#pragma once
#include"clsUser.h"
#include<iomanip>
#include<iostream>
#include"clsScreen.h"

using namespace std;


class clsShowListRigsterLogScreen:protected clsScreen
{
private:
	

	static void _PrintClientRecordLine(clsUser::stuser user)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left <<user.date;
		cout << "| " << setw(20) << left <<user.Username;
		cout << "| " << setw(20) << left << user.password;
		cout << "| " << setw(20) << left << user.permation;


	}

public:

	static void ShowLogRigstersList()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pLogRegister)) {
			return;
		}
		string line;
		vector <clsUser::stuser > vusers = clsUser::GetUsersLogList();

		string Title = "\t  User Log Register List Screen";
		string SubTitle = "\t    (" + to_string(vusers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permations";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vusers.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsUser::stuser suser : vusers)
			{

				_PrintClientRecordLine(suser);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

	
};

