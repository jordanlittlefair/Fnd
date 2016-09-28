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
		this->AddTestCase( "Constructor_Success", &Vector4Tests::Constructor_Success, this );
		this->AddTestCase( "LengthSquared_Success", &Vector4Tests::LengthSquared_Success, this );
		this->AddTestCase( "Length_Success", &Vector4Tests::Length_Success, this );
		this->AddTestCase( "Normalise_Success", &Vector4Tests::Normalise_Success, this );
		this->AddTestCase( "Dot_Success", &Vector4Tests::Dot_Success, this );
	}

private:

	using typename VectorTestsBase<Fnd::Math::Vector4<Number>>::TestVec;

	void Constructor_Success(TestCase& test_case)
	{
		TestVec v(12, 34, 56, 78);

		test_case.AssertEqual(12, v.x);
		test_case.AssertEqual(34, v.y);
		test_case.AssertEqual(56, v.z);
		test_case.AssertEqual(78, v.w);
	}

	void LengthSquared_Success(TestCase& test_case)
	{
		TestVec v(1, 3, 5, 17);

		test_case.AssertEqual(18 * 18, Fnd::Math::LengthSquared(v));
	}

	void Length_Success(TestCase& test_case)
	{
		TestVec v(1, 3, 5, 17);

		test_case.AssertEqual(18, Fnd::Math::Length(v));
	}

	void Normalise_Success(TestCase& test_case)
	{
		{
			TestVec v(5, 0, 0, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(1, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(0, n.z);
			test_case.AssertEqual(0, n.w);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 5, 0, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(1, n.y);
			test_case.AssertEqual(0, n.z);
			test_case.AssertEqual(0, n.w);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 0, 5, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(1, n.z);
			test_case.AssertEqual(0, n.w);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 0, 0, 5);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(0, n.z);
			test_case.AssertEqual(1, n.w);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(1, 1, 1, 1);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertFloatEqual(n.x, n.y);
			test_case.AssertFloatEqual(n.x, n.z);
			test_case.AssertFloatEqual(n.x, n.w);
			test_case.AssertFloatEqual(n.y, n.z);
			test_case.AssertFloatEqual(n.y, n.w);
			test_case.AssertFloatEqual(n.z, n.w);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
	}

	void Dot_Success(TestCase& test_case)
	{
		{
			TestVec a(1, 0, 0, 0);
			TestVec b(1, 0, 0, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(1, dot);
		}
		{
			TestVec a(1, 0, 0, 0);
			TestVec b(-1, 0, 0, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(-1, dot);
		}
		{
			TestVec a(1, 0, 0, 0);
			TestVec b(0, 1, 0, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
		{
			TestVec a(0, 1, 0, 0);
			TestVec b(0, 0, 1, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
		{
			TestVec a(0, 0, 1, 0);
			TestVec b(0, 0, 0, 1);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
	}
};

}

}

}
