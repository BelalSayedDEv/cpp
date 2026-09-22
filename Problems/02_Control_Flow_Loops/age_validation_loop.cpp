
#include <iostream>

using namespace std;




int readage() {
    int age;
    cout << "please enter your age " << endl;
    cin >> age;
    return age;
}

bool clcage(int age ,int from ,int to) {
    return (bool)(age >= from && age <= to);
}


void printage(int age) {

    if (clcage(age, 18, 45))
        cout << age << "  is validate number " << endl;
    else 
        while (clcage(age, 18, 45) ==0) {
            cout << "wrong number !  please enter other number " << endl;
            cin >> age;
        }  
    
}



int main()
{
    printage(readage());
}


