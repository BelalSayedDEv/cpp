#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readstring() {
    string name;
    cout << "enter your name: ";
    getline(cin, name);
    return name;
}


string left_trim(string s) {

    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ')
        {
            return(s.substr(i,s.length()-i));
        }
    }
    return "";
}


string right_trim(string s) {

    for(int i = s.length()-1; i >=0; i--) {
        if(s[i] != ' ')
        {
            return(s.substr(0,i+1));
        }
    }
    return "";
}
string trim(string s) {

    return left_trim(right_trim(s));
}

int main() {

    string s = readstring();
//s = left_trim(s);
//s = right_trim(s);
    s =trim(s);
    cout << "'"<< s << "'" << endl;

    return 0;
}