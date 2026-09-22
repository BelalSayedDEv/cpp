#include <iostream>
#include<string>

using namespace std;

int randomnumber(int from,int to ) {
    int number = rand() % (to - from + 1) + from;
    return number;
}

enum enchartype {
    smallletter = 1, capitalletter = 2 ,signletter = 3 ,number = 4 
};

char printtype(enchartype chartype) {

    switch (chartype)
    {
    case  enchartype::smallletter:
    {
        return char(randomnumber(97, 122));
        break;
    }
    case enchartype::capitalletter:
    {
        return char(randomnumber(65, 90));
        break;
    }
    case enchartype::signletter:
    {
        return char(randomnumber(33, 47));
        break;
    }
    case enchartype::number:
    {
        return char(randomnumber(48, 57));
        break;
    }
    };
}

int main()
{
    srand((unsigned)time(NULL));

       cout << printtype(enchartype::smallletter) << endl;
       cout << printtype(enchartype::capitalletter) << endl;
       cout << printtype(enchartype::signletter) << endl;
       cout << printtype(enchartype::number) << endl;
}
