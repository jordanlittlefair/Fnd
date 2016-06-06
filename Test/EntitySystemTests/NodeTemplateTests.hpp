#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{
	
class NodeTemplateTests:
	public TestClass
{
public:
	
	NodeTemplateTests();
	
private:
	
	void GetNodeId_Success( Fnd::Test::TestCase& test_case );
	
	void GetEntityId_Success( Fnd::Test::TestCase& test_case );
};
	
}

}

}
