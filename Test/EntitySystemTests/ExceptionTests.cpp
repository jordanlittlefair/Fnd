#include "ExceptionTests.hpp"

#include "../../Code/EntitySystem/Exceptions.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

ExceptionTests::ExceptionTests():
	UnitTestClass("ExceptionTests")
{
	AddTestCase( "ThrowInvalidComponentIdException_Caught", &ExceptionTests::ThrowInvalidComponentIdException_Caught, this );
	AddTestCase( "ThrowInvalidComponentIdException_CaughtEntitySystemException", &ExceptionTests::ThrowInvalidComponentIdException_CaughtEntitySystemException, this );
	AddTestCase( "ThrowInvalidComponentIdException_CaughtFndException", &ExceptionTests::ThrowInvalidComponentIdException_CaughtFndException, this );
	AddTestCase( "ThrowInvalidEntityIdException_Caught", &ExceptionTests::ThrowInvalidEntityIdException_Caught, this );
	AddTestCase( "ThrowInvalidEntityIdException_CaughtEntitySystemException", &ExceptionTests::ThrowInvalidEntityIdException_CaughtEntitySystemException, this );
	AddTestCase( "ThrowInvalidEntityIdException_CaughtFndException", &ExceptionTests::ThrowInvalidEntityIdException_CaughtFndException, this );
	AddTestCase( "ThrowInvalidNodeIdException_Caught", &ExceptionTests::ThrowInvalidNodeIdException_Caught, this );
	AddTestCase( "ThrowInvalidNodeIdException_CaughtEntitySystemException", &ExceptionTests::ThrowInvalidNodeIdException_CaughtEntitySystemException, this );
	AddTestCase( "ThrowInvalidNodeIdException_CaughtFndException", &ExceptionTests::ThrowInvalidNodeIdException_CaughtFndException, this );
}

void ExceptionTests::ThrowInvalidComponentIdException_Caught(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<InvalidComponentIdException>([]()
	{
		throw InvalidComponentIdException();
	});
}

void ExceptionTests::ThrowInvalidComponentIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::EntitySystem::Exception>([]()
	{
		throw InvalidComponentIdException();
	});
}

void ExceptionTests::ThrowInvalidComponentIdException_CaughtFndException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::Core::Exception>([]()
	{
		throw InvalidComponentIdException();
	});
}

void ExceptionTests::ThrowInvalidEntityIdException_Caught(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<InvalidEntityIdException>([]()
	{
		throw InvalidEntityIdException();
	});
}

void ExceptionTests::ThrowInvalidEntityIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::EntitySystem::Exception>([]()
	{
		throw InvalidEntityIdException();
	});
}

void ExceptionTests::ThrowInvalidEntityIdException_CaughtFndException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::Core::Exception>([]()
	{
		throw InvalidEntityIdException();
	});
}

void ExceptionTests::ThrowInvalidNodeIdException_Caught(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<InvalidNodeIdException>([]()
	{
		throw InvalidNodeIdException();
	});
}

void ExceptionTests::ThrowInvalidNodeIdException_CaughtEntitySystemException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::EntitySystem::Exception>([]()
	{
		throw InvalidNodeIdException();
	});
}

void ExceptionTests::ThrowInvalidNodeIdException_CaughtFndException(Fnd::Test::TestCase& test_case)
{
	test_case.AssertException<Fnd::Core::Exception>([]()
	{
		throw InvalidNodeIdException();
	});
}
