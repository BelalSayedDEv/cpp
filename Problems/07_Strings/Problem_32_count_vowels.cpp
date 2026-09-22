#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string readstring() {
    string name;
    cout << "enter your string: " << endl;
    getline(cin, name);
    return name;
}

char readchar() {
    char name;
    cout << "enter your character: " << endl;
    cin >> name;
    return name;
}


bool isvowel(char c) {

    c = tolower(c);
    return ( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') );

}


int checkvowel(string s) {
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isvowel(s[i])) {
            counter++;
        }
    }
    return counter;
}

void printallvowel(string s) {

    for (int i = 0; i < s.length(); i++)
    {
        if (isvowel(s[i])) {
            cout  << s[i] <<"  ";
        }
    }

}

int main() {

    string s = readstring();
    cout << endl << s << endl;
    cout << "\nNumber of vowels is : " << checkvowel(s) << endl;
    cout << "Vowels in string are : ";
    printallvowel(s);
}

