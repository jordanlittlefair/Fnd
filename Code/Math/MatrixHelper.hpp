#pragma once

#include <stdexcept>

namespace Fnd
{

namespace Math
{

enum class MatrixOrder
{
	RowMajor,
	ColumnMajor
};
	
enum class Handedness
{
	Left,
	Right
};
	
template <MatrixOrder MatrixOrderT>
class MatrixHelper
{
public:
	
	static const MatrixOrder MatrixOrder = MatrixOrderT;
	
protected:
	
	template <typename MatrixType>
	static MatrixType ConvertOrder(const MatrixType& matrix)
	{
		if (MatrixOrder == MatrixOrder::RowMajor)
		{
			return matrix;
		}
		else if (MatrixOrder == MatrixOrder::ColumnMajor)
		{
			return Transpose(matrix);
		}
		else
		{
			throw std::runtime_error("Unknown MatrixOrder");
		}
	}
};

}

}
