#pragma once

#include <string>

namespace Fnd
{

namespace Test
{

/**
	@brief The result of a call to Assert.
	Stores whether the Assert succeeded and a brief description of what the Assert call tests.
*/
class AssertResult
{
public:

	AssertResult( const bool succeeded, const std::string& description );
	
	AssertResult( const AssertResult& ) = default;
	AssertResult& operator=( const AssertResult& ) = default;
	
	std::string GetDescription() const;
	
	bool GetSucceeded() const;
	
private:
	
	std::string _description;
	
	bool _succeeded;
};

}
	
}
