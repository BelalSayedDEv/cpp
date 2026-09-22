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

bool existnumber(int number, int arr[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (number == arr[i][j]) {
				return true;
			}
		}
	}
	return false;
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
	int number = readnumber();
	if(existnumber(number,arr1)) {
		cout << "Yes: the number is found" << endl;
	}
	else
	{
		cout << "No: the number is not found" << endl;
	}

}

