
#include <iostream>
using namespace std;

struct stpiggybankcontent
{
    int penny, Nicle, Dime, Quarter, Dollar;
};
stpiggybankcontent readpiggybackcontent() {
    stpiggybankcontent piggybankcontent;
    cout << "please enter number of penny " << endl;
    cin >> piggybankcontent.penny;
    cout << "please enter number of nicle " << endl;
    cin >> piggybankcontent.Nicle;
    cout << "please enter number of dime " << endl;
    cin >> piggybankcontent.Dime;
    cout << "please enter number of quarter " << endl;
    cin >> piggybankcontent.Quarter;
    cout << "please enter number of dollar" << endl;
    cin >> piggybankcontent.Dollar;

    return piggybankcontent;
}

int clctotalpennies(stpiggybankcontent piggybankcontent) {
    int totalpennis = 0;
    totalpennis = piggybankcontent.penny * 1 + piggybankcontent.Nicle * 5 + piggybankcontent.Dime * 10 + piggybankcontent.Quarter * 25 + piggybankcontent.Dollar * 100;
    return totalpennis;
}
int main()
{
    int totalpennis =clctotalpennies( readpiggybackcontent());
    cout << "the total pennis is : " << totalpennis << endl;
    cout << "the total dollars is : " << (float)totalpennis / 100 << endl;
}

