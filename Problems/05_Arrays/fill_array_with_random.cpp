#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int Randnumber(int from , int to) {

    int number = rand() % (to - from + 1) + from;
    return number;
}

void readarray(int arr[], int &arraylength) {
   
    do
    {
        cout << "please enter the length of array and which is positive number" << endl;
        cin >> arraylength;
    } while (arraylength < 0);
    for (int  i = 0; i < arraylength; i++)
    {
        arr[i] = Randnumber(1,100);


    }

}

void printarry(int arr[], int arraylength) {
    
    cout << "Array Elements : ";
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}



int main()
{
    int arr[100], arraylength;
    readarray(arr, arraylength);
    printarry(arr, arraylength);
}

