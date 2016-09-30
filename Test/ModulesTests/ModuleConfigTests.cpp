#include "ModuleConfigTests.hpp"

#include "MockConfigProvider.hpp"
#include "MockModuleConfig.hpp"

using namespace Fnd::Test::Modules;


ModuleConfigTests::ModuleConfigTests():
	UnitTestClass("ModuleConfigTests")
{
	AddTestCase("LoadDefault_Success", &ModuleConfigTests::LoadDefault_Success, this);
	AddTestCase("Load_Success", &ModuleConfigTests::Load_Success, this);
	AddTestCase("Save_Success", &ModuleConfigTests::Save_Success, this);
}

void ModuleConfigTests::LoadDefault_Success(Fnd::Test::TestCase& test_case)
{
	MockModuleConfig config;
	config.SetDefault("default");
	
	config.LoadDefault();
	
	test_case.AssertEqual("default", config.GetConfig().str);
}

void ModuleConfigTests::Load_Success(Fnd::Test::TestCase& test_case)
{
	auto config_provider = std::make_shared<MockConfigProvider>();
	config_provider->SetValue("loaded");
	
	MockModuleConfig config;
	
	config.Load(config_provider);
	
	test_case.AssertEqual("loaded", config.GetConfig().str);
}

void ModuleConfigTests::Save_Success(Fnd::Test::TestCase& test_case)
{
	auto config_provider = std::make_shared<MockConfigProvider>();
	
	MockModuleConfig config;
	
	config.GetConfig().str = "saved";
	
	config.Save(config_provider);
	
	test_case.AssertEqual("saved", config_provider->GetValue());
}
