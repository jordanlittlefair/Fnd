#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ExceptionTests:
	public UnitTestClass
{
public:

	ExceptionTests();

private:
	
	void ThrowInvalidComponentIdException_Caught(Fnd::Test::TestCase& test_case);
	void ThrowInvalidComponentIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case);
	void ThrowInvalidComponentIdException_CaughtFndException(Fnd::Test::TestCase& test_case);

	void ThrowInvalidEntityIdException_Caught(Fnd::Test::TestCase& test_case);
	void ThrowInvalidEntityIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case);
	void ThrowInvalidEntityIdException_CaughtFndException(Fnd::Test::TestCase& test_case);

	void ThrowInvalidNodeIdException_Caught(Fnd::Test::TestCase& test_case);
	void ThrowInvalidNodeIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case);
	void ThrowInvalidNodeIdException_CaughtFndException(Fnd::Test::TestCase& test_case);
};

}

}

}
