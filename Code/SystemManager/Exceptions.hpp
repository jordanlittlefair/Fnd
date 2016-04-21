#pragma once

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
};
	
class InvalidSystemDependenciesException:
	public Fnd::SystemManager::Exception
{
public:

	InvalidSystemDependenciesException();
};

}

}
