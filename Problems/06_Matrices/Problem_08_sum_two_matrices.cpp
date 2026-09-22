#include <iostream>
#include<time.h>
#include<limits>
#include<iomanip>

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
			arr[i][j] = randnumber(1,100);
		}
	}
}
void sumtwoarray(int arr1[3][3], int arr2[3][3], int arr3[3][3], int row = 3, int col = 3) {
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr3[i][j] = arr1[i][j]+ arr2[i][j];
		}
	}

}
void printarray(int arr[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout <<setw(5) << arr[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], arr3[3][3], row = 3, col = 3;
	fillarray(arr1);
	fillarray(arr2);
	sumtwoarray(arr1, arr2, arr3);
	cout << "matrix one : " << endl;
	printarray(arr1);
	cout << "--------------" << endl;
	cout << "matrix two : " << endl;
	printarray(arr2);
	cout << "--------------" << endl;
	cout << "matrix of sumation : " << endl;
	printarray(arr3);
	cout << "--------------" << endl;
}


