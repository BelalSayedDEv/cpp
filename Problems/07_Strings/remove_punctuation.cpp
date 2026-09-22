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

string removepunct(string s) {
    string word="";
    for(char &c: s)
    {
        if (!ispunct(c)) {
            word += c;
        }
    }
return word;
}

string removepunctfromstring(string s) {
    string word = "";
    vector<string> vstring = split(s, " ");

    for (string &st : vstring) {
        
        word += removepunct(st) + " ";
    }

    if (!word.empty())
        word = word.substr(0, word.length() - 1);
        
    return word;
}

int main() {
    string s = readstring("Enter your sentence:");
    cout << "\nSentance Before remove punctuation :\n";
    cout << s << endl;

    cout << "\nnSentance After remove punctuation:\n";
    cout << removepunctfromstring(s) << endl;
}