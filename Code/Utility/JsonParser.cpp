#include "JsonParser.hpp"

#include "../../External/RapidJSON/document.h"
#include "../../External/RapidJSON/rapidjson.h"
#include "../../External/RapidJSON/stringbuffer.h"
#include "../../External/RapidJSON/writer.h"

using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;


namespace
{
	/*
		Parsing methods
	*/

	StringNodePtr ParseString(const rapidjson::Value& object_in, const std::string& name);
	NumberNodePtr ParseNumber(const rapidjson::Value& object_in, const std::string& name);
	ObjectNodePtr ParseObject(const rapidjson::Value& object_in, const std::string& name);
	ArrayNodePtr ParseArray(const rapidjson::Value& object_in, const std::string& name);
	NodePtr ParseNode(const rapidjson::Value& object_in, const std::string& name);

	StringNodePtr ParseString(const rapidjson::Value& object_in, const std::string& name)
	{
		return std::make_shared<StringNode>(name, object_in.GetString());
	}

	NumberNodePtr ParseNumber(const rapidjson::Value& object_in, const std::string& name)
	{
		return std::make_shared<NumberNode>(name, object_in.GetDouble());
	}

	ObjectNodePtr ParseObject(const rapidjson::Value& object_in, const std::string& name)
	{
		ObjectNodePtr ret = std::make_shared<ObjectNode>(name);

		for (const auto& child : object_in.GetObject())
		{
			ret->GetValue().AddChild(ParseNode(child.value,child.name.GetString()));
		}

		return ret;
	}

	ArrayNodePtr ParseArray(const rapidjson::Value& object_in, const std::string& name)
	{
		ArrayNodePtr ret = std::make_shared<ArrayNode>(name);

		for (const auto& child : object_in.GetArray())
		{
			ret->GetValue().AddElement(ParseNode(child,""));
		}

		return ret;
	}

	NodePtr ParseNode(const rapidjson::Value& object_in, const std::string& name)
	{
		switch (object_in.GetType())
		{
		case rapidjson::kStringType:
			return ParseString(object_in, name);
			break;
		case rapidjson::kNumberType:
			return ParseNumber(object_in, name);
			break;
		case rapidjson::kObjectType:
			return ParseObject(object_in, name);
			break;
		case rapidjson::kArrayType: 
			return ParseArray(object_in, name);
			break;
		case rapidjson::kNullType:
		case rapidjson::kFalseType:
		case rapidjson::kTrueType:
		default:
			assert(!"Unknown type!");
			return nullptr;
		}
	}
}

namespace
{
	/*
		Serialisation methods
	*/
	void SerialiseString(const DocumentTree::StringNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer);
	void SerialiseNumber(const DocumentTree::NumberNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer);
	void SerialiseObject(const DocumentTree::ObjectNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer);
	void SerialiseArray(const DocumentTree::ArrayNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer);
	void SerialiseNode(const DocumentTree::NodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer);

	void SerialiseString(const DocumentTree::StringNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer)
	{
		writer.String(node_in->GetName().c_str());
		writer.String(node_in->GetValue().c_str());
	}

	void SerialiseNumber(const DocumentTree::NumberNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer)
	{
		writer.String(node_in->GetName().c_str());
		writer.Double(node_in->GetValue());
	}

	void SerialiseObject(const DocumentTree::ObjectNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer)
	{
		if (!node_in->GetName().empty())
		{
			writer.String(node_in->GetName().c_str());
		}

		writer.StartObject();

		auto children = node_in->GetValue().GetChildren();
		
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			auto& child = children[i];
			SerialiseNode(child, writer);
		}

		writer.EndObject();
	}

	void SerialiseArray(const DocumentTree::ArrayNodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer)
	{
		writer.String(node_in->GetName().c_str());

		writer.StartArray();

		auto elements = node_in->GetValue().GetElements();

		for (auto& child : elements)
		{
			SerialiseNode(child, writer);
		}

		writer.EndArray();
	}

	void SerialiseNode(const DocumentTree::NodePtr& node_in, rapidjson::Writer<rapidjson::StringBuffer>& writer)
	{
		switch (node_in->GetType())
		{
		case INode::Type::String:
			SerialiseString(std::static_pointer_cast<StringNode>(node_in), writer);
			break;
		case INode::Type::Number:
			SerialiseNumber(std::static_pointer_cast<NumberNode>(node_in), writer);
			break;
		case INode::Type::Object:
			SerialiseObject(std::static_pointer_cast<ObjectNode>(node_in), writer);
			break;
		case INode::Type::Array:
			SerialiseArray(std::static_pointer_cast<ArrayNode>(node_in), writer);
			break;
		default:
			assert(!"Unknown type!");
				break;
		}
	}
}

ObjectNodePtr JsonParser::Parse(const Buffer& buffer) const
{
	rapidjson::Document document;
	document.Parse(std::string(buffer.begin(), buffer.end()).c_str());
	
	ObjectNodePtr ret = ParseObject(document.GetObject(),"");
	
	return ret;
}

Buffer JsonParser::Serialise(const DocumentTree::ObjectNodePtr& document_tree) const
{
	Buffer ret;

	rapidjson::StringBuffer stringBuffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);

	SerialiseNode(document_tree, writer);

	if (stringBuffer.GetSize() != 0)
	{
		ret.resize(stringBuffer.GetSize());
		memcpy(&ret.front(), stringBuffer.GetString(), ret.size());
	}

	return ret;
}

std::string JsonParser::GetDefaultFileExtension() const
{
	return ".json";
}
