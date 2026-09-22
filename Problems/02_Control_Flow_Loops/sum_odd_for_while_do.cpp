

#include <iostream>
using namespace std;

int readnumber() {
    int limit_number;
    cout << "please enter the limit number " << endl;
    cin >> limit_number;
    return limit_number;
}

void printnumberusingforloop (int limit){


    cout << "sum of odd numbers between 1 to n using for loop " << endl;
    int sum =0;
    for (int i = 1; i <= limit; i++)
    {
        if (i % 2 != 0) {
            sum = i + sum;
        }
    }
    cout << "sum of odd numbers between  1 to " << limit << " is :" << sum << endl;

}

void printnumbersusingwhileloop(int limit) {

    cout << "sum of odd numbers between 1 to n using while loop " << endl;
    int counter = 0;
    int sum = 0;
    while (counter <= limit) {

        if (counter % 2 != 0) {
        
            sum = counter + sum;
        
        }


        counter++;
    }
    cout << "sum of odd numbers between  1 to " << limit << " is :" << sum << endl;
}


void printnumbersusingdowhile(int limit) {
    cout << "sum of odd numbers between 1 to n using do while loop " << endl;
    int counter = 0;
    int sum = 0;

    do {
        if (counter % 2 != 0) {

            sum = counter + sum;

        }
        counter++;
    } while (counter <=limit);

    cout << "sum of odd numbers between  1 to " << limit << " is :" << sum << endl;
}

int main()
{
    
    printnumberusingforloop(readnumber());
    printnumbersusingwhileloop(readnumber());
    printnumbersusingdowhile(readnumber());
}

