
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

void printsumationofcoll(int arr[3][3], int row, int col) {

    for (int i = 0; i < col; i++)
    {
        cout << "sum of col " << i + 1  <<" = " << sumcolls(arr, row, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    fillelement(arr, 3, 3);
    cout << "\nthis element of array :\n" << endl;
    printelement(arr, 3, 3);
    cout << "\nthis sum of all col :\n" << endl;
    printsumationofcoll(arr, 3, 3);

}

