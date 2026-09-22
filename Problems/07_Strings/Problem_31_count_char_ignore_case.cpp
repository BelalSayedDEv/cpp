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

int printstring(string s, char input , bool matchcase = true) {

  int  counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (matchcase) {
            if (input == s[i])
            {
                counter++;
               
            }
        }
        else
        {
            if (tolower(input) == tolower(s[i]) )
            {
                counter++;

            }
        }
    }
    return counter;
}


int main()
{
    int counter = 0 ,canycase = 0;
    string s = readstring();
    cout << s << endl;
    char c = readchar();
    printstring(s, c, counter);
    cout << "Letter '" << c << "' Count = " << printstring(s, c, true) << endl;
    cout << "Letter '" << char(tolower(c)) <<"' or ' "<< char (toupper(c)) <<"' " << "'Count = " << printstring(s, c, false) << endl;
}


