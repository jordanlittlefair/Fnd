#include "Exceptions.hpp"

using namespace Fnd::EntitySystem;

Exception::Exception( const std::string& what ):
	Fnd::Core::Exception(what)
{
}

InvalidComponentIdException::InvalidComponentIdException():
	Exception("Invalid ComponentId")
{
}

InvalidEntityIdException::InvalidEntityIdException():
	Exception("Invalid EntityId")
{
}
