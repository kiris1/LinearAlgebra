#pragma once

#include <iostream>
#include <vector>

class Matrix
{
private:
	int m_rows;
	int m_columns;
	std::vector<std::vector<double>> m_matrix;
public:
	Matrix (int rows, int columns)
		: m_rows(rows), m_columns(columns)
	{}

	Matrix(int rows, int columns, std::vector<double> data)
		: m_rows(rows), m_columns(columns)
	{
		if (data.size() != rows * columns)
		{
			std::cout << "Number of input element is not equal to matrix size.\n";
			return;
		}
		for (int i = 0; i != m_matrix.size(); ++i)
			for (int j = 0; j != m_matrix[i].size(); ++j)
				m_matrix[i][j] = data[i * m_matrix.size() + j];
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
};
