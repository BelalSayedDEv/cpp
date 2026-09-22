#pragma once
#include"clsInputValidate.h"
#include<iomanip>
#include<iostream>
#include"clsScreen.h"
using namespace std;

class clsShowTransferScreen : protected clsScreen
{
private:

	static void _print(clsBankClient Client1) {
		cout << "\n=========================" << endl;
		cout << "\tClient Card: " << endl;
		cout << "=========================" << endl;
		cout << "FullName      : " << Client1.FullName() << endl;
		cout << "Account Number: " << Client1.AccountNumber() << endl;
		cout << "Balance       : " << Client1.AccountBalance << endl;
	}

public:

	/*static void ShowTransferProcess() {

		_DrawScreenHeader("\t Transfeer Screen");

		string AccountNumber1 = "";
		cout << "Enter an Account Number which will send from it " << endl;

		AccountNumber1 = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(AccountNumber1)) {
			cout << "Enter an Account Number Is NOT Found  " << endl;
			AccountNumber1 = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
		_print(Client1);


		string AccountNumber2 = "";

		cout << "\nEnter an Account Number which will recive the amount of balance " << endl;
		AccountNumber2 = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(AccountNumber2)) {
			cout << "Enter an Account Number Is NOT Found  " << endl;
			AccountNumber2 = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		_print(Client2);

		float Amount = 0;

		cout << "\nEnter Transfer Amount :" << endl;
		Amount = clsInputValidate::ReadFloatNumber();

		cout << "Are you Sure to Transfeer this Amount" << endl;

		char choise;
		cin >> choise;

		if (choise == 'y' || choise == 'Y') {

			while (!Client1.Withdraw(Amount)) {

				if (Client1.AccountBalance == 0) {
					cout << "Balancre is 0 , Enter Balalnce and Try Again Letter" << endl;
					Amount = 0;
					break;
				}

				cout << "\nAmount Exeeds the avaliable balance , Enter Transfer Amount Again: ";
				Amount = clsInputValidate::ReadFloatNumber();
				cout << endl;
				
			}

			if(Amount!=0)
			{
				
				cout << "\nTransfer done successfully " << endl;
				Client2.Deposit(Amount);
			}
		}

		_print(Client1);
		_print(Client2);
	}*/

private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);


	}
};

