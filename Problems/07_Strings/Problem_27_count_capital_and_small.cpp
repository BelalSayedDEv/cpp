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
char readcharachter() {

    char name;
    cout << "please enter your name : " << endl;
    cin >> name;
    return name;
}

char convertupper( char s) {
   

   return (isupper(s) ? tolower(s) : toupper(s));
    
}

string inverttheletter(string s) {

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = convertupper(s[i]);
    }
    return s;
}

void countcapitalsmall(string s,int &countcapital ,int &countsmall) {
     
    countcapital = 0;
    countsmall = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isspace(s[i])) {
            continue;
        }
        else
        {
            (isupper(s[i])) ? countcapital++ : countsmall++;
        }
        
    }

}

/***************************       this on problem has(27, 28,29)       ************************/

int main()
{
    string s;
    int countcapital = 0, countsmall = 0;
    s = readstring();
    countcapitalsmall(s, countcapital, countsmall);
    cout << "\nstring before inverted : " << endl;
    cout << endl << s << endl;
    cout << "String Length = " << s.length() << endl;
    cout << "Capital Letters Count = " << countcapital << endl;
    cout << "Small Letters Count = " << countsmall << endl;

}
