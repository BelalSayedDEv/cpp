
#include <iostream>
using namespace std;

int readicons(int &penny,int &Nicle,int &Dime,int &Quarter,int &Dollar) {
   
    cout << "please enter number of penny " << endl;
    cin >> penny;
    cout << "please enter number of nicle " << endl;
    cin >> Nicle;
    cout << "please enter number of dime" << endl;
    cin >> Dime;
    cout << "please enter number of quarter " << endl;
    cin >> Quarter;
    cout << "please enter number of dollar" << endl;
    cin >> Dollar;

    return penny, Nicle, Dime, Quarter, Dollar;

}

int clcpennies(int penny, int nicle, int dime, int quarter, int dollar) {
    int result;
    result = penny * 1 + nicle * 5 + dime * 10 + quarter * 25 + dollar * 100;
    return result;
}

float clcdollar(int result){

    return (float)result / 100;

}


int main()
{
    int penny, Nicle, Dime, Quarter, Dollar;
    readicons(penny, Nicle, Dime, Quarter, Dollar);
    cout << "the total pennis is : " << clcpennies(penny, Nicle, Dime, Quarter, Dollar) << endl;
    cout << "the total dollars is : " << clcdollar(clcpennies(penny, Nicle, Dime, Quarter, Dollar)) << endl;

}


