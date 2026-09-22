
#include <iostream>
using namespace std;

int readnumbers(int &base ,int &power) {
    
    cout << "please enter the base" << endl;
    cin >> base;
    cout << "please enter the base" << endl;
    cin >> power;
    return base, power;
}

int clcpowers(int base,int power) {


    if (power == 0)
    {
        return 1;
    }
    int resulte = 1;
    for (int i = 0; i < power; i++)
    {
        resulte *= base;
    }
    return resulte;

}




int main()
{
    int base , power ;
    readnumbers(base,power);
   cout<<"power of "<< power << " to " << "number " << base << " is " << clcpowers(base, power);
    
}

