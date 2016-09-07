#include "DocumentTreeTests.hpp"

#include "../../Code/Utility/DocumentTreeNodes.hpp"

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility::DocumentTree;


DocumentTreeTests::DocumentTreeTests():
	UnitTestClass("DocumentTreeTests")
{
	AddTestCase("CreateStringNode_Success", &DocumentTreeTests::CreateStringNode_Success, this);
	AddTestCase("CreateNumberNode_Success", &DocumentTreeTests::CreateNumberNode_Success, this);
	AddTestCase("CreateObjectNode_Success", &DocumentTreeTests::CreateObjectNode_Success, this);
	AddTestCase("CreateArrayNode_Success", &DocumentTreeTests::CreateArrayNode_Success, this);
	AddTestCase("AddStringNodeToObject_Success", &DocumentTreeTests::AddStringNodeToObject_Success, this);
	AddTestCase("AddNumberNodeToObject_Success", &DocumentTreeTests::AddNumberNodeToObject_Success, this);
	AddTestCase("AddObjectNodeToObject_Success", &DocumentTreeTests::AddObjectNodeToObject_Success, this);
	AddTestCase("AddArrayNodeToObject_Success", &DocumentTreeTests::AddArrayNodeToObject_Success, this);
	AddTestCase("AddMultipleNodesToObject_Success", &DocumentTreeTests::AddMultipleNodesToObject_Success, this);
	AddTestCase("AddStringNodeToArray_Success", &DocumentTreeTests::AddStringNodeToArray_Success, this);
	AddTestCase("AddNumberNodeToArray_Success", &DocumentTreeTests::AddNumberNodeToArray_Success, this);
	AddTestCase("AddObjectNodeToArray_Success", &DocumentTreeTests::AddObjectNodeToArray_Success, this);
	AddTestCase("AddArrayNodeToArray_Success", &DocumentTreeTests::AddArrayNodeToArray_Success, this);
	AddTestCase("AddMultipleNodesToArray_Success", &DocumentTreeTests::AddMultipleNodesToArray_Success, this);
}

void DocumentTreeTests::CreateStringNode_Success(Fnd::Test::TestCase& test_case)
{
	StringNodePtr stringNode = std::make_shared<StringNode>("key", "value");
	
	test_case.AssertEqual((int)INode::Type::String, (int)stringNode->GetType());
	
	test_case.AssertEqual("key", stringNode->GetName());
	test_case.AssertEqual("value", stringNode->GetValue());
	
	stringNode->GetValue() = "updated";
	
	test_case.AssertEqual("key", stringNode->GetName());
	test_case.AssertEqual("updated", stringNode->GetValue());
}

void DocumentTreeTests::CreateNumberNode_Success(Fnd::Test::TestCase& test_case)
{
	NumberNodePtr numberNode = std::make_shared<NumberNode>("key", 123.456);
	
	test_case.AssertEqual((int)INode::Type::Number, (int)numberNode->GetType());
	
	test_case.AssertEqual("key", numberNode->GetName());
	test_case.AssertEqual(123.456, numberNode->GetValue());
	
	numberNode->GetValue() = 654.321;
	
	test_case.AssertEqual("key", numberNode->GetName());
	test_case.AssertEqual(654.321, numberNode->GetValue());
}

void DocumentTreeTests::CreateObjectNode_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	test_case.AssertEqual((int)INode::Type::Object, (int)objectNode->GetType());
	
	test_case.AssertEqual("key", objectNode->GetName());
	test_case.Assert(objectNode->GetValue().GetChildren().empty());
}

void DocumentTreeTests::CreateArrayNode_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	test_case.AssertEqual((int)INode::Type::Array, (int)arrayNode->GetType());
	
	test_case.AssertEqual("key", arrayNode->GetName());
	test_case.Assert(arrayNode->GetValue().GetElements().empty());
}


void DocumentTreeTests::AddStringNodeToObject_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	objectNode->GetValue().AddChild(std::make_shared<StringNode>("child", "value"));
	
	test_case.Assert(objectNode->GetValue().HasChild("child"));
	test_case.AssertEqual("value", objectNode->GetValue().GetChildValue<StringNode>("child"));
	
	objectNode->GetValue().GetChildValue<StringNode>("child") = "updated";
	
	test_case.AssertEqual("updated", objectNode->GetValue().GetChildValue<StringNode>("child"));

	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<NumberNode>("child");
	});
}

void DocumentTreeTests::AddNumberNodeToObject_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	objectNode->GetValue().AddChild(std::make_shared<NumberNode>("child", 123.456));
	
	test_case.Assert(objectNode->GetValue().HasChild("child"));
	test_case.AssertEqual(123.456, objectNode->GetValue().GetChildValue<NumberNode>("child"));
	
	objectNode->GetValue().GetChildValue<NumberNode>("child") = 654.321;
	
	test_case.AssertEqual(654.321, objectNode->GetValue().GetChildValue<NumberNode>("child"));
	
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<ObjectNode>("child");
	});
}

void DocumentTreeTests::AddObjectNodeToObject_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	objectNode->GetValue().AddChild(std::make_shared<ObjectNode>("child"));
	
	test_case.Assert(objectNode->GetValue().HasChild("child"));
	test_case.Assert(objectNode->GetValue().GetChildValue<ObjectNode>("child").GetChildren().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<ArrayNode>("child");
	});
}

