#include <iostream>
using namespace std;

int readnumber() {
    int number;
    cout << "please enter your number" << endl;
    cin >> number;
    return number;
}

int powerofnumber(int number, int power) {
    int result = 1;
    for (int  i = 0 ; i < power; i++)
    {
       result  = result * number;
    }
    return result;
}




void printthepowers(int number) {
    cout << "power  2 of " << number << " is " << powerofnumber(number, 2) << endl;
    cout << "power  3 of " << number << " is " << powerofnumber(number, 3) << endl;
    cout << "power  4 of " << number << " is " << powerofnumber(number, 4) << endl;

}



int main()
{
    int A = readnumber();
    printthepowers(A);
}

