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
			arr[i][j] = randnumber(1, 100);
		}
	}
}

int sumofarry(int arr[3][3], int row = 3, int col = 3) {

	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
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

	cout << "\nsum of Matrix1 is  : " << sumofarry(arr1) << endl;

}
