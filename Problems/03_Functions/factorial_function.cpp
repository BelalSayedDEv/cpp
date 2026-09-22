

#include <iostream>
#include <string>
using namespace std;

int readnumber(string message) {
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}

int clcfactorial(int num) {
    int sum = 1;
    for (int i = num ; i >= 1 ; i--)
    {
        if (i > 0) {
            sum = sum * i;
        }
    }
    return sum;
}

void printsumation(int num) {
    cout << "factorial of " << num << " is " << clcfactorial(num) << endl;
}

int main()
{
    int A = readnumber("Please Enter Postive Number");
    printsumation(A);
}


