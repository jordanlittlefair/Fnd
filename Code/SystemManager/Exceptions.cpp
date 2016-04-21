#include "Exceptions.hpp"

using namespace Fnd::SystemManager;

Exception::Exception( const std::string& what ):
	Fnd::Core::Exception(what)
{
}

InvalidSystemIdException::InvalidSystemIdException():
	Fnd::SystemManager::Exception("Invalid System::Id")
{
}

InvalidSystemDependenciesException::InvalidSystemDependenciesException():
	Fnd::SystemManager::Exception("Invalid System dependencies")
{
}
