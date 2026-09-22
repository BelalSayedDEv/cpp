#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int readnumber(string message) {
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

int randomnumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void fillelement(int arr[3][3], int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = randomnumber(1, 100);
        }
    }
}

void printelemnt(int arr[3][3], int row, int cols) {
    cout << "\nMatrix elements:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int sumrow(int arr[3][3], int rowIndex, int cols) {
    int sumofrow = 0;
    for (int j = 0; j < cols; j++) {
        sumofrow += arr[rowIndex][j];
    }
    return sumofrow;
}

void printsumeachrow(int arr[3][3], int row, int cols) {
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (int i = 0; i < row; i++) {
        cout << "Sum of row " << i + 1 << " = " << sumrow(arr, i, cols) << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3], row, col;

    row = readnumber("Enter number of rows (max 3): ");
    col = readnumber("Enter number of columns (max 3): ");

    fillelement(arr, row, col);
    printelemnt(arr, row, col);
    printsumeachrow(arr, row, col);
}
