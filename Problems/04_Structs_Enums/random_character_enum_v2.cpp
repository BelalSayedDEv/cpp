#include <iostream>
#include<string>

using namespace std;

int Randomnumber(int from,int to ) 
{
    char number = rand() % (to - from + 1) + from;
    return number;
}

enum enchartype
{
    smallletter = 1 ,capitalletter = 2,spcialchar = 3,number = 4 
};


char printchar(enchartype chartype) {
    switch (chartype)
    {
    case enchartype::smallletter:
        return char(Randomnumber(97, 122));
        break;
    case enchartype::capitalletter:
        return char(Randomnumber(65, 90));
        break;
    case enchartype::spcialchar:
        return char(Randomnumber(33, 47));
        break;
    case enchartype::number:
        return char(Randomnumber(48, 57));
        break;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "character is : " << printchar(enchartype::smallletter) << endl;
    cout << "character is : " << printchar(enchartype::capitalletter) << endl;
    cout << "character is : " << printchar(enchartype::spcialchar) << endl;
    cout << "character is : " << printchar(enchartype::number) << endl;
}

    