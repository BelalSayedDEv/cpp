#include<iostream>
using namespace std;
#include<string>

int readnumber(string message) {
    int number;
    do {
        cout << message<<endl;
        cin >> number;
    } while(number <=0);
    return number;
}

void makepattern(int number) {
    for (int i = number; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cout << i ;
        }
        cout << endl;
    }

}
int main()
{    
    makepattern(readnumber("please enter positive number"));
    return 0;
}