

#include <iostream>
using namespace std;
int main()
{
	int arr[3][3], row = 3,col=3;
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			counter++;
			arr[i][j] = counter;
		}
	}
		for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout<< arr[i][j] << " ";
		}
		cout << endl;
	}
}


