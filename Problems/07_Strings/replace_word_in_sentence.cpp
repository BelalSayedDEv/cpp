#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string readstring(string message) {
    string s;
    cout << message << endl;
    getline(cin, s);
    return s;
}

vector<string> split(string s, string delim) {
    vector<string> vstring;
    string word = "";
    size_t pos = s.find(delim);

    while (pos != string::npos) {
        word = s.substr(0, pos);
        if (word != "") {
            vstring.push_back(word);
        }
        s.erase(0, pos + delim.length());
        pos = s.find(delim);
    }

    if (s != "")
        vstring.push_back(s);

    return vstring;
}

string tolowerallstring(string s) {
    string word = "";
    for (char c : s)
        word += tolower(c);
    return word;
}

string replaceworupdate(string s, string oldstring, string newstring, bool matchcase) {
    string word = "";
    vector<string> vstring = split(s, " ");
    
    for (string &st : vstring) {
        if (matchcase && st == oldstring) {
            st = newstring;
        }
        else if (!matchcase && tolowerallstring(st) == tolowerallstring(oldstring)) {
            st = newstring;
        }
        word += st + " ";
    }

    if (!word.empty())
        word = word.substr(0, word.length() - 1);

    return word;
}

int main() {
    string s = readstring("Enter your sentence:");
    string oldstring = readstring("Enter old word:");
    string newstring = readstring("Enter new word:");

    cout << "\nCase-sensitive replace:\n";
    cout << replaceworupdate(s, oldstring, newstring, true) << endl;

    cout << "\nCase-insensitive replace:\n";
    cout << replaceworupdate(s, oldstring, newstring, false) << endl;
}