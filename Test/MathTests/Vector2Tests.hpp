#pragma once 

#include "VectorTestsBase.hpp"

#include "../../Code/Math/Vector2.hpp"

namespace Fnd
{

namespace Test
{

namespace Math
{

template <typename Number>
class Vector2Tests:
	public VectorTestsBase<Fnd::Math::Vector2<Number>>
{
public:

	Vector2Tests(const std::string& number_type):
		VectorTestsBase<Fnd::Math::Vector2<Number>>("Vector2Tests<" + number_type + ">")
	{
	}
};

}

}

}
