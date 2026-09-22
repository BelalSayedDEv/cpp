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

int printreverse(int number )
{
    // int sum = 0;
    int reminder = 0 , times = 0;
    while (number > 0)
    {
        reminder = number % 10;
        number = number / 10;
        times = times*10+reminder;
    }
    
    return times;
    // cout << "sum is :  " << sum << endl;
}

int main(){
   cout<< "the reverse is : "<< printreverse(readnumber ("please enter positive number"));
}