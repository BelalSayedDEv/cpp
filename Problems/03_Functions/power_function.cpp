
#include <iostream>
using namespace std;


int readbase() {
    int base;
    cout << "please enter your base " << endl;
    cin >> base;
    return base;
}

int readpower() {
    int power;
    cout << "please enter the power " << endl;
    cin >> power;
    return power;
}

int printpowerofnumber(int base, int power) {
    int result = 1 ;
    if (power == 0) {
        return 1;
    }
    for (int i = 0; i < power; i++)
    {
        result = base * result;
    } 
    return result;
}

int main()
{
    cout << "result is " << printpowerofnumber(readbase(), readpower());
}


