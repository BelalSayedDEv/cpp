#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int Randnumber(int from , int to ) {
    int number = rand() % (to - from + 1) + from;
    return number;
}

void fillarraynumber(int arr[], int &arraylength) {
    cout << "please enter the array length" << endl;
    cin >> arraylength;
    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randnumber(1, 100);
    }

}

void printarraynumber(int arr[], int arraylength) {

    cout << "the element of array is : ";
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumarray(int arr[], int arraylength) {
    int sum = 0;
    for (int i = 0; i < arraylength; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arraylength;
    fillarraynumber(arr, arraylength);
    printarraynumber(arr, arraylength);
    cout << "\nAverage of all number is : " << (float)sumarray(arr, arraylength) / arraylength << endl;
}


