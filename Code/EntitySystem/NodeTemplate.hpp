#pragma once

#include "Node.hpp"

namespace Fnd
{

namespace EntitySystem
{

template <typename NodeType>
class NodeTemplate:
	public Node
{
public:

	static_assert( sizeof(typename NodeType::Components), "NodeType must define a Components struct" );

	typedef typename NodeType::Components NodeComponents;

	NodeTemplate ( const EntityId entity_id ):
		Node( NodeType::Id, entity_id )
	{
	}
	
	
};

}

}
