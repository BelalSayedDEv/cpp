
#include <iostream>
using namespace std;


enum encolor
{
	red, blue,yello,clack,white
};

enum enstatues
{
	married,single
};

struct stadress
{
	string namestresst;
	string city;
	string country;

};

struct stcontactinfo
{
	string email;
	string phone;
	stadress adress;
};
struct person
{
	string name;
	int age;
	int salary;
	stcontactinfo contactinfo;

};
int main()
{
	person person1;

	person1.name = "belal sayed";
	person1.age = 15;
	person1.salary = 20000;
	person1.contactinfo.phone = "01277871581";
	person1.contactinfo.email = "pelalkak@gmail.com";
	person1.contactinfo.adress.country = "egypt";
	person1.contactinfo.adress.city = "alex";
	person1.contactinfo.adress.namestresst = "sadat";


	cout << "my name is :" << person1.name << endl;
	cout << "my age is :" << person1.age<< endl;
	cout << "my salary is :" << person1.salary << endl;
	cout << "my phone is :" << person1.contactinfo.phone << endl;
	cout << "my email is :" << person1.contactinfo.email << endl;
	cout << "my country is :" << person1.contactinfo.adress.country << endl;
	cout << "my city is :" << person1.contactinfo.adress.city << endl;
	cout << "my country is :" << person1.contactinfo.adress.country << endl;
	cout << "my street is :" << person1.contactinfo.adress.namestresst << endl;


}

