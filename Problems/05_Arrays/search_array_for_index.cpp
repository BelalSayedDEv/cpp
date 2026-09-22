#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;


int Randomnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
int readlength() {
    int arraylength;
    cout << "please enter number of array : " << endl;
    cin >> arraylength;
    return arraylength;
}

void fillarray(int arr[], int& arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randomnumber(1,100);
    }
}

void printfillarray(int arr[], int arraylength) {
    cout << "Array element : " << endl;
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}

int readserchnumber() {
    int searchnumber;
    cout << "please enter a number to search for ?" << endl;
    cin >> searchnumber;
    return searchnumber;
}

void searcharray(int arr1[], int arraylength, int searchnumbre) {
    for (int i = 0; i < arraylength; i++)
    {
        if (arr1[i] == searchnumbre) {
            cout << "Number you are looking for is : " << searcharray;
            cout << "the number found at position : " << i << endl;
            cout << "the number found its order : " << i + 1 << endl;
        }
        else
        {
            cout << "Number you are looking for is : " << searcharray;
            cout << "the number is not found :-(" << endl;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arraylength;
    fillarray(arr, arraylength);
    printfillarray(arr, arraylength);
    searcharray(arr,arraylength,readserchnumber());
}
