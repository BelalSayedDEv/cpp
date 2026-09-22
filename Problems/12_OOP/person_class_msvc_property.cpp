
#include <iostream>


using namespace std;

class clsperson
{

private :

	string _FirstName;
	string _LastName;

	int _id = 10 ;
	

public:

	 // set perpority for first name 

	void setFirstname(string FirstName) {

		_FirstName = FirstName;
	}
	 
	// Get perpority for first name

	string getFirstname() {
		return _FirstName;
	}

	// set perpority for last name
	
	void setlastname(string lastname) {
		_LastName = lastname;

	}

	// Get perpority for first name
	string lastname() {
		return _LastName;
	}

	string fullname() {

		return (_FirstName + " " +_LastName);
	}
	 
	// to read only id from the person 
	__declspec( property ( get = getFirstname , put = setFirstname ) ) string Firstname;


	int id() {
		return _id ;
	}


};



int main()
{
	clsperson person1;
	person1.setFirstname("belal");
	person1.setlastname(" sayed ");
	cout << "firstname : " << person1.getFirstname()<<endl;

	person1.Firstname = "mohsen";
	cout << person1.Firstname << endl;


}

