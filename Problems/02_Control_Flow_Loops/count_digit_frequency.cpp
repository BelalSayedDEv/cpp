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

int readbase(string message)
{
    int base;
    do
    {
        cout << message << endl;
        cin >> base;

    } while (base <= 0);
    return base;
}

int clcfrequancy(int number, int base)
{
    // int sum = 0;
    int reminder = 0, times = 0;
    while (number > 0)
    {
        reminder = number % 10;
        number = number / 10;
        if (reminder == base)
        {
            times++;
        }
    }

    return times;
    // cout << "sum is :  " << sum << endl;
}

int main()
{
    int number = readnumber("please enter positive number");
    int base = readbase("please enter positive base");
    cout << "Digit " << base << " Frequency is " << clcfrequancy(number, base) << ""
                                                                                  " Times(s)"
         << endl;
}