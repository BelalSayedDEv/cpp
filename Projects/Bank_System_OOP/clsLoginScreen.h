#pragma once
#include"clsInputValidate.h"
#include"clsShowMainScreens.h"
#include<iomanip>
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"global.h"
#include<fstream>
#include"clsdate.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _login() {

		bool LoginFaild = false;
		string username, password;
		int counterFailed = 0;
		do {

			if (LoginFaild) {

				cout << "\nInvaild UserName,Password , Try again" << endl;
				counterFailed++;
				cout << "You have " << (3 - counterFailed) << " Trails to login." << endl;

			}
			if (counterFailed == 3) {

				cout << "\nYou are locked after 3 failed \n\n";
				return false;
			}
			cout << "\nEnter UserName? " << endl;

			username = clsInputValidate::ReadString();
			cout << "\nEnter PassWord? " << endl;
			password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(username, password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.SaveDataToLogFile(CurrentUser);

		clsMainScreen::ShowMainMenue();

		return true;
		
	}


public:

	static bool ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return	_login();

	}
};

