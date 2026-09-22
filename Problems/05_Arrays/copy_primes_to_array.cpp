#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int Randnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}


bool isprime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0) {
            return false;
        }
      
    }
    return true;
}
void fillarraynumber(int arr[], int& arraylength){
    cout << "please enter the array length" << endl;
    cin >> arraylength;

    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = Randnumber(1, 100);
    }

}

void printarraynumber(int arr[], int arraylength) {

    cout << "the element of array is : " << endl;
    for (int i = 0; i < arraylength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copingarray(int copingarr[], int arr[], int arraylength) {

    for (int i = 0; i < arraylength; i++)
    {
        if (isprime(arr[i])) {
            copingarr[i] = arr[i];
        }
    }
}
void printcopingarry(int copingarr[], int arraylength) {

    cout << "element of array (just prime number : )";
    for (int i = 0; i < arraylength; i++)
    {
        cout << copingarr[i] << " ";
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arraylength, copied_array[100];
    fillarraynumber(arr, arraylength);
    printarraynumber(arr, arraylength);
    copingarray(copied_array, arr, arraylength);
    printcopingarry(copied_array, arraylength);



}