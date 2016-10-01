#include "Exceptions.hpp"

using namespace Fnd::Modules;

Exception::Exception(const std::string& what):
	Fnd::Core::Exception(what)
{
}

InvalidOperationException::InvalidOperationException(const std::string& what):
	Fnd::Modules::Exception(what)
{
}
