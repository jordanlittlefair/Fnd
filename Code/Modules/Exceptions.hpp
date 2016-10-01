#pragma once

#include "../Core/Exception.hpp"

namespace Fnd
{

namespace Modules
{

class Exception:
	public Fnd::Core::Exception
{
protected:
	
	Exception(const std::string& what);
};

class InvalidOperationException:
public Fnd::Modules::Exception
{
public:
	
	InvalidOperationException(const std::string& what);
};

}

}
