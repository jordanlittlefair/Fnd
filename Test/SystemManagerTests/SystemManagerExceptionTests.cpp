#include "SystemManagerExceptionTests.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

SystemManagerExceptionTests::SystemManagerExceptionTests():
	TestClass("SystemManagerExceptionTests")
{
	AddTestCase( "SystemManagerExceptionTests", &SystemManagerExceptionTests::TestInvalidSystemIdException, this );
}

void SystemManagerExceptionTests::TestInvalidSystemIdException( TestCase& test_case )
{
	bool caught_InvalidSystemIdException = false;
	bool caught_SystemManagerException = false;
	bool caught_FndException = false;
	bool caught_StdException = false;

	try
	{
		throw InvalidSystemIdException();
	}
	catch( const InvalidSystemIdException& )
	{
		caught_InvalidSystemIdException = true;
	}
	
	try
	{
		throw InvalidSystemIdException();
	}
	catch ( const Fnd::SystemManager::Exception& )
	{
		caught_SystemManagerException = true;
	}
	
	try
	{
		throw InvalidSystemIdException();
	}
	catch ( const Fnd::Core::Exception& )
	{
		caught_FndException = true;
	}
	
	try
	{
		throw InvalidSystemIdException();
	}
	catch ( const std::exception& )
	{
		caught_StdException = true;
	}
	
	test_case.Assert(caught_InvalidSystemIdException);
	test_case.Assert(caught_SystemManagerException);
	test_case.Assert(caught_FndException);
	test_case.Assert(caught_StdException);
}
