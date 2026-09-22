#include <iostream>
using namespace std;



struct stperson
{
    string firstname;
    string lastname;
    int age;
    string phone;
};

void readperson(stperson &person) {

    cout << "pelease enter the firstname " << endl;
    cin >> person.firstname;

    cout << "pelease enter the lastname " << endl;
    cin >> person.lastname;

    cout << "pelease enter  age " << endl;
    cin >> person.age;

    cout << "pelease enter phone " << endl;
    cin >> person.phone;

}

void printperson(stperson person) {

    cout << "FirstName : " << person.firstname << endl;

    cout << "LastName  : " << person.lastname << endl;
    
    cout << "Age  : " << person.age << endl;
    
    cout << "Phone  : " << person.phone << endl;
}


/*  cout << "enter the Firstname of person 1 " << endl;
         cin >> arr[i].firstname;
         cout << "enter the Lastname of person 1 " << endl;
         cin >> arr[i].lastname;
         cout << "enter the Age of person 1 " << endl;
         cin >> arr[i].age;
         cout << "enter the Phone of person 1 " << endl;
         cin >> arr[i].phone;*/



void readarrayofperson(stperson arr[100], int &maxnumber)
{
    cout << "please enter the number of persons you want to enter " << endl;

    cin >> maxnumber;

    for (int i = 0; i <= maxnumber - 1; i++)
    {
        cout << endl;
        cout << "information of person's " << i+1 << endl;
        readperson(arr[i]);
    }
}


/* cout << "FirstName 1 : " << arr[i].firstname;
 cout << "LastName 1 : " << arr[i].lastname;
 cout << "Age 1 : " << arr[i].age;
 cout << "Phone 1 : " << arr[i].phone;*/





void parrayofperson(stperson arr[100], int maxnumber) {

    for (int i = 0; i <= maxnumber-1; i++)
    {
        cout << endl;
        cout << "*************************************\n";
        cout << "Person " << i + 1 << " Info" <<endl;
        cout << "*************************************\n";

        printperson(arr[i]);
         
    }
}

int main()
{
    
    stperson person[100];
    int maxnumber;
    readarrayofperson(person, maxnumber);
    parrayofperson(person, maxnumber);
}

