#include "Exceptions.hpp"

using namespace Fnd::SystemManager;

Exception::Exception( const std::string& what ):
	Fnd::Core::Exception(what)
{
}

InvalidSystemIdException::InvalidSystemIdException():
	Fnd::SystemManager::Exception("Invalid SystemId")
{
}

InvalidSystemDependenciesException::InvalidSystemDependenciesException():
	Fnd::SystemManager::Exception("Invalid System dependencies")
{
}
