#include <iostream>
#include<cctype>
#include<string>


using namespace std;


string readstring() {
    string name;
    cout << "enter your string" << endl;
    getline(cin, name);
    return name;
}
char readchar() {
    char name;
    cout << "enter your charchter" << endl;
    cin >> name;
    return name;
}

void printstring(string s ,char input ,int &counter) {
 
    counter = 0 ;
    bool found = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (input == s[i])
        {
            counter++;

            found = true;
        }
    }
    if (!found) {
        cout << "character is not found" << endl;
    }
}


int main()
{
    string s = readstring();
    char c = readchar();
    int counter = 0;
    printstring(s, c, counter);
    cout << "\nletter ' " << c << "' count = " << counter << endl;

}


