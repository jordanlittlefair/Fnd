#pragma once

#include "TestCase.hpp"
#include "TestClassResult.hpp"
#include "TestType.hpp"

#include <memory>
#include <vector>

namespace Fnd
{
	
namespace Test
{

class TestClass
{
public:
	
	void SetWorkingDirectory(const std::string& working_directory);
	
	void SetResultPrinter(ResultPrinterPtr result_printer);
	
	TestType GetTestType() const;
	
	std::string GetDescription() const;

	void Run();
	
	const TestClassResult& GetResult() const;

	virtual ~TestClass();
	
protected:

	TestClass(const TestType type, const std::string& desciption);

	template <typename FunctionType,typename DerivedType>
	void AddTestCase( const std::string& name, FunctionType function, DerivedType* ptr )
	{
		AddTestCase( std::make_shared<TestCase>( name, std::bind( function, ptr, std::placeholders::_1 ) ) );
	}
	
	std::string GetWorkingDirectory() const;
	
	virtual void SetupClass();
	
	virtual void CleanupClass();

	virtual void SetupTest(const std::string& test_description);

	virtual void CleanupTest(const std::string& test_description);
	
private:
	
	void AddTestCase( TestCasePtr test_case );
	
private:
	
	const TestType _type;
	
	const std::string _description;
	
	std::vector<TestCasePtr> _test_cases;
	
	std::string _working_directory;

	ResultPrinterPtr _result_printer;
	
	TestClassResult _result;
};

typedef std::shared_ptr<TestClass> TestClassPtr;

}

}
