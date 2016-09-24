#pragma once 

#include "VectorTestsBase.hpp"

#include "../../Code/Math/Vector3.hpp"

namespace Fnd
{

namespace Test
{

namespace Math
{

template <typename Number>
class Vector3Tests:
	public VectorTestsBase<Fnd::Math::Vector3<Number>>
{
public:

	Vector3Tests(const std::string& number_type):
		VectorTestsBase<Fnd::Math::Vector3<Number>>("Vector3Tests<" + number_type + ">")
	{
	}
};

}

}

}
