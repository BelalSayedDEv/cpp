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
			arr[i][j] = randnumber(1, 10);
		}
	}
}

bool issparce(int arr[3][3], int row = 3, int col = 3) {

	int counterof0 = 0;
	int counterofnumber = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				counterof0++;
			}
			else
			{
				counterofnumber++;
			}
		}
	}
	if (counterof0 < counterofnumber) {
		return false;
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
	int arr1[3][3], row = 3, col = 3;
	fillarray(arr1);
	cout << "matrix one : " << endl;
	printarray(arr1);
	cout << "------------------" << endl;
	int Matrix1[3][3] = { {0,0,12},{0,0,1},{0,0,9} };
	printarray(Matrix1);
	if (issparce(Matrix1))
	{
		cout << "Yes: It's Sparce" << endl;
	}
	else
	{
		cout << "No: It's NOt Sparce" << endl;
	}
	
}

