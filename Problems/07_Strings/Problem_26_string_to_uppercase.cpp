
#include <iostream>
#include<cctype>
#include<string>


using namespace std;

string readstring() {

    string name;
    cout << "please enter your name : " << endl;
    getline(cin, name);
    return name;
}

string convertupper(string s) {
    
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }

    return s;
}

int main()
{
    string s;
    s = readstring();
    cout << "string before converting : " << endl;
    cout << endl << s << endl;
    cout << "-------------------------------" << endl;
    cout << "string after converting : " << endl;
    s = convertupper(s);
    cout << endl  << s << endl;
    cout << "-------------------------------" << endl;
}
