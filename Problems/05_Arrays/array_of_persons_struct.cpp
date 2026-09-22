
#include <iostream>
using namespace std;


struct stperson {
    string firstname;
    string lastname;
    int age;
    string phone;
};
   
void readperson(stperson &person) {
    cout << "please enter your firstname \n";
    cin >> person.firstname;
    cout << "please enter your lastname" << endl;
    cin >> person.lastname;
    cout << "please enter your age \n";
    cin >> person.age;
    cout << "please enter your phone" << endl;
    cin >> person.phone;
}
void printperson(stperson person) {

    cout << "*****************************************" << endl;

    cout << "firstName   :" << person.firstname << endl;
    cout << "lastName    :" << person.lastname << endl;
    cout << "Age         :" << person.age << endl;
    cout << "phone       :" << person.phone << endl;

    cout << "*****************************************" << endl;


}



int main()
{
    stperson persones[2];
    readperson(persones[0]);
    readperson(persones[1]);
    printperson(persones[0]);
    printperson(persones[1]);

}


