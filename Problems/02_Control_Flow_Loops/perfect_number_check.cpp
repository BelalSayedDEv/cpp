#include <iostream>

using namespace std;

int readnumber()
{
    int number;
    cout << "please enter the max number " << endl;
    cin >> number;
    return number;
}
enum enperfectnumber
{

    perfect = 1,
    notperfect = 2

};

enperfectnumber checkperfect(int number)
{
    int result = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0 && result <= number)
        {
            result = result + i;
        }
    }
    if (result == number)
        {
            return enperfectnumber::perfect;
        }
        else 
        {
            return enperfectnumber::notperfect;
        }
}

void printperfect(int number)
{
    if (checkperfect(number) == enperfectnumber::perfect)
    {
        cout << number << " is perfect number" << endl;
    }
    else
    {
        cout << number << " is not perfect number" << endl;
    }
}

int main()
{
    printperfect(readnumber());
}
