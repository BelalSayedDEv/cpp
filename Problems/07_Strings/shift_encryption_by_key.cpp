#include <iostream>
using namespace std;
#include <string>

string readpin(string message)
{
    string text;
    cout << message << endl;
    getline(cin, text );
    return text;
}


string encryption(string text,int keyencryption) {

    for (int i = 0 ; i <= text.length(); i++) {

        text[i] = char( (int)text[i]+ keyencryption);

    }
    return text;
}

string decryption(string text,int keyencryption) {

    for (int i = 0 ; i <= text.length(); i++) {

        text[i] = char( (int)text[i] - keyencryption);

    }
    return text;
}





int main()
{
    int encryptionkey = 2;
    string  text = readpin("please enter pin number ");
    string textafterencryption = encryption(text, encryptionkey);
    string textafterdecryption = decryption (textafterencryption, encryptionkey);

    cout << "text before encryption " << text << endl;
    cout << "text after encryption " << textafterencryption << endl;
    cout << "text after decryption " << textafterdecryption << endl;

    return 0;
}