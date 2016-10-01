#include "TestSuite.hpp"

#include "DirectoryHelper.hpp"

#include <algorithm>

using namespace Fnd::Test;

TestSuite::TestSuite( const std::string& description ):
	_result(description)
{
}

void TestSuite::AddTestClass( TestClassPtr test_class )
{
	_test_classes.push_back( test_class );
}

void TestSuite::SetWorkingDirectory(const std::string& working_directory)
{
	DirectoryHelper directory_helper;
	
	const std::string validated_directory = directory_helper.ValidateString(directory_helper.RemoveTrailingSlash(working_directory)) + '/';

	directory_helper.CreateDirectory(validated_directory, true);
	
	_working_directory = validated_directory;
}

void TestSuite::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

void TestSuite::Run()
{
	SortTestClasses();
	
	if (_result_printer)
	{
		_result_printer->PrintBeginTestSuiteResult(GetResult().GetDescription());
	}
	
	_result.StartTimer();

	for ( auto test_class : _test_classes )
	{
		test_class->SetWorkingDirectory(_working_directory);
		
		test_class->SetResultPrinter(_result_printer);

		test_class->Run();
		
		_result.AddTestClassResult( test_class->GetResult() );
	}
	
	_result.EndTimer();

	if (_result_printer)
	{
		_result_printer->PrintEndTestSuiteResult(GetResult());
	}
}

void TestSuite::Run(const TestType type)
{
	SortTestClasses();
	
	if (_result_printer)
	{
		_result_printer->PrintBeginTestSuiteResult(GetResult().GetDescription());
	}
	
	for (auto test_class : _test_classes)
	{
		if (test_class->GetTestType() == type)
		{
			test_class->SetResultPrinter(_result_printer);
			
			test_class->Run();
			
			_result.AddTestClassResult(test_class->GetResult());
		}
	}
	
	if (_result_printer)
	{
		_result_printer->PrintEndTestSuiteResult(GetResult());
	}
}

const TestSuiteResult& TestSuite::GetResult() const
{
	return _result;
}

void TestSuite::SortTestClasses()
{
	std::sort(_test_classes.begin(), _test_classes.end(),
		[&](const TestClassPtr& lhs, const TestClassPtr& rhs)
		{
			return
				((std::underlying_type<TestType>::type)lhs->GetTestType()) <
				((std::underlying_type<TestType>::type)rhs->GetTestType());
		});
}

TestSuite::~TestSuite()
{
}
