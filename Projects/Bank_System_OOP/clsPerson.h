#pragma once

#include <iostream>
#include<string>

using namespace std;



class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Phone, string Email) {

		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}
	// get

	string  GetFirstName() {

		return _FirstName;

	}

	void setFirstName(string FirstName) {

		 _FirstName = FirstName;

	}

	__declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

	
	// get 

	string  GetLastName() {

		return _LastName;

	}

	void setLastName(string LastName) {

		_LastName = LastName;

	}

	__declspec(property(get = GetLastName, put = setLastName)) string LastName;

	
	// get 

	string  GetEmail() {

		return _Email;

	}

	void setEmail(string Email) {

		_Email = Email;

	}

	__declspec(property(get = GetEmail, put = setEmail)) string Email;


	// get 

	string  GetPhone() {

		return _Phone;

	}

	void setPhone(string Phone) {

		_Phone = Phone;

	}

	__declspec(property(get = GetPhone, put = setPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";

	}
};

