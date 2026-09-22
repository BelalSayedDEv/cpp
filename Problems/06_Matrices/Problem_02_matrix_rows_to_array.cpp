#include<string>
#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;

int randomnumber(int from, int to) {
    return rand() % (to - from + 1) + from;
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

int sumofrow(int arr[3][3], int rowIndex, int col) {
    int sumofrow = 0;
    for (int j = 0; j < col; j++) {
        sumofrow += arr[rowIndex][j];
    }
    return sumofrow;
}

void sumation(int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        cout << "Sum of Row " << i + 1 << " = " << sumofrow(arr, i, col) << endl;
    }
}

int main()
{
    srand(time(0));
    int arr[3][3];
    fillelement(arr, 3, 3);
    printelement(arr, 3, 3);
    sumation(arr, 3, 3);
}
