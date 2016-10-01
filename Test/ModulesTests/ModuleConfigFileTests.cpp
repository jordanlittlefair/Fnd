#include "ModuleConfigFileTests.hpp"

#include "MockFile.hpp"
#include "MockParser.hpp"
#include "../../Code/Modules/ModuleConfigFile.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;
using namespace Fnd::Utility::File;

namespace
{
	Buffer MakeBuffer(const std::string& str)
	{
		return Buffer(str.begin(), str.end());
	}
	std::string MakeString(const Buffer& buffer)
	{
		return std::string(buffer.begin(), buffer.end());
	}
}

ModuleConfigFileTests::ModuleConfigFileTests():
	UnitTestClass("ModuleConfigFileTests")
{
	AddTestCase("LoadConfigDocumentTree_Success", &ModuleConfigFileTests::LoadConfigDocumentTree_Success, this);
	AddTestCase("SaveConfigDocumentTree_Success", &ModuleConfigFileTests::SaveConfigDocumentTree_Success, this);
}

void ModuleConfigFileTests::LoadConfigDocumentTree_Success(Fnd::Test::TestCase& test_case)
{
	std::string file_content_str = "Here is some content";
	
	ParserPtr parser = std::make_shared<MockParser>();
	FilePtr file = std::make_shared<MockFile>("filename",MakeBuffer(file_content_str)); // Mock file with some content set
	
	ModuleConfigFile config_file(parser, file);
	
	ObjectNodePtr loaded =  config_file.LoadConfigDocumentTree(); // Load the config through a mock parser
	
	test_case.AssertEqual(file_content_str, loaded->GetValue().GetChildValue<StringNode>("node")); // Make sure the loaded and parsed content matches the file content
}

void ModuleConfigFileTests::SaveConfigDocumentTree_Success(Fnd::Test::TestCase& test_case)
{
	std::string config_str = "Here is some content";
	
	ParserPtr parser = std::make_shared<MockParser>();
	FilePtr file = std::make_shared<MockFile>("filename"); // Empty mock file
	
	ModuleConfigFile config_file(parser, file);
	
	// Create a config document tree containing the expected content
	ObjectNodePtr config_tree = std::make_shared<ObjectNode>("");
	config_tree->GetValue().AddChild(std::make_shared<StringNode>("node",config_str));
	
	config_file.SaveConfigDocumentTree(config_tree); // Save the config through a mock parser
	
	test_case.AssertEqual(config_str, MakeString(file->GetFileBuffer())); // Make sure the parsed and saved content matches the config_str
}
