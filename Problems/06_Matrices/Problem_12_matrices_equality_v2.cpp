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

bool isquality(int arr1[3][3], int arr2[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				return false;
			}
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
	cout << "\nmatrix two : " << endl;
	printarray(arr2);

	if (isquality(arr1, arr2))
	{
		cout << "\nYes: martices are equal." << endl;
	}
	else {
		cout << "\nNo: martices are NOT equal." << endl;
	}


}
