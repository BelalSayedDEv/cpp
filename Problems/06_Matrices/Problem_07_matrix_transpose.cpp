

#include <iostream>
using namespace std;

void fillarray(int arr[3][3], int row = 3, int col = 3) {
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			counter++;
			arr[i][j] = counter;
		}
	}
}
void printarray(int arr[3][3], int row = 3, int col = 3) {
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fillcloumm(int copyarr[3][3], int arr[3][3], int row = 3, int col = 3) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			copyarr[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int arr[3][3],coppyarr[3][3], row = 3, col = 3;
	fillarray(arr);
	printarray(arr);
	cout << "-------------------\n";
	fillcloumm(coppyarr, arr);
	printarray(coppyarr);
	cout << "-------------------";
}


