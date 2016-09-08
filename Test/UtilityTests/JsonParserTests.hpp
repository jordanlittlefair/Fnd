#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Utility
{

class JsonParserTests:
	public UnitTestClass
{
public:

	JsonParserTests();

private:
	
	void ParseAndSerialise_EmptyObject_Success(Fnd::Test::TestCase& test_case);
	void ParseAndSerialise_StringValue_Success(Fnd::Test::TestCase& test_case);
	void ParseAndSerialise_NumberValue_Success(Fnd::Test::TestCase& test_case);
	void ParseAndSerialise_EmptyArrayValue_Success(Fnd::Test::TestCase& test_case);
	void ParseAndSerialise_EmptyObjectValue_Success(Fnd::Test::TestCase& test_case);
	
};

}

}

}
