#pragma once 

#include "VectorTestsBase.hpp"

#include "../../Code/Math/Vector4.hpp"

namespace Fnd
{

namespace Test
{

namespace Math
{

template <typename Number>
class Vector4Tests:
	public VectorTestsBase<Fnd::Math::Vector4<Number>>
{
public:

	Vector4Tests(const std::string& number_type):
		VectorTestsBase<Fnd::Math::Vector4<Number>>("Vector4Tests<" + number_type + ">")
	{
	}
};

}

}

}
