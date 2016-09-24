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
		this->AddTestCase( "Constructor_Success", &Vector2Tests::Constructor_Success, this );
		this->AddTestCase( "LengthSquared_Success", &Vector2Tests::LengthSquared_Success, this );
		this->AddTestCase( "Length_Success", &Vector2Tests::Length_Success, this );
		this->AddTestCase( "Normalise_Success", &Vector2Tests::Normalise_Success, this );
		this->AddTestCase( "Dot_Success", &Vector2Tests::Dot_Success, this );
	}

private:

	using typename VectorTestsBase<Fnd::Math::Vector2<Number>>::TestVec;

	void Constructor_Success(TestCase& test_case)
	{
		TestVec v(123, 456);

		test_case.AssertEqual(123, v.x);
		test_case.AssertEqual(456, v.y);
	}

	void LengthSquared_Success(TestCase& test_case)
	{
		TestVec v(3, 4);

		test_case.AssertEqual(5 * 5, Fnd::Math::LengthSquared(v));
	}

	void Length_Success(TestCase& test_case)
	{
		TestVec v(3, 4);

		test_case.AssertEqual(5, Fnd::Math::Length(v));
	}

	void Normalise_Success(TestCase& test_case)
	{
		{
			TestVec v(5, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(1, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 5);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(1, n.y);
			test_case.AssertEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(1, 1);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(n.x, n.y);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
	}

	void Dot_Success(TestCase& test_case)
	{
		{
			TestVec a(1, 0);
			TestVec b(1, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(1, dot);
		}
		{
			TestVec a(1, 0);
			TestVec b(-1, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(-1, dot);
		}
		{
			TestVec a(1, 0);
			TestVec b(0, 1);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
	}	
};

}

}

}
