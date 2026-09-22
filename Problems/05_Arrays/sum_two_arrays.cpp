#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;


int Randomnumber(int from, int to) {

    int number = rand() % (to - from + 1) + from;
    return number;
}

int readarraylenght() {
    int arraylength;
    cout << "please enter the length of array" << endl;
    cin >> arraylength;
    return arraylength;
}

void fillarray(int arr[], int& arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randomnumber(1, 100);
    }

}

void printfillarray(int arr[], int& arraylength) {
    cout << "Array 1 Element : " << endl;

    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillfromsum(int arr1[], int arr2[], int arr3[], int arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}

void printfillfromsum(int arr3[], int arraylength) {
    cout << "Array 3 Element (sum array1 and array2): " << endl;
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}



int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arr3[100], arraylength;
    arraylength = readarraylenght();
    fillarray(arr1, arraylength);
    fillarray(arr2, arraylength);
    fillfromsum(arr1, arr2, arr3, arraylength);
    printfillarray(arr1, arraylength);
    printfillarray(arr2, arraylength);
    printfillfromsum(arr3, arraylength);

}

