#include "SystemManagerExceptionTests.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

SystemManagerExceptionTests::SystemManagerExceptionTests():
	UnitTestClass("SystemManagerExceptionTests")
{
	AddTestCase( "SystemManagerExceptionTests", &SystemManagerExceptionTests::TestInvalidSystemIdException, this );
	AddTestCase( "TestInvalidSystemDependenciesException", &SystemManagerExceptionTests::TestInvalidSystemDependenciesException, this );
}

void SystemManagerExceptionTests::TestInvalidSystemIdException( TestCase& test_case )
{
	bool caught_InvalidSystemIdException = false;
	bool caught_SystemManagerException = false;
	bool caught_FndException = false;
	bool caught_StdException = false;

	try
	{
		throw InvalidSystemIdException(0);
	}
	catch ( const InvalidSystemIdException& )
	{
		caught_InvalidSystemIdException = true;
	}
	
	try
	{
		throw InvalidSystemIdException(0);
	}
	catch ( const Fnd::SystemManager::Exception& )
	{
		caught_SystemManagerException = true;
	}
	
	try
	{
		throw InvalidSystemIdException(0);
	}
	catch ( const Fnd::Core::Exception& )
	{
		caught_FndException = true;
	}
	
	try
	{
		throw InvalidSystemIdException(0);
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

void SystemManagerExceptionTests::TestInvalidSystemDependenciesException( TestCase& test_case )
{
	bool caught_InvalidSystemDependenciesException = false;
	bool caught_SystemManagerException = false;
	bool caught_FndException = false;
	bool caught_StdException = false;
	
	try
	{
		throw InvalidSystemDependenciesException();
	}
	catch ( const InvalidSystemDependenciesException& )
	{
		caught_InvalidSystemDependenciesException = true;
	}
	
	try
	{
		throw InvalidSystemDependenciesException();
	}
	catch ( const Fnd::SystemManager::Exception& )
	{
		caught_SystemManagerException = true;
	}
	
	try
	{
		throw InvalidSystemDependenciesException();
	}
	catch ( const Fnd::Core::Exception& )
	{
		caught_FndException = true;
	}
	
	try
	{
		throw InvalidSystemDependenciesException();
	}
	catch ( const std::exception& )
	{
		caught_StdException = true;
	}
	
	test_case.Assert(caught_InvalidSystemDependenciesException);
	test_case.Assert(caught_SystemManagerException);
	test_case.Assert(caught_FndException);
	test_case.Assert(caught_StdException);
}
