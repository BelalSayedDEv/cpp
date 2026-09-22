#include<iostream>
#include<time.h>
#include<limits>
#include<iomanip>


using namespace std;

int randomnumber(int from, int to) {
    int number;
    number =  rand() % (to - from + 1) + from;
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

int sumofrow(int arr[3][3], int row, int col) {
    int sum =0;
    for (int i = 0; i < col; i++)
    {
        sum += arr[row][i];
    }
    return sum;
}


void fillelemntarray(int arr[3][3], int row, int col,int arr1[10]) {

    for (int i = 0; i < row; i++)
    {
        arr1[i] =  sumofrow(arr, i, col) ;
    }

}
void printarray(int arr[10], int length) {

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}
//int sumofcols(int arr[3][3], int row, int col) {
//
//    int sum = 0;
//    for (int i = 0; i < row; i++)
//    {
//        sum += arr[i][col];
//    }
//    return sum;
//
//}

//void sumationofcols(int arr[3][3], int row, int col) {
//
//    for (int i = 0; i < col; i++)
//    {
//        cout << "Sum of row " << i + 1 << " = " << sumofcols(arr, row, i) << endl;
//    }
//
//
//}
//





int main()
{
    srand(  (unsigned)   time(NULL)  );
    int arr[3][3], arr1[10];
    fillelement(arr, 3, 3);
    cout << "==========================" << endl;
    cout << "array element is : " << endl;
    cout << "==========================" << endl;
    printelement(arr, 3, 3);
    /*cout << "==========================" << endl;
    cout << "sum of all rows is :" << endl;
    sumation(arr, 3, 3);
    cout << "==========================" << endl;
    cout << "sum of all cols is :" << endl;
    sumationofcols(arr, 3, 3);*/
    fillelemntarray(arr, 3, 3, arr1);
    cout << "==========================" << endl;
    printarray(arr1, 3);

}

