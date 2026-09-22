#include <iostream>
#include<time.h>
#include<limits>
#include<iomanip>
#include<cmath>
using namespace std;

int readnumber() {
	int number;
	cout << "please enter a number : " << endl;
	cout << "number : ";
	cin >> number;
	return number;
}
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
			arr[i][j] = randnumber(1, 100);
		}
	}
}


bool isnumberinarray(int number, int arr1[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr1[i][j] == number) {
				return true;
			}

		}
	}
	return false;
}

void printintersectednumber(int arr1[3][3], int arr2[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (isnumberinarray(arr1[i][j], arr2))
			{
				cout << setw(4) << arr1[i][j] << " ";
			}
		}
	}
}

int maxnumber(int arr[3][3], int row = 3, int col = 3) {
	
	int maxnumber = arr[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (maxnumber < arr[i][j]) {
				maxnumber = arr[i][j];
			}
		}
	}
	return maxnumber;
}

int minenumber(int arr[3][3], int row = 3, int col = 3) {

	int minnumber = arr[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (minnumber > arr[i][j]) {
				minnumber = arr[i][j];
			}
		}
	}
	return minnumber;
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

	int arr2[3][3], arr1[3][3], row = 3, col = 3;
	fillarray(arr1);
	fillarray(arr2);
	cout << "matrix one : " << endl;
	printarray(arr1);
	cout << "------------------" << endl;
	cout << "minimum Number is : " << minenumber(arr1) << endl;
	cout << "------------------" << endl;
	cout << "Max Number is : " << maxnumber(arr1) << endl;
	cout << "------------------" << endl;
}


