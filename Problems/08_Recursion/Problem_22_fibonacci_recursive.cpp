
#include <iostream>
using namespace std;

int readnumber() {
    int number;
    cout << "please enter your number " << endl;
    cin >> number;
    return  number;
}


void printfibonaccinumber(int number,int prevzero , int prevone ) {

    int fibonacii = 0;
    if (number > 0)
    {
        fibonacii = prevone + prevzero;
        prevzero = prevone;
        prevone = fibonacii;
        cout << fibonacii << " ";

        printfibonaccinumber(number - 1, prevzero, prevone);
    }
}

int main()
{
    int number = readnumber();

    printfibonaccinumber(number,0,1);
}
