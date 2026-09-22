
#include <iostream>
#include <string>
using namespace std;

int readnumber(string message)
{
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

bool isperfectnumber(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum = sum + i;
        }
    }

    return number == sum;
}

void printperfect(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (isperfectnumber(i) == true)
            cout << i << endl;
    }
}

int main()
{
    printperfect(readnumber("please enter the max number"));
}