#include <iostream>
#include<time.h>
#include<limits>
#include<iomanip>
#include<cmath>
using namespace std;


int randnumber(int from, int to) {
	int number;
	number = rand() % (to - from + 1) + from;
	return number;
}

void fillarray(int arr[3][3], int row = 3, int col = 3) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = randnumber(1, 10);
		}
	}
}

bool isscalaber(int arr[3][3], int row = 3, int col = 3)
{
	int counter = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j && arr[i][j] != counter) || (i != j && arr[i][j] != 0))
				return false;
		}
	}
	return true;
}


void printarray(int arr[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(5) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], row = 3, col = 3;
	fillarray(arr1);
	fillarray(arr2);
	cout << "matrix one : " << endl;
	printarray(arr1);

	int Matrix1[3][3] = { {3,0,0},{0,3,0},{0,0,3} };
	printarray(Matrix1);
	if (isscalaber(Matrix1))
	{
		cout << "\nYes: matrix is scalar." << endl;
	}
	else
	{
		cout << "\nNo: matrix is not scalar." << endl;
	}
}

