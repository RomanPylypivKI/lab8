#ifndef matrix_h__
#define matrix_h__
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
class Matrix
{
private:
	T** m_iArr;
	int size_row;
	int size_col;
public:
	//конструктор за замовчуванням
	Matrix();
	//конструктор з параметрами
	Matrix(int size_row_BuUser, int size_col_BuUser);
	//деструктор
	~Matrix();
	//перевантаження оператора виводу
	friend ostream& operator<< <>(ostream&, Matrix<T>&);
	//підрахунок нулів в матриці
	int count_null();
};
//конструктор за замовчуванням
template <class T>
Matrix<T>::Matrix()
{
	size_col = 0;
	size_row = 0;
	m_iArr = new T * [size_row];
	for (int i = 0; i < size_row; i++)
	{
		m_iArr[i] = new T[size_col];
		for (int j = 0; j < size_col; j++)
		{
			m_iArr[i][j] = 0;
		}
	}
}
//конструктор з параметрами
template <class T>
Matrix<T>::Matrix(int size_row_BuUser, int size_col_BuUser)
{
	size_row = size_col_BuUser;
	size_col = size_row_BuUser;
	m_iArr = new T * [size_row];
	for (int i = 0; i < size_row; i++)
	{
		m_iArr[i] = new T[size_col];
		for (int j = 0; j < size_col; j++)
		{
			m_iArr[i][j] = 0;
		}
	}
	cout << "Matrix for random enter - 1\nMatrix for user enter - 2" << endl << "Please enter:";
	int l = 1;
	int b = 0;
	cin >> l;
	switch (l)
	{
	case 1:
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_col; j++)
			{
				m_iArr[i][j] = rand() % 99;
				b = rand() % 2;
				if (b == 0)
				{
					m_iArr[i][j] = -1 * m_iArr[i][j];
				}
			}
		break;
	case 2:
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_col; j++)
			{
				cout << "a[" << i << "]" << "[" << j << "]" << "=";
				cin >> m_iArr[i][j];
			}
		break;
	}
}
template<class T>
Matrix<T>::~Matrix()
{
	for (int j = 0; j < size_row; j++)
	{
		delete m_iArr[j];
	}
	delete[] m_iArr;
}
template <class T>
ostream& operator<<(ostream& output, Matrix<T>& matr)
{
	for (int i = 0; i < matr.size_row; i++)
	{
		for (int j = 0; j < matr.size_col; j++)
		{
			output << setw(5) << matr.m_iArr[i][j] << " ";
		}
		output << endl;
	}
	output << endl;
	return output;
}
template<class T>
int Matrix<T>::count_null()
{
	int res[99][99];
	int a = 0, b = 0;
	int x = size_row - 1, y = size_col - 1;
	for (int i = 0; i < size_row; i++)
	{
		for (int j = 0; j < size_col; j++)
		{
			if (m_iArr[i][j] >= 0)
			{
				res[a][b] = m_iArr[i][j];
				b++;
				if (b == size_col)
				{
					a++;
					b = 0;
				}
			}
			else if (m_iArr[i][j] < 0)
			{
				res[x][y] = m_iArr[i][j];
				if (y == 0)
				{
					x--;
					y = size_col;
				}
				y--;
			}
		}
	}
	cout << endl << endl << "Result:" << endl << endl;
	for (int i = 0; i < size_row; i++)
	{
		for (int j = 0; j < size_col; j++)
		{
			cout << setw(5) << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif