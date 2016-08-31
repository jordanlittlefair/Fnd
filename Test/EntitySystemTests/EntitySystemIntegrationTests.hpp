#pragma once

#pragma once

#include "../Framework/IntegrationTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class EntitySystemIntegrationTests:
	public IntegrationTestClass
{
public:

	EntitySystemIntegrationTests();

private:

	void Create_Components_Nodes_And_Loop_Nodes(Fnd::Test::TestCase& test_case);
};

}

}

}
