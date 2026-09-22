

#pragma once
#include<iomanip>
#include<iostream>
#include"clsScreen.h"

class clsShowLogOfListTransfeer :protected clsScreen
{
//
//private:
//
//	static void _PrintClientRecordLine(clsUser::stTransfeerCleint user)
//	{
//
//		cout << setw(8) << left << "" << "| " << setw(30) << left << user.date;
//		cout << "| " << setw(20) << left << user.Account1;
//		cout << "| " << setw(20) << left << user.Account2;
//		cout << "| " << setw(20) << left << user.Amount;
//		cout << "| " << setw(20) << left << user.balance1;
//		cout << "| " << setw(20) << left << user.balance1;
//		cout << "| " << setw(20) << left << user.Username;
//
//
//	}
//
//public:
//
//
//	static void ShowLogTransfeerList()
//	{
//		
//		string line;
//		vector <clsUser::stTransfeerCleint > vusers = clsBankClient;
//
//		string Title = "\t  User Log Transfeer List Screen";
//		string SubTitle = "\t    (" + to_string(vusers.size()) + ") User(s).";
//
//		_DrawScreenHeader(Title, SubTitle);
//
//
//
//		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
//		cout << "_________________________________________\n" << endl;
//
//		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
//		cout << "| " << left << setw(20) << "AccountNumber 1";
//		cout << "| " << left << setw(20) << "AccountNumber 2";
//		cout << "| " << left << setw(20) << "Amount ";
//		cout << "| " << left << setw(20) << "Balance 1 ";
//		cout << "| " << left << setw(20) << "Balance 2 ";
//		cout << "| " << left << setw(20) << "UserName";
//		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
//		cout << "_________________________________________\n" << endl;
//
//		if (vusers.size() == 0)
//			cout << "\t\t\t\tNo Clients Available In the System!";
//		else
//
//			for (clsUser::stTransfeerCleint suser : vusers)
//			{
//
//				_PrintClientRecordLine(suser);
//				cout << endl;
//			}
//
//		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
//		cout << "_________________________________________\n" << endl;
//
//	}
private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransfeerCleint user)
    {

                cout << setw(8) << left << "" << "| " << setw(23) << left << user.date;
        		cout << "| " << setw(8) << left << user.Account1;
        		cout << "| " << setw(8) << left << user.Account2;
        		cout << "| " << setw(8) << left << user.Amount;
        		cout << "| " << setw(10) << left << user.balance1;
        		cout << "| " << setw(10) << left << user.balance1;
                cout << "| " << setw(8) << left << user.Username;

    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransfeerCleint> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransfeerCleint Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

