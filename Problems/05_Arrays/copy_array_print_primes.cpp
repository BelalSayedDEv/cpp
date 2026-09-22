#include <iostream>
#include <string>
#include<stdlib.h>
#include <ctime>
using namespace std;

int Randnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;

}

bool isprime(int number) {
    int m = round(number / 2);
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= m ; i++)
    {
        if (number % i == 0) {
            return false; 
        }

    }
    return true;

}

void fillarray(int arr[], int& arraylength){
    cout << "enter the length of array" << endl;
    cin >> arraylength;
    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randnumber(1, 100);
    }
}

void printfillarray(int arr[], int arraylength) {
    cout << "element of array is : ";
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copingarray(int copingarr[], int arr[], int arraylength) {
    int counter = 0;
    for (int i = 0; i < arraylength; i++)
    {
        copingarr[counter] = arr[i];
        counter++;
    }
}

void primincopingarray(int copingarr[], int arraylength) {
    cout << "prime numbers in array2 is : " << endl;

    for (int i = 0; i < arraylength; i++)
    {
        if (isprime(copingarr[i])) {
            cout << copingarr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arraylength;
    fillarray(arr, arraylength);
    printfillarray(arr, arraylength);
    copingarray(arr, arr2, arraylength);
    primincopingarray(arr2, arraylength);


}


