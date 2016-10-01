#include "TemplatedModuleConfigTests.hpp"

#include "MockConfigProvider.hpp"
#include "MockTemplatedModuleConfig.hpp"

using namespace Fnd::Test::Modules;


TemplatedModuleConfigTests::TemplatedModuleConfigTests():
UnitTestClass("TemplatedModuleConfigTests")
{
	AddTestCase("LoadDefault_Success", &TemplatedModuleConfigTests::LoadDefault_Success, this);
	AddTestCase("Load_Success", &TemplatedModuleConfigTests::Load_Success, this);
	AddTestCase("Save_Success", &TemplatedModuleConfigTests::Save_Success, this);
}

void TemplatedModuleConfigTests::LoadDefault_Success(Fnd::Test::TestCase& test_case)
{
	MockTemplatedModuleConfig config;
	config.SetDefault("default");
	
	config.LoadDefault();
	
	test_case.AssertEqual("default", config.GetConfigData().a_string);
}

void TemplatedModuleConfigTests::Load_Success(Fnd::Test::TestCase& test_case)
{
	auto config_provider = std::make_shared<MockConfigProvider>();
	config_provider->SetValue("loaded");
	
	MockTemplatedModuleConfig config;
	
	config.Load(config_provider);
	
	test_case.AssertEqual("loaded", config.GetConfigData().a_string);
}

void TemplatedModuleConfigTests::Save_Success(Fnd::Test::TestCase& test_case)
{
	auto config_provider = std::make_shared<MockConfigProvider>();
	
	MockTemplatedModuleConfig config;
	
	config.GetConfigData().a_string = "saved";
	
	config.Save(config_provider);
	
	test_case.AssertEqual("saved", config_provider->GetValue());
}
