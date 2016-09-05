#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Utility
{

class DocumentTreeTests:
	public UnitTestClass
{
public:
	
	DocumentTreeTests();
	
private:
	
	void CreateStringNode_Success(Fnd::Test::TestCase& test_case);
	void CreateIntegerNode_Success(Fnd::Test::TestCase& test_case);
	void CreateFloatNode_Success(Fnd::Test::TestCase& test_case);
	void CreateObjectNode_Success(Fnd::Test::TestCase& test_case);
	void CreateArrayNode_Success(Fnd::Test::TestCase& test_case);
	
	void AddStringNodeToObject_Success(Fnd::Test::TestCase& test_case);
	void AddIntegerNodeToObject_Success(Fnd::Test::TestCase& test_case);
	void AddFloatNodeToObject_Success(Fnd::Test::TestCase& test_case);
	void AddObjectNodeToObject_Success(Fnd::Test::TestCase& test_case);
	void AddArrayNodeToObject_Success(Fnd::Test::TestCase& test_case);
	void AddMultipleNodesToObject_Success(Fnd::Test::TestCase& test_case);
	
	void AddStringNodeToArray_Success(Fnd::Test::TestCase& test_case);
	void AddIntegergNodeToArray_Success(Fnd::Test::TestCase& test_case);
	void AddFloatNodeToArray_Success(Fnd::Test::TestCase& test_case);
	void AddObjectNodeToArray_Success(Fnd::Test::TestCase& test_case);
	void AddArrayNodeToArray_Success(Fnd::Test::TestCase& test_case);
	void AddMultipleNodesToArray_Success(Fnd::Test::TestCase& test_case);
};

}

}

}