#include "Exceptions.hpp"

#include <sstream>

using namespace Fnd::EntitySystem;

namespace
{
	template <typename IdType>
	std::string IdToString(const IdType& id)
	{
		std::stringstream ss;
		ss << id;
		return ss.str();
	}
}

Exception::Exception( const std::string& what ):
	Fnd::Core::Exception(what)
{
}

InvalidComponentIdException::InvalidComponentIdException():
	Exception("Invalid ComponentId")
{
}

InvalidComponentIdException::InvalidComponentIdException(const ComponentId invalid_component_id):
	Exception("Invalid ComponentId [" + IdToString(invalid_component_id) + "]")
{
}

InvalidEntityIdException::InvalidEntityIdException():
	Exception("Invalid EntityId")
{
}

InvalidEntityIdException::InvalidEntityIdException(const EntityId invalid_entity_id):
	Exception("Invalid EntityId [" + IdToString(invalid_entity_id) + "]")
{
}

InvalidNodeIdException::InvalidNodeIdException():
	Exception("Invalid NodeId")
{
}

InvalidNodeIdException::InvalidNodeIdException(const NodeId invalid_node_id):
Exception("Invalid NodeId [" + IdToString(invalid_node_id) + "]")
{
}
