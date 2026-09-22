#include <iostream>
#include <string>

using namespace std;

int readnumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void printreverse(int number)
{
    int sum = 0;
    int reminder = 0;
    while (number > 0)
    {
        reminder = number % 10;
        number = number / 10;
        //    cout << reminder <<endl;
        sum = sum + reminder;
    }
    cout << "sum is :  " << sum << endl;
}

int main()
{
    printreverse(readnumber("please enter positive number "));
}