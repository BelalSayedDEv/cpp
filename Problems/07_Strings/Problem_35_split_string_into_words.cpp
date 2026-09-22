
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

void printoneword(string s) {
    
    string delim = " ";
    cout << "\n your string words  are : \n\n";
    short pos = 0;
    string sword;

    while ((pos = s.find(delim)) != std::string::npos)
    {
        sword = s.substr(0,pos);
        if (sword != "") {
            cout << sword << endl;
        }

        s.erase(0, pos + delim.length());
    }

    if (s != "") {

        cout << s << endl;
    }
}



int main()
{
    string s = readstring();
    printoneword(s);
}

