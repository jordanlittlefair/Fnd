#include "AssertResult.hpp"

using namespace Fnd::Test;

AssertResult::AssertResult( const bool succeeded, const std::string& description ):
	_succeeded(succeeded),
	_description(description)
{
}

std::string AssertResult::GetDescription() const
{
	return _description;
}

bool AssertResult::GetSucceeded() const
{
	return _succeeded;
}
