#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsBankClient.h"
#include"clsdate.h"

using namespace std;
class clsUser : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;



	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;

		vUserData = clsstring::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], Decrypt(vUserData[5], 5), stoi(vUserData[6]));

	}

	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += Encrypt(User.Password, 5) + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}

	static  vector <clsUser> _LoadUsersDataFromFile()
	{

		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLinetoUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _convertogdatetoline(string Sperator = "#//#") {

		string line = "";
		line += clsDate::DateToString(clsDate()) + " - ";
		line += clsDate::GetTime() + Sperator;
		line += UserName + Sperator;
		line += Encrypt(Password, 5) + Sperator;
		line += to_string(Permissions);
		return line;


	}

	static string _convertLogTransferdatetoline(clsBankClient client1, clsBankClient client2, int Amount, string UserName, string Sperator = "#//#") {

		string line = "";
		line += clsDate::DateToString(clsDate()) + " - ";
		line += clsDate::GetTime() + Sperator;
		line += client1.AccountNumber() + Sperator;
		line += client2.AccountNumber() + Sperator;
		line += to_string(Amount) + Sperator;
		line += to_string(client1.AccountBalance) + Sperator;
		line += to_string(client2.AccountBalance) + Sperator;
		/*line += UserName;*/

		return line;


	}


public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLogRegister = 128
	};


	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}

	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool checkAccessScreen(enPermissions permisstion) {

		if (this->Permissions == enPermissions::eAll) {
			return true;
		}
		if ((permisstion & this->Permissions) == permisstion)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void SaveDataToLogFile(clsUser user) {
		fstream myfile;
		myfile.open("UserLog.txt", ios::app);
		if (myfile.is_open()) {
			string line;
			line = _convertogdatetoline();
			myfile << line << endl;
			myfile.close();
		}
	}

	static struct stuser
	{
		string Username;
		string date;
		string password;
		int permation;

	};



	static stuser _ConvertLinetostuser(string line, string seprator = "#//#") {

		vector<string>vstring;
		vstring = clsstring::Split(line, seprator);

		stuser user;
		user.date = vstring[0];
		user.Username = vstring[1];
		user.password = Decrypt(vstring[2], 5);
		user.permation = stoi(vstring[3]);

		return user;

	}

	static vector<stuser> _ConvertLinetoVectorOfStrng()
	{
		vector<stuser> vUserData;
		fstream myfile;
		stuser user;
		myfile.open("UserLog.txt", ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {

				user = _ConvertLinetostuser(line);
				vUserData.push_back(user);
			}
			myfile.close();
		}
		return vUserData;
	}

	static vector<stuser> GetUsersLogList() {

		return _ConvertLinetoVectorOfStrng();
	}

	static string Encrypt(string text, int key) {

		for (int i = 0; i <= text.length(); i++)
		{
			text[i] = char((int)text[i] + key);
		}
		return text;
	}


	static string Decrypt(string text, int key) {

		for (int i = 0; i <= text.length(); i++)
		{
			text[i] = char((int)text[i] - key);
		}
		return text;
	}



};

