#pragma once

#include "../Core/Exception.hpp"

namespace Fnd
{

namespace EntitySystem
{

class Exception:
	public Fnd::Core::Exception
{
protected:
	
	Exception( const std::string& what );
};

class InvalidComponentIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidComponentIdException();
};

class InvalidEntityIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidEntityIdException();
};
	
class InvalidNodeIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidNodeIdException();
};

}

}