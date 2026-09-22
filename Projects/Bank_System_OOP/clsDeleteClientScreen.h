#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
	
	static void DeleteClientScreen() {

		_DrawScreenHeader("\t Delete Client Screen ");
        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient)) {
            return;
        }

        string AccountNumber = "";

        cout << "enter Accountnumber  : " << endl;

        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number not found, try another one: " << endl;
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintClient(client);

        cout << "Do you want to delete this client y or n" << endl;
        char choise;
        cin >> choise;

        if (choise == 'y' || choise == 'Y')
        {
            if (client.Delete()) {

                cout << "the client deleted succussffuly" << endl;

            }
            else
            {
                cout << "error ,deleted not complete successffuly " << endl;
            }
        }

	}

};

