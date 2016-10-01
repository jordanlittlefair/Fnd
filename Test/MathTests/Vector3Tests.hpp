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
		this->AddTestCase( "Constructor_Success", &Vector3Tests::Constructor_Success, this );
		this->AddTestCase( "LengthSquared_Success", &Vector3Tests::LengthSquared_Success, this );
		this->AddTestCase( "Length_Success", &Vector3Tests::Length_Success, this );
		this->AddTestCase( "Normalise_Success", &Vector3Tests::Normalise_Success, this );
		this->AddTestCase( "Dot_Success", &Vector3Tests::Dot_Success, this );
	}

private:

	using typename VectorTestsBase<Fnd::Math::Vector3<Number>>::TestVec;

	void Constructor_Success(TestCase& test_case)
	{
		TestVec v(12, 34, 56);

		test_case.AssertEqual(12, v.x);
		test_case.AssertEqual(34, v.y);
		test_case.AssertEqual(56, v.z);
	}

	void LengthSquared_Success(TestCase& test_case)
	{
		TestVec v(2, 10, 11);

		test_case.AssertEqual(15 * 15, Fnd::Math::LengthSquared(v));
	}

	void Length_Success(TestCase& test_case)
	{		
		TestVec v(2, 10, 11);

		test_case.AssertEqual(15, Fnd::Math::Length(v));
	}

	void Normalise_Success(TestCase& test_case)
	{
		{
			TestVec v(5, 0, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(1, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(0, n.z);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 5, 0);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(1, n.y);
			test_case.AssertEqual(0, n.z);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(0, 0, 5);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertEqual(0, n.x);
			test_case.AssertEqual(0, n.y);
			test_case.AssertEqual(1, n.z);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
		{
			TestVec v(1, 1, 1);
			TestVec n = Fnd::Math::Normalise(v);

			test_case.AssertFloatEqual(n.x, n.y);
			test_case.AssertFloatEqual(n.x, n.z);
			test_case.AssertFloatEqual(n.y, n.z);
			test_case.AssertFloatEqual(1, Fnd::Math::Length(n));
		}
	}

	void Dot_Success(TestCase& test_case)
	{
		{
			TestVec a(1, 0, 0);
			TestVec b(1, 0, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(1, dot);
		}
		{
			TestVec a(1, 0, 0);
			TestVec b(-1, 0, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(-1, dot);
		}
		{
			TestVec a(1, 0, 0);
			TestVec b(0, 1, 0);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
		{
			TestVec a(0, 1, 0);
			TestVec b(0, 0, 1);

			Number dot = Fnd::Math::Dot(a, b);

			test_case.AssertFloatEqual(0, dot);
		}
	}
};

}

}

}
