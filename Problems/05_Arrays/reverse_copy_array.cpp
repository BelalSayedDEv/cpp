#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;

int readlength() {
    int number;
    cout << "please enter the length of array" << endl;
    cin >> number;
    return number;
}

int randomnumber(int from, int to) {

    int number = rand() % (to - from + 1) + from;
    return number;
}

void fillorderdarray(int arr[], int &arraylength) {
        
    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = randomnumber(1, 100);
    }

}

void copingarray(int arr1[], int arr2[], int arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        arr2[i] = arr1[arraylength - 1 - i];
    }
}

void printorderdarray(int arr[], int arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void printcopingarray(int arr2[], int arraylength) {
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr1[100], arr2[100], arraylength;
    arraylength = readlength();
    fillorderdarray(arr1, arraylength);
    copingarray(arr1, arr2, arraylength);

    cout << "Array 1 element : " << endl;
    printorderdarray(arr1, arraylength);

    cout << "Array 2 elements after coping array 1 in reversed order : " << endl;
    printcopingarray(arr2,arraylength);

}

