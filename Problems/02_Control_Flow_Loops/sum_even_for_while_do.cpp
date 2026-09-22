
#include <iostream>
using namespace std;

int readnumber() {
    int limit_number;
    cout << "please enter the max number" << endl;
    cin >> limit_number;
    return limit_number;

}

enum entypenumber
{
    odd =0,even=1
};

entypenumber checktypenumber(int number) {
    if (number % 2 != 0)
        return entypenumber::odd;
    else
        return entypenumber::even;
}
void printsumofevennumbersusingfor(int limit) {
    int sum = 0;
    cout << "print even numbers using for loop" << endl;
    for (int i = 1; i <= limit; i++)
    {
        if (checktypenumber(i) == entypenumber::even) {
            sum = sum + i;
        }
      
    }
    cout << "sum of the even numbers between 1 to " << limit << " is " << sum << endl;
}

void printevennumbersusingwhile(int limit) {
    int sum = 0;
    cout << "print even numbers using for while" << endl;
    int counter = 0;
    while (counter <=limit) {
        if (checktypenumber(counter) == entypenumber::even) {
            sum = sum + counter;
        }
        counter++;
    }

    cout << "sum of the even numbers between 1 to " << limit << " is " << sum << endl;
}

void printevennumbersusingdowhile(int limit) {
    int counter = 0;
    int sum = 0;
    cout << "print even numbers using for do  while" << endl;
    do {
        if (checktypenumber(counter) == entypenumber::even) {
            sum = sum + counter;
        }
        counter++;

    } while (counter<=limit);
    
    cout << "sum of the even numbers between 1 to " << limit << " is " << sum << endl;
}


int main()
{
    int A = readnumber();
    printsumofevennumbersusingfor(A);
    printevennumbersusingwhile(A);
    printevennumbersusingdowhile(A);
}

