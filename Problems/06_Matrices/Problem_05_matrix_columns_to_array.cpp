
#include <iostream>
#include<time.h>
#include<limits>
#include<iomanip>


using namespace std;

int randomnumber(int from, int to) {
    int number;
    number = rand() % (to - from + 1) + from;
    return number;
}

void fillelement(int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = randomnumber(1, 100);
        }
    }
}

void printelement(int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(6) << arr[i][j];
        }
        cout << endl;
    }
}

int sumcolls(int arr[3][3], int row, int col) {

    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += arr[i][col];
    }
    return sum;
}

void fillarryoned(int arr[3][3], int row, int col,int arr1[3]) {

    for (int i = 0; i < col; i++)
    {
       arr1[i]=  sumcolls(arr, row, i) ;
    }
}

void printarryoned( int arr1[10],int arrylength) {

    for (int i = 0; i < arrylength; i++)
    {
        cout << setw(6)<< arr1[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3],arr1[3];
    fillelement(arr, 3, 3);
    cout << "\nthis element of array :\n" << endl;
    printelement(arr, 3, 3);
    fillarryoned(arr, 3, 3, arr1);
    cout << "\nelement of one dimensial array :\n" << endl;
    printarryoned(arr1, 3);
   
}

