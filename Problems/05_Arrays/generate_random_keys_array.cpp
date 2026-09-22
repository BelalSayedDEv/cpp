#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

enum entypeletter {
    smallletter = 1,capitalletter = 2 ,signletter = 3, numberletter=4
};

int Randomnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
char createcharacter(entypeletter typeletter) {
    switch (typeletter)
    {
    case smallletter:
        return char(Randomnumber(97,122));
    case capitalletter:
        return char(Randomnumber(65, 90));
    case signletter:
        return char(Randomnumber(47, 64));
    case numberletter:
        return char(Randomnumber(48, 57));
    }
}

string smallkey(entypeletter typeletter,short length) {
    string smallkey = "";
    for (int i = 0; i < length; i++)
    {
        
        smallkey = smallkey + createcharacter(typeletter);
    }
    return smallkey;
}
string largekey() {
    string largekey = "";
   largekey = smallkey(entypeletter::capitalletter,4);
   largekey = largekey + "-" + smallkey(entypeletter::capitalletter,4);
   largekey = largekey + "-" + smallkey(entypeletter::capitalletter,4);
   largekey = largekey + "-" + smallkey(entypeletter::capitalletter,4);
   return largekey;
}

void fillarray(string arr[],int &arraylength) {

    cout << "please enter number of array : " << endl;
    cin >> arraylength;
    
    for (int i = 0; i < arraylength; i++)
    {
        arr[i] = largekey();
    }
}

void printfillarray(string arr[], int arraylength) {
    cout << "Array element : " << endl;
    for (int i = 0; i < arraylength; i++)
    {
        cout << "Array" << "[" << i << "] : ";
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    string arr[100];
    int arraylength;
    fillarray(arr, arraylength);
    printfillarray(arr, arraylength);
}
