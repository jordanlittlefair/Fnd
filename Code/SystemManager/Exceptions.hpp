#pragma once

#include "SystemId.hpp"
#include "../Core/Exception.hpp"

namespace Fnd
{

namespace SystemManager
{

class Exception:
	public Fnd::Core::Exception
{
protected:

	Exception( const std::string& what );
};

class InvalidSystemIdException:
	public Fnd::SystemManager::Exception
{
public:

	InvalidSystemIdException();
	
	InvalidSystemIdException(const SystemId system_id);
};
	
class InvalidSystemDependenciesException:
	public Fnd::SystemManager::Exception
{
public:

	InvalidSystemDependenciesException();
};
	
class InvalidOperationException:
	public Fnd::SystemManager::Exception
{
public:
	
	InvalidOperationException();
};

}

}