void DocumentTreeTests::AddArrayNodeToObject_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	objectNode->GetValue().AddChild(std::make_shared<ArrayNode>("child"));
	
	test_case.Assert(objectNode->GetValue().HasChild("child"));
	test_case.Assert(objectNode->GetValue().GetChildValue<ArrayNode>("child").GetElements().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<StringNode>("child");
	});
}

void DocumentTreeTests::AddMultipleNodesToObject_Success(Fnd::Test::TestCase& test_case)
{
	ObjectNodePtr objectNode = std::make_shared<ObjectNode>("key");
	
	objectNode->GetValue().AddChild(std::make_shared<StringNode>("string", "value"));
	objectNode->GetValue().AddChild(std::make_shared<NumberNode>("float", 123.456));
	objectNode->GetValue().AddChild(std::make_shared<ObjectNode>("object"));
	objectNode->GetValue().AddChild(std::make_shared<ArrayNode>("array"));
	
	test_case.Assert(objectNode->GetValue().HasChild("string"));
	test_case.AssertEqual("value", objectNode->GetValue().GetChildValue<StringNode>("string"));
	test_case.Assert(objectNode->GetValue().HasChild("float"));
	test_case.AssertEqual(123.456, objectNode->GetValue().GetChildValue<NumberNode>("float"));
	test_case.Assert(objectNode->GetValue().HasChild("object"));
	test_case.Assert(objectNode->GetValue().GetChildValue<ObjectNode>("object").GetChildren().empty());
	test_case.Assert(objectNode->GetValue().HasChild("array"));
	test_case.Assert(objectNode->GetValue().GetChildValue<ArrayNode>("array").GetElements().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<NumberNode>("string");
	});
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<ObjectNode>("float");
	});
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<ArrayNode>("object");
	});
	test_case.AssertException<std::exception>([&]()
	{
		objectNode->GetValue().GetChildValue<StringNode>("array");
	});
}


void DocumentTreeTests::AddStringNodeToArray_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	arrayNode->GetValue().AddElement(std::make_shared<StringNode>("child", "value"));
	
	test_case.AssertEqual(1, arrayNode->GetValue().GetNumElements());
	test_case.AssertEqual("value", arrayNode->GetValue().GetElementValue<StringNode>(0));
	
	arrayNode->GetValue().GetElementValue<StringNode>(0) = "updated";
	
	test_case.AssertEqual("updated", arrayNode->GetValue().GetElementValue<StringNode>(0));
	
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<NumberNode>(0);
	});
}

void DocumentTreeTests::AddNumberNodeToArray_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	arrayNode->GetValue().AddElement(std::make_shared<NumberNode>("child", 123.456));
	
	test_case.AssertEqual(1, arrayNode->GetValue().GetNumElements());
	test_case.AssertEqual(123.456, arrayNode->GetValue().GetElementValue<NumberNode>(0));
	
	arrayNode->GetValue().GetElementValue<NumberNode>(0) = 654.321;
	
	test_case.AssertEqual(654.321, arrayNode->GetValue().GetElementValue<NumberNode>(0));
	
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<ObjectNode>(0);
	});
}

void DocumentTreeTests::AddObjectNodeToArray_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	arrayNode->GetValue().AddElement(std::make_shared<ObjectNode>("child"));
	
	test_case.AssertEqual(1, arrayNode->GetValue().GetNumElements());
	test_case.Assert(arrayNode->GetValue().GetElementValue<ObjectNode>(0).GetChildren().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<ArrayNode>(0);
	});
}

void DocumentTreeTests::AddArrayNodeToArray_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	arrayNode->GetValue().AddElement(std::make_shared<ArrayNode>("child"));
	
	test_case.AssertEqual(1, arrayNode->GetValue().GetNumElements());
	
	test_case.Assert(arrayNode->GetValue().GetElementValue<ArrayNode>(0).GetElements().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<StringNode>(0);
	});
}

void DocumentTreeTests::AddMultipleNodesToArray_Success(Fnd::Test::TestCase& test_case)
{
	ArrayNodePtr arrayNode = std::make_shared<ArrayNode>("key");
	
	arrayNode->GetValue().AddElement(std::make_shared<StringNode>("string", "value"));
	arrayNode->GetValue().AddElement(std::make_shared<NumberNode>("float", 123.456));
	arrayNode->GetValue().AddElement(std::make_shared<ObjectNode>("object"));
	arrayNode->GetValue().AddElement(std::make_shared<ArrayNode>("array"));
	
	test_case.AssertEqual((int)INode::Type::String, (int)arrayNode->GetValue().GetElementType(0));
	test_case.AssertEqual("value", arrayNode->GetValue().GetElementValue<StringNode>(0));
	test_case.AssertEqual((int)INode::Type::Number, (int)arrayNode->GetValue().GetElementType(1));
	test_case.AssertEqual(123.456, arrayNode->GetValue().GetElementValue<NumberNode>(1));
	test_case.AssertEqual((int)INode::Type::Object, (int)arrayNode->GetValue().GetElementType(2));
	test_case.Assert(arrayNode->GetValue().GetElementValue<ObjectNode>(2).GetChildren().empty());
	test_case.AssertEqual((int)INode::Type::Array, (int)arrayNode->GetValue().GetElementType(3));
	test_case.Assert(arrayNode->GetValue().GetElementValue<ArrayNode>(3).GetElements().empty());
	
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<NumberNode>(0);
	});
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<ObjectNode>(1);
	});
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<ArrayNode>(2);
	});
	test_case.AssertException<std::exception>([&]()
	{
		arrayNode->GetValue().GetElementValue<StringNode>(3);
	});
}
