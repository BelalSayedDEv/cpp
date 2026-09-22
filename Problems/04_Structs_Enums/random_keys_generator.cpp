
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int randnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}

int readnumber() {
    int number;
    do
    {
        cout << "please enter postive number " << endl;
        cin >> number;
    } while (number < 0);
    return number;
}

enum enchartype
{
    smallletter=1,capitalletter=2,signletter=3,numerletter=4
};

char printcharater(enchartype chartype) {
    switch (chartype)
    {
    case enchartype::smallletter:
        return char(randnumber(97, 122));
    case enchartype::capitalletter:
        return char(randnumber(65, 90));
    case enchartype::signletter:
        return char(randnumber(33, 47));
    case enchartype::numerletter:
        return char(randnumber(48, 57));
    }
}

char Getcharacter(enchartype chartype) {
    return char(printcharater(enchartype::capitalletter));
}

string smallkey(enchartype chartype,int length) {

    string smallkey = "";
    for (int i = 0; i < length; i++)
    {
        smallkey = smallkey + Getcharacter(chartype);
    }
    return smallkey;
}

string largekey() {

    string largekey = "";
    largekey = smallkey(enchartype::capitalletter, 4) + "-";
    largekey = largekey + smallkey(enchartype::capitalletter, 4) + "-";
    largekey = largekey + smallkey(enchartype::capitalletter, 4) + "-";
    largekey = largekey + smallkey(enchartype::capitalletter, 4);
    return largekey;


}

void printlargekey(int number) {
    for (int i = 1; i <= number ; i++)
    {
        cout << "Key "<<"["<<i<<"] : " << largekey() << endl;
    }
}






int main()
{
    printlargekey(readnumber());
}

