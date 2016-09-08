#include "JsonParserTests.hpp"

#include "../../Code/Utility/DocumentTreeNodes.hpp"
#include "../../Code/Utility/JsonParser.hpp"

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;


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
	AddTestCase("ParseAndSerialise_BoolValue_Success", &JsonParserTests::ParseAndSerialise_BoolValue_Success, this);
	AddTestCase("ParseAndSerialise_NullValue_Success", &JsonParserTests::ParseAndSerialise_NullValue_Success, this);
	
	AddTestCase("ParseAndSerialise_ObjectWithEachType", &JsonParserTests::ParseAndSerialise_ObjectWithEachType, this);
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
	
	test_case.Assert(tree->GetValue().GetChildren().empty());
	
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
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(tree->GetValue().GetChildNode<StringNode>("key")->GetValue() == "value");
	
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
	
	Buffer input = MakeBuffer("{\"key\":123.456}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(tree->GetValue().GetChildNode<NumberNode>("key")->GetValue() == 123.456);
	
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
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(tree->GetValue().GetChildNode<ArrayNode>("key")->GetValue().GetNumElements() == 0);
	
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
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	test_case.Assert(tree->GetValue().GetChildNode<ObjectNode>("key")->GetValue().GetChildren().empty());
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_BoolValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	*/
	
	Buffer input = MakeBuffer("{\"key\":true}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	*/
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	test_case.AssertEqual(tree->GetValue().GetChildNode<BoolNode>("key")->GetValue(), true);
	
	/*
		Serialise it and make sure it's equal to what the input
	*/
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_NullValue_Success(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	*/
	
	Buffer input = MakeBuffer("{\"key\":null}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	*/
	
	test_case.AssertEqual(tree->GetValue().GetChildren().size(), 1);
	
	tree->GetValue().GetChildNode<NullNode>("key")->GetValue(); // Doesn't return anything - mustn't throw
	
	/*
		Serialise it and make sure it's equal to what the input
	*/
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

void JsonParserTests::ParseAndSerialise_ObjectWithEachType(Fnd::Test::TestCase& test_case)
{
	/*
		Create buffer and parse it to document tree
	 */
	
	Buffer input = MakeBuffer("{\"object\":{\"number\":999.999,\"string\":\"a string\",\"bool\":false,\"null\":null,\"array\":[1.2,3.4,5.6],\"sub-object\":{\"sub-string\":\"a sub string\"}}}");
	
	DocumentTree::ObjectNodePtr tree = JsonParser().Parse(input);
	
	/*
		Check tree contains items
	 */
	
	test_case.AssertEqual(1, tree->GetValue().GetChildren().size());
	test_case.AssertEqual((int)INode::Type::Object, (int)tree->GetValue().GetChildren()[0]->GetType());
	
	auto object = tree->GetValue().GetChildNode<ObjectNode>("object");
	test_case.AssertEqual(6, object->GetValue().GetChildren().size());
	test_case.AssertEqual(999.999, object->GetValue().GetChildNode<NumberNode>("number")->GetValue());
	test_case.AssertEqual("a string", object->GetValue().GetChildNode<StringNode>("string")->GetValue());
	test_case.AssertEqual(false, object->GetValue().GetChildNode<BoolNode>("bool")->GetValue());
	object->GetValue().GetChildNode<NullNode>("null")->GetValue(); // Doesn't return anything - mustn't throw
	test_case.Assert(object->GetValue().HasChild("array"));
	test_case.AssertEqual((int)INode::Type::Array, (int)object->GetValue().GetChildType("array"));
	test_case.Assert(object->GetValue().HasChild("sub-object"));
	test_case.AssertEqual((int)INode::Type::Object, (int)object->GetValue().GetChildType("sub-object"));
	
	auto array = object->GetValue().GetChildNode<ArrayNode>("array");
	test_case.AssertEqual(3, array->GetValue().GetNumElements());
	test_case.AssertEqual(1.2, array->GetValue().GetElementNode<NumberNode>(0)->GetValue());
	test_case.AssertEqual(3.4, array->GetValue().GetElementNode<NumberNode>(1)->GetValue());
	test_case.AssertEqual(5.6, array->GetValue().GetElementNode<NumberNode>(2)->GetValue());
	
	auto sub = object->GetValue().GetChildNode<ObjectNode>("sub-object");
	test_case.AssertEqual("a sub string", sub->GetValue().GetChildNode<StringNode>("sub-string")->GetValue());
	
	
	/*
		Serialise it and make sure it's equal to what the input
	 */
	
	Buffer output = JsonParser().Serialise(tree);
	
	test_case.AssertEqual(MakeString(input), MakeString(output));
}

