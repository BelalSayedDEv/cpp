#include <iostream>
using namespace std;

int readage() {
    int age;
    cout << "please enter your age " << endl;
    cin >> age;
    return age;
}

bool clcage(int age, int from, int to) {
    return (bool)(age >= from && age <= to);
}

void printage( int age) {
    if (clcage(age, 18, 40))
        cout << "validate" << endl;
    else
        cout << "invalidate" << endl;
}

int main()
{
    
    printage(readage());



}

