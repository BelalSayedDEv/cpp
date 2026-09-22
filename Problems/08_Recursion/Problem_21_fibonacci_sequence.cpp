#include<iomanip>
#include <iostream>

using namespace std;

int readnumber() {

    int number;
    cout << "enter your number ";
    cin >> number;
    return number;
}



void fillelement(int number,int arr[]) {

    for (int i = 0; i < number; i++)
    {
        if (i == 0 || i == 1) {
            arr[i] = 1;
        }
        else
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

}

void printarray(int number, int arr[]) {

    for (int i = 0; i < number; i++)
    {
        cout << setw(6) << arr[i];
    }
    cout << endl;

}

int main()
{
    int arr[100];
    int number = readnumber();
    fillelement(number,arr);
    cout << "--------------------------------" << endl;
    printarray(number , arr);
    cout << "--------------------------------" << endl;
}

