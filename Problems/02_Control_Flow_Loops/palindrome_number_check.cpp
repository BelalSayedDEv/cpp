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

int  reversenumber(int number )
{
    // int sum = 0;
    int before = number;
    int reminder = 0 , number2=0;
    while (number > 0)
    {
        reminder = number % 10;
        number = number / 10;
        number2 =number2*10 +reminder;
    }
  return  number2;   // cout << "sum is :  " << sum << endl;
}

bool palindrome(int number){
    return number == reversenumber(number);
    
}

int main(){
    
    if (palindrome(readnumber ("please enter positive number")))
            cout <<  " yes, it is plainrom number "<<endl;
     else
             cout << "no, it is not plainrom number "<<endl;
            
}