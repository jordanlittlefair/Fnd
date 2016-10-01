#include "IntegrationTestClass.hpp"

using namespace Fnd::Test;

IntegrationTestClass::IntegrationTestClass(const std::string& description):
	TestClass(TestType::Integration, description)
{
}

std::string IntegrationTestClass::GetTestClassDirectory() const
{
	return
	TestClass::GetWorkingDirectory() +
	_directory_helper.ValidateString(GetDescription()) + "/";
}

std::string IntegrationTestClass::GetTestCaseDirectory() const
{
	return
	TestClass::GetWorkingDirectory() +
	_directory_helper.ValidateString(GetDescription()) + "/" +
	_directory_helper.ValidateString(_current_test) + "/";
}

void IntegrationTestClass::SetupClass()
{
	_directory_helper.CreateDirectory(GetTestClassDirectory(), true);
}

void IntegrationTestClass::CleanupClass()
{
	_directory_helper.DeleteDirectory(GetTestClassDirectory(), true);
}

void IntegrationTestClass::SetupTest(const std::string& test_description)
{
	_current_test = test_description;
	
	_directory_helper.CreateDirectory(GetTestCaseDirectory(), true);
}

void IntegrationTestClass::CleanupTest(const std::string& test_description)
{
	_directory_helper.DeleteDirectory(GetTestCaseDirectory(), true);
	
	_current_test.clear();
}
