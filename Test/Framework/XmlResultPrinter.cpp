#include "XmlResultPrinter.hpp"

#include "../../External/RapidXml/rapidxml.hpp"
#include "../../External/RapidXml/rapidxml_print.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

using namespace Fnd::Test;

namespace
{
	template <typename T>
	std::string ToString(const T& t)
	{
		std::stringstream ss;
		ss << t;
		return ss.str();
	}
}

struct XmlResultPrinter::XmlImpl
{
	rapidxml::xml_document<> document;
	
	std::stack<rapidxml::xml_node<>*> node_stack;
	
	rapidxml::xml_node<>* CurrentNode()
	{
		return node_stack.empty() ? nullptr : node_stack.top();
	}
};

XmlResultPrinter::XmlResultPrinter(const std::string& output_filename):
	_xml_impl(std::make_shared<XmlImpl>()),
	_output_filename(output_filename + ".xml")
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
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("time_taken",_xml_impl->document.allocate_string(ToString(Timer::ToSeconds<double>(test_suite_result.GetTimeElapsed())).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_classes_succeeded",_xml_impl->document.allocate_string(ToString(test_suite_result.GetNumTestClassesSucceeded()).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_classes",_xml_impl->document.allocate_string(ToString(test_suite_result.GetNumTestClasses()).c_str())));
	
	_xml_impl->node_stack.pop();
}

void XmlResultPrinter::PrintEndTestClassResult(const TestClassResult& test_class_result)
{
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("succeeded",test_class_result.GetSucceeded() ? "true" : "false"));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("time_taken",_xml_impl->document.allocate_string(ToString(Timer::ToSeconds<double>(test_class_result.GetTimeElapsed())).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_cases_succeeded",_xml_impl->document.allocate_string(ToString(test_class_result.GetNumTestCasesSucceeded()).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_test_cases",_xml_impl->document.allocate_string(ToString(test_class_result.GetNumTestCases()).c_str())));
	
	_xml_impl->node_stack.pop();
}

void XmlResultPrinter::PrintEndTestCaseResult(const TestCaseResult& test_case_result)
{
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("succeeded",test_case_result.GetSucceeded() ? "true" : "false"));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("time_taken",_xml_impl->document.allocate_string(ToString(Timer::ToSeconds<double>(test_case_result.GetTimeElapsed())).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_asserts_succeeded",_xml_impl->document.allocate_string(ToString(test_case_result.GetNumAssertsSucceeded()).c_str())));
	
	_xml_impl->CurrentNode()->append_attribute(_xml_impl->document.allocate_attribute("num_asserts",_xml_impl->document.allocate_string(ToString(test_case_result.GetNumAsserts()).c_str())));
	
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
	std::ofstream output(_output_filename);
	
	if (output.is_open())
	{
		output << _xml_impl->document;
		
		std::cout << "Test results written to [" << _output_filename << "]\n";
	}
	else
	{
		std::cout << "Failed to write results to [" << _output_filename << "]\n";
	}
}
