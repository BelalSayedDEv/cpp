#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int Randnumber(int from, int to) {

    int number = rand() % (to - from + 1) + from;
    return number;
}

void readarray(int arr[], int& arraylength) {

    do
    {
        cout << "please enter the length of array and which is positive number" << endl;
        cin >> arraylength;
    } while (arraylength <= 0);

    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randnumber(1, 100);
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

int getmax(int arr[], int arraylength) {
    int max_valu = arr[0];
        for (int i = 0; i < arraylength; i++)
        {
            if (max_valu < arr[i])
                max_valu = arr[i];
        }
        return max_valu;
}

int main()
{
    srand((unsigned) time(NULL));
    int arr[100], arraylength;
    readarray(arr, arraylength);
    printarry(arr, arraylength);
    cout << "Max Number is : " << getmax(arr, arraylength) << endl;
}

