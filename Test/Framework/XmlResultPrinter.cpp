#include "XmlResultPrinter.hpp"

#include "../../External/RapidXml/rapidxml.hpp"
#include "../../External/RapidXml/rapidxml_print.hpp"

#include <iostream>
#include <sstream>
#include <stack>

using namespace Fnd::Test;

struct XmlResultPrinter::XmlImpl
{
	rapidxml::xml_document<> document;
	
	std::stack<rapidxml::xml_node<>*> node_stack;
	
	rapidxml::xml_node<>* CurrentNode()
	{
		return node_stack.empty() ? nullptr : node_stack.top();
	}
};

XmlResultPrinter::XmlResultPrinter():
	_xml_impl(std::make_shared<XmlImpl>())
{
	auto root = _xml_impl->document.allocate_node(rapidxml::node_element,"TestResults");
	_xml_impl->document.append_node(root);
	_xml_impl->node_stack.push(root);
}

void XmlResultPrinter::PrintBeginTestSuiteResult(const std::string& description)
{
	auto node = _xml_impl->document.allocate_node(rapidxml::node_element, "TestSuiteResult");
	node->append_attribute(_xml_impl->document.allocate_attribute("description",_xml_impl->document.allocate_string(description.c_str())));
	_xml_impl->CurrentNode()->append_node(node);
	_xml_impl->node_stack.push(node);
}

void XmlResultPrinter::PrintBeginTestClassResult(const TestType test_type, const std::string& description)
{
	auto node = _xml_impl->document.allocate_node(rapidxml::node_element, "TestClassResult");
	node->append_attribute(_xml_impl->document.allocate_attribute("type",_xml_impl->document.allocate_string(GetTestTypeString(test_type).c_str())));
	node->append_attribute(_xml_impl->document.allocate_attribute("description",_xml_impl->document.allocate_string(description.c_str())));
	_xml_impl->CurrentNode()->append_node(node);
	_xml_impl->node_stack.push(node);
}

void XmlResultPrinter::PrintBeginTestCaseResult(const std::string& description)
{
	auto node = _xml_impl->document.allocate_node(rapidxml::node_element, "TestCaseResult");
	node->append_attribute(_xml_impl->document.allocate_attribute("description",_xml_impl->document.allocate_string(description.c_str())));
	_xml_impl->CurrentNode()->append_node(node);
	_xml_impl->node_stack.push(node);
}

void XmlResultPrinter::PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result)
{
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("succeeded",test_suite_result.GetSucceeded() ? "true" : "false"));
	
	std::stringstream numsucceeded_ss;
	numsucceeded_ss << test_suite_result.GetNumTestClassesSucceeded();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_tests_succeeded",_xml_impl->document.allocate_string(numsucceeded_ss.str().c_str())));

	std::stringstream num_ss;
	num_ss << test_suite_result.GetNumTestClasses();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_tests",_xml_impl->document.allocate_string(num_ss.str().c_str())));
	
	_xml_impl->node_stack.pop();
}

void XmlResultPrinter::PrintEndTestClassResult(const TestClassResult& test_class_result)
{
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("succeeded",test_class_result.GetSucceeded() ? "true" : "false"));
	
	std::stringstream numsucceeded_ss;
	numsucceeded_ss << test_class_result.GetNumTestCasesSucceeded();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_cases_succeeded",_xml_impl->document.allocate_string(numsucceeded_ss.str().c_str())));
	
	std::stringstream num_ss;
	num_ss << test_class_result.GetNumTestCases();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_cases",_xml_impl->document.allocate_string(num_ss.str().c_str())));
	
	_xml_impl->node_stack.pop();
}

void XmlResultPrinter::PrintEndTestCaseResult(const TestCaseResult& test_case_result)
{
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("succeeded",test_case_result.GetSucceeded() ? "true" : "false"));
	
	std::stringstream numsucceeded_ss;
	numsucceeded_ss << test_case_result.GetNumAssertsSucceeded();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_asserts_succeeded",_xml_impl->document.allocate_string(numsucceeded_ss.str().c_str())));
	
	std::stringstream num_ss;
	num_ss << test_case_result.GetNumAsserts();
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_asserts",_xml_impl->document.allocate_string(num_ss.str().c_str())));
	
	for (auto assert_result : test_case_result.GetAssertResults())
	{
		if (!assert_result.GetSucceeded()) // Do we want to print all asserts results or just failures?
		{
			auto node = _xml_impl->document.allocate_node(rapidxml::node_element, "AssertResult");
			node->append_attribute(_xml_impl->document.allocate_attribute("succeeded",assert_result.GetSucceeded() ? "true" : "false"));
			node->append_attribute(_xml_impl->document.allocate_attribute("description",_xml_impl->document.allocate_string(assert_result.GetDescription().c_str())));
			_xml_impl->CurrentNode()->append_node(node);
			_xml_impl->node_stack.push(node);
			
			// Create any other child nodes here
			
			_xml_impl->node_stack.pop();
		}
	}
	
	_xml_impl->node_stack.pop();
}

XmlResultPrinter::~XmlResultPrinter()
{
	std::string s;
	print(back_inserter(s), _xml_impl->document, 0);
	
	std::cout << s << '\n';
	
	// TODO: Output to file instead of cout
}
