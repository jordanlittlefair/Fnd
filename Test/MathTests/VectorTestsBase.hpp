#pragma once

#include "../Framework/UnitTestClass.hpp"


namespace Fnd
{

namespace Test
{

namespace Math
{

template <typename VectorType>
class VectorTestsBase:
	public UnitTestClass
{
public:

	typedef VectorType TestVec;
	typedef typename VectorType::NumberType Number;

	VectorTestsBase(const std::string& description):
		UnitTestClass(description)
	{
		AddTestCase( "Zero_Success", &VectorTestsBase::Zero_Success, this );
		AddTestCase( "Negate_Success", &VectorTestsBase::Negate_Success, this );
		AddTestCase( "Add_Success", &VectorTestsBase::Add_Success, this );
		AddTestCase( "Minus_Success", &VectorTestsBase::Minus_Success, this );
		AddTestCase( "MultiplyScalar_Success", &VectorTestsBase::MultiplyScalar_Success, this );
		AddTestCase( "Multiply_Success", &VectorTestsBase::Multiply_Success, this );
		AddTestCase( "DivideScalar_Success", &VectorTestsBase::DivideScalar_Success, this );
		AddTestCase( "Divide_Success", &VectorTestsBase::Divide_Success, this );
		AddTestCase( "AddAssign_Success", &VectorTestsBase::AddAssign_Success, this );
		AddTestCase( "MinusAssign_Success", &VectorTestsBase::MinusAssign_Success, this );
		AddTestCase( "MultiplyScalarAssign_Success", &VectorTestsBase::MultiplyScalarAssign_Success, this );
		AddTestCase( "MultiplyAssign_Success", &VectorTestsBase::MultiplyAssign_Success, this );
		AddTestCase( "DivideScalarAssign_Success", &VectorTestsBase::DivideScalarAssign_Success, this );
		AddTestCase( "DivideAssign_Success", &VectorTestsBase::DivideAssign_Success, this );
	}
	
private:
	
	void Zero_Success(TestCase& test_case)
	{
		TestVec zero = TestVec::Zero();

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(0, zero[i]);
		}
	}

	void Negate_Success(TestCase& test_case)
	{
		TestVec pos;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			pos[i] = DefaultElements[i];
		}

		TestVec neg = -pos;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(-DefaultElements[i], neg[i]);
		}
	}

	void Add_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec sum = a + b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], sum[i]);
		}

		sum = b + a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], sum[i]);
		}
	}

	void Minus_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec sum = a - b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] - AltElements[i], sum[i]);
		}

		sum = b - a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(AltElements[i] - DefaultElements[i], sum[i]);
		}
	}
	
	void MultiplyScalar_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		Number b = 10;
		TestVec product = a * b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * b, product[i]);
		}

		product = b * a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * b, product[i]);
		}
	}

	void Multiply_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;		
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec product = a * b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], product[i]);
		}

		product = b * a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], product[i]);
		}
	}

	void DivideScalar_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		Number b = 10;
		TestVec product = a / b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] / b, product[i]);
		}
	}

	void Divide_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec product = a / b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] / AltElements[i], product[i]);
		}
	}

	void AddAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec sum = a += b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], sum[i]);
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], a[i]);
		}

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		sum = b += a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], sum[i]);
			test_case.AssertEqual(DefaultElements[i] + AltElements[i], b[i]);
		}
	}

	void MinusAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec sum = a -= b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] - AltElements[i], sum[i]);
			test_case.AssertEqual(DefaultElements[i] - AltElements[i], a[i]);
		}
		
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		sum = b -= a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(AltElements[i] - DefaultElements[i], sum[i]);
			test_case.AssertEqual(AltElements[i] - DefaultElements[i], b[i]);
		}
	}
	
	void MultiplyScalarAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		Number b = 10;
		TestVec product = a *= b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * b, product[i]);
			test_case.AssertEqual(DefaultElements[i] * b, a[i]);
		}
	}

	void MultiplyAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;		
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec product = a *= b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], product[i]);
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], a[i]);
		}
		
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		product = b *= a;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], product[i]);
			test_case.AssertEqual(DefaultElements[i] * AltElements[i], b[i]);
		}
	}

	void DivideScalarAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		Number b = 10;
		TestVec product = a /= b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] / b, product[i]);
			test_case.AssertEqual(DefaultElements[i] / b, a[i]);
		}
	}

	void DivideAssign_Success(TestCase& test_case)
	{
		TestVec a;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			a[i] = DefaultElements[i];
		}
		TestVec b;
		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			b[i] = AltElements[i];
		}
		TestVec product = a /= b;

		for (unsigned int i = 0; i < TestVec::NumElements; ++i)
		{
			test_case.AssertEqual(DefaultElements[i] / AltElements[i], product[i]);
			test_case.AssertEqual(DefaultElements[i] / AltElements[i], a[i]);
		}
	}

private:

	static const unsigned int MaxElements = 4;

	static const Number DefaultElements[MaxElements];
	static const Number AltElements[MaxElements];
};

template <typename VectorType> 
const typename VectorTestsBase<VectorType>::Number VectorTestsBase<VectorType>::DefaultElements[] = { 12, 34, 56, 78 };

template <typename VectorType> 
const typename VectorTestsBase<VectorType>::Number VectorTestsBase<VectorType>::AltElements[] = { 10, 20, 30, 40 };

}

}

}
