#include "IntegrationTestClass.hpp"

#include "DirectoryHelper.hpp"

using namespace Fnd::Test;

IntegrationTestClass::IntegrationTestClass(const std::string& description):
	TestClass(TestType::Integration, description)
{
}

std::string IntegrationTestClass::GetTestClassDirectory() const
{
	return
	TestClass::GetWorkingDirectory() +
	DirectoryHelper::ValidateString(GetDescription()) + "/";
}

std::string IntegrationTestClass::GetTestCaseDirectory() const
{
	return
	TestClass::GetWorkingDirectory() +
	DirectoryHelper::ValidateString(GetDescription()) + "/" +
	DirectoryHelper::ValidateString(_current_test) + "/";
}

void IntegrationTestClass::SetupClass()
{
	DirectoryHelper::CreateDirectory(GetTestClassDirectory(), true);
}

void IntegrationTestClass::CleanupClass()
{
	DirectoryHelper::DeleteDirectory(GetTestClassDirectory(), true);
}

void IntegrationTestClass::SetupTest(const std::string& test_description)
{
	_current_test = test_description;
	
	DirectoryHelper::CreateDirectory(GetTestCaseDirectory(), true);
}

void IntegrationTestClass::CleanupTest(const std::string& test_description)
{
	DirectoryHelper::DeleteDirectory(GetTestCaseDirectory(), true);
	
	_current_test.clear();
}
