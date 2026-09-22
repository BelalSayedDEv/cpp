
#include <iostream>
#include <string>
#include<stdlib.h>


using namespace std;

int readchecknumber() {
	int number;
	do
	{
		
		cout << "please enter postive number which want to check " << endl;
		cin >> number;
	} while (number < 0);
	return number;
}



void readarray(int arr[], int  &arrlength) {

	cout << "please enter the length of array " << endl;
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++)
	{
		cout << "Element " << "[" << i + 1 << "] : ";
		cin >> arr[i];
	}

}

void printarray(int arr[] ,int n) {
	cout << "Original array: ";
	for (int i = 0; i < n ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int foundRepeatcounter(int arr[], int n , int checknumber) {
	
	int counter = 0;
	for (int  i = 0 ; i < n ; i++)
	{
		if (checknumber == arr[i])
		{
			counter++;
		}

	}
	return counter;
}

void printcounterrepeat(int counter , int checknumber) {
	cout << checknumber << " is repeated " << counter << " time(s)" << endl;
}

int main()
{
	int arr[100], arrlength;
	readarray(arr, arrlength);
	int checknumber = readchecknumber();
	printarray(arr, arrlength);
	printcounterrepeat(foundRepeatcounter(arr, arrlength, checknumber), checknumber);
	
}