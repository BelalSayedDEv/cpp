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

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int randomnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}

void fillorderdarray(int arr[],int arraylength) {
    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = i + 1;
    }

}

void printorderdarray(int arr[], int arraylength) {

    for (int  i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void shufflearray(int arr[], int arraylength) {
   
    for (int i = 0; i < arraylength; i++)
    {
        swap(arr[randomnumber(1,arraylength)-1] , arr[randomnumber(1, arraylength) - 1]);
    }
}

int main()
{
    int arr[100], arraylength;
    arraylength = readlength();
    fillorderdarray(arr, arraylength);

    cout << "Array element before shuffle : " << endl;
    printorderdarray(arr, arraylength);
    
    shufflearray(arr, arraylength);

    cout << "Array elemnt after shuffle : " << endl;
    printorderdarray(arr, arraylength);
}