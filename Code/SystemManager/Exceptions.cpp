#include "Exceptions.hpp"

#include <sstream>

using namespace Fnd::SystemManager;

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

InvalidSystemIdException::InvalidSystemIdException():
Fnd::SystemManager::Exception("Invalid SystemId")
{
}

InvalidSystemIdException::InvalidSystemIdException(const SystemId system_id):
	Fnd::SystemManager::Exception("Invalid SystemId[" + IdToString(system_id) + "]")
{
}

InvalidSystemDependenciesException::InvalidSystemDependenciesException():
	Fnd::SystemManager::Exception("Invalid System dependencies")
{
}

InvalidOperationException::InvalidOperationException():
Fnd::SystemManager::Exception("Invalid Operation on SystemManager component")
{
}
