#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class Matrix
{
private:
	int m_rows;
	int m_columns;
	std::vector<std::vector<double>> m_matrix;
public:
	Matrix(int rows, int columns)
		: m_rows(rows), m_columns(columns)
	{
		m_matrix.resize(rows, std::vector<double>(columns, 0));
	}

	Matrix(int rows, int columns, std::vector<double> data)
		: m_rows(rows), m_columns(columns)
	{
		if (data.size() != rows * columns)
		{
			std::cout << "Number of input element is not equal to matrix size.\n";
			return;
		}
		m_matrix.resize(rows, std::vector<double>(columns, 0));
		for (int i = 0; i != m_matrix.size(); ++i)
			for (int j = 0; j != m_matrix[i].size(); ++j)
				m_matrix[i][j] = data[i * m_matrix[i].size() + j];
	}

	Matrix(Matrix &m)
		: m_matrix(m.m_matrix), m_rows(m.m_rows), m_columns(m.m_columns)
	{
	}

	Matrix(Matrix &m, int row, int column)
	{
		if (row > m.m_rows || column > m.m_columns)
		{
			std::cout << "Given row or column is too large\n";
		}

		Matrix newMatrix(m.m_rows - 1, m.m_columns - 1);

		for (int i = 0; i != m.m_rows - 1; ++i)
			if (i != row)
			{
				for (int j = 0; j != m.m_columns - 1; ++j)
				{
					if (j != column)
					{
						if (i > row)
						{
							if (j < column)
								newMatrix.m_matrix[i][j] = m.m_matrix[i + 1][j];
							else if (j > column)
								newMatrix.m_matrix[i][j] = m.m_matrix[i + 1][j + 1];
						}
						else if (i < row)
						{
							if (j < column)
								newMatrix.m_matrix[i][j] = m.m_matrix[i][j];
							else if (j > column)
								newMatrix.m_matrix[i][j] = m.m_matrix[i][j + 1];
						}
					}
				}
			}
	}

	void print()
	{
		for (int i = 0; i != m_matrix.size(); ++i)
		{
			for (int j = 0; j != m_matrix[i].size(); ++j)
				std::cout << m_matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

	Matrix operator+ (Matrix &m);
	Matrix operator-(Matrix &m);
	Matrix operator* (Matrix &m);
	Matrix operator*(int value);
	//friend Matrix operator*(int value, Matrix &m);
	Matrix &operator*=(int value);

	virtual ~Matrix()
	{}
};

Matrix Matrix::operator+ (Matrix &m)
{
	Matrix temp(m_rows, m_columns);
	if (m.m_columns != m_columns || m.m_rows != m_rows)
	{
		std::cout << "Matrices have different dimensions. Cannot add them.";
		for (int i = 0; i != m_rows; ++i)
			for (int j = 0; j != m_columns; ++j)
				temp.m_matrix[i][j] = m_matrix[i][j];
	}
	else
	{
		for (int i = 0; i != m_rows; ++i)
			for (int j = 0; j != m_columns; ++j)
				temp.m_matrix[i][j] = m_matrix[i][j] + m.m_matrix[i][j];
	}
	return temp;
}

Matrix Matrix::operator-(Matrix &m)
{
	Matrix temp(m_rows, m_columns);
	if (m.m_columns != m_columns || m.m_rows != m_rows)
	{
		std::cout << "Matrices have different dimensions. Cannot add them.";
		for (int i = 0; i != m_rows; ++i)
			for (int j = 0; j != m_columns; ++j)
				temp.m_matrix[i][j] = m_matrix[i][j];
	}
	else
	{
		for (int i = 0; i != m_rows; ++i)
			for (int j = 0; j != m_columns; ++j)
				temp.m_matrix[i][j] = m_matrix[i][j] - m.m_matrix[i][j];
	}
	return temp;
}

Matrix Matrix::operator* (Matrix &m)
{
	if (m_columns != m.m_rows)
	{
		std::cout << "Sizes of matrices don't match. Cannot multiply them\n";
		return *this;
	}
	Matrix temp(m_rows, m.m_columns);
	for (int i = 0; i != m_rows; ++i)
		for (int j = 0; j != m.m_columns; ++j)
			for (int k = 0; k != m_columns; ++k)
				temp.m_matrix[i][j] += m_matrix[i][k] * m.m_matrix[k][j];
	return temp;
}

Matrix Matrix::operator*(int value)
{
	Matrix temp(m_rows, m_columns);
	for (int i = 0; i != m_rows; ++i)
		for (int j = 0; j != m_columns; ++j)
			m_matrix[i][j] *= value;
	return temp;
}

//Matrix operator*(int value, Matrix &m)
//{
//	return (m * value);
//}



Matrix &Matrix::operator*=(int value)
{
	*this * value;
	return *this;
}
//
//double calculateDeterminant(Matrix &m)
//{
//
//}


int main()
{
	std::vector<double> v1 = { 1.0, 2.3, 4.4, 4.3, 2.8, 5.4 };
	std::vector<double> v2 = { 2.0, 3.3, 5.4, 5.3, 3.8, 6.4 };
	Matrix mat(2, 3, v1);
	//Matrix mat2(3, 2, v2);
	//Matrix mat3(2, 2);
	Matrix ms(mat, 1, 1);
	//mat.print();
	ms.print();
	//mat *= 5;

	system("pause");
}