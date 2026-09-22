

#include <iostream>

using namespace std;

class clsperson
{ 
private:
	int _id;
	string _Firstname;
	string _lastname;
	string _phone;
	string _email;

public:

	// set first name
	void setfirstname( string firstname) {
		_Firstname = firstname;
	}


	//get first name
	string Firstname() {
		return _Firstname;
	}

	// set last name
	void setlastname(string lastname) {
		_lastname = lastname;
	}
	// get last name
	string Lastname() {
		return _lastname;
	}

	// set phone number
	void setphone(string phone) {
		_phone = phone;
	}
	// get last name
	string Phone() {
		return _phone;
	}


	// set Email
	void setEmail(string email) {
		_email = email;
	}
	
	// get last name
	string Email() {
		return _email;
	}

	// print full name
	string FullName() {
		return _Firstname + " " + _lastname;
	}

	void SendEmail(string subject,string body) {

		cout << "\nthe following message sent successfully to email : " << _email << endl;
		cout << "Subject : " << subject << endl;
		cout << "Body : " << body << endl;
	}
	
	void SendSMS( string body) {

		cout << "\nhe following SMS sent successfully to phone : " << _phone << endl;
		cout << body << endl;
	}


	// constructor by defulte value
	clsperson(int id,string Firstname,string lastname,string phone,string email){
		
		_id = id;
		_Firstname = Firstname;
		_lastname = lastname;
		_phone = phone;
		_email = email;

	}
	void print() {

		cout << "\nInfo :" << endl;
		cout << "--------------------------------" << endl;
		cout << "ID       :" << _id << endl;
		cout << "FirstName:" << _Firstname << endl;
		cout << "LastName :" << _lastname << endl;
		cout << "FullName :" << FullName() << endl;
		cout << "Email    :" << _email << endl;
		cout << "Phone    :" << _phone << endl;
		cout << "--------------------------------" << endl;

	}


};








int main()
{
	
	clsperson person1(10, "belal", "sayed", "0121308514", "belalsayed@gmail.com");
	person1.print();

	person1.SendEmail("Hi","how are you");
	person1.SendSMS("how are you");


}

