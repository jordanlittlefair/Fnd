#include "Exception.hpp"

using namespace Fnd::Core;

const char* Exception::what() const throw()
{
	return _message.c_str();
}

Exception::Exception( const std::string& message ):
	_message(message)
{
}
