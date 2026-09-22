

#include <iostream>
#include<string>
#include<cctype>



using namespace std;


string readstring() {
    string name;
    cout << "enter your name " << endl;
    getline(cin, name);
    return name;
}

string lowerfirstletterin(string s) {

    bool isfirstleeter = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] !=  ' ' && isfirstleeter)
        {
            s[i] = tolower(s[i]);
        }
        isfirstleeter = (s[i] == ' ') ? true : false;
    }
    return s;
}
int main()
{
    string s = readstring();
    cout << "string before lower the first letter" << endl;
    cout << s << endl;
     s= lowerfirstletterin(s);
    cout << "string after lower the first letter" << endl;
    cout << s << endl;
}
