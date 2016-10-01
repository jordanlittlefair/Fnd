#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class ModuleConfigFileTests:
	public UnitTestClass
{
public:
	
	ModuleConfigFileTests();
	
private:
	
	void LoadConfigDocumentTree_Success(Fnd::Test::TestCase& test_case);
	void SaveConfigDocumentTree_Success(Fnd::Test::TestCase& test_case);
};

}

}

}
