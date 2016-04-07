#pragma once

#include <exception>
#include <string>

namespace Fnd
{

namespace Core
{

class Exception:
	public std::exception
{
public:

	virtual const char* what() const throw();
	
protected:

	Exception( const std::string& message );

private:

	const std::string _message;
};

}

}
