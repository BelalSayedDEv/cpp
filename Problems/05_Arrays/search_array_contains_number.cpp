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
        arr[i] = Randomnumber(1, 100);
    }
}

void printfillarray(int arr[], int arraylength) {
    cout << "Array element : " << endl;
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int readserchnumber() {
    int searchnumber;
    cout << "\nplease enter a number to search for ?" << endl;
    cin >> searchnumber;
    return searchnumber;
}



int searcharray(int arr1[], int arraylength, int searchnumbre) {

    for (int i = 0; i < arraylength; i++)
    {
        if (arr1[i] == searchnumbre) {
            return i;
        }
    }
    return -1;
  
}

void printsearchresult(int arr1[],int arraylength,int searchnumber )
{
    if (searcharray(arr1,arraylength,searchnumber) != -1) {
        cout << "\nNumber you are looking for is : " << searchnumber << endl;
        cout << "the number found at position : " << searcharray(arr1, arraylength, searchnumber) << endl;
        cout << "the number found its order : " << searcharray(arr1, arraylength, searchnumber) + 1 << endl;
    }
    else
    {
        cout << "\nNumber you are looking for is : " << searchnumber << endl;
        cout << "the number is not found:-(" << endl;
    }

}

bool isnumberinarray(int arr1[], int arraylength, int searchnumber) {
    return searcharray(arr1, arraylength, searchnumber) != -1;
 }

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arraylength = readlength();
    fillarray(arr, arraylength);
    printfillarray(arr, arraylength);
    int searchnumber = readserchnumber();
   // printsearchresult(arr, arraylength,searchnumber);
    cout << "\nNumber you are looking for is : " << searchnumber << endl;

    if (!isnumberinarray(arr, arraylength, searchnumber)) {
        cout << "no,the number is not found" << endl;
    }
    else {
        cout << "yes,the number is  found" << endl;
    }
}
