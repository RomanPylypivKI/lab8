#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;
int main(void)
{
	int row, col;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter col: ";
	cin >> col;
	Matrix<int> m(row, col);
	cout << m;
	m.count_null();
	return 0;
}