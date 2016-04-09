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

}

}