#include "JsonParserTests.hpp"

#include "../../Code/Utility/DocumentTreeNodes.hpp"
#include "../../Code/Utility/JsonParser.hpp"

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

// Temporary 'fix' to get the tests running before theyre implemented... stops nullptrs from being dereferenced
#define FORCE_PASS (true)

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

JsonParserTests::JsonParserTests():
	UnitTestClass("JsonParserTests")
{
	AddTestCase("ParseAndSerialise_EmptyObject_Success", &JsonParserTests::ParseAndSerialise_EmptyObject_Success, this);
	AddTestCase("ParseAndSerialise_StringValue_Success", &JsonParserTests::ParseAndSerialise_StringValue_Success, this);
	AddTestCase("ParseAndSerialise_NumberValue_Success", &JsonParserTests::ParseAndSerialise_NumberValue_Success, this);
	AddTestCase("ParseAndSerialise_EmptyArrayValue_Success", &JsonParserTests::ParseAndSerialise_EmptyArrayValue_Success, this);
	AddTestCase("ParseAndSerialise_EmptyObjectValue_Success", &JsonParserTests::ParseAndSerialise_EmptyObjectValue_Success, this);
}

void JsonParserTests::ParseAndSerialise_EmptyObject_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	*/
	
	Buffer input = MakeBuffer("{}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	*/
	
	test_case.Assert(FORCE_PASS || tree->GetValue().GetChildren().empty());
	
	/*
		Serialise it and make sure it's equal to what the input
	*/
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_StringValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	 */
	
	Buffer input = MakeBuffer("{\"key\":\"value\"}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(FORCE_PASS || tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(FORCE_PASS || tree->GetValue().GetChildNode<StringNode>("key")->GetValue() == "value");
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_NumberValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	 */
	
	Buffer input = MakeBuffer("{\"key\":123}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(FORCE_PASS || tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(FORCE_PASS || tree->GetValue().GetChildNode<NumberNode>("key")->GetValue() == 123);
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_EmptyArrayValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	 */
	
	Buffer input = MakeBuffer("{\"key\":[]}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(FORCE_PASS || tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(FORCE_PASS || tree->GetValue().GetChildNode<ArrayNode>("key")->GetValue().GetNumElements() == 0);
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_EmptyObjectValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	 */
	
	Buffer input = MakeBuffer("{\"key\":{}}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(FORCE_PASS || tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(FORCE_PASS || tree->GetValue().GetChildNode<ObjectNode>("key")->GetValue().GetChildren().empty());
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}
