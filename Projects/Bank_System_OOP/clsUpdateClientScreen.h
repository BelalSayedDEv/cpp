#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsUpdateClientScreen :protected	clsScreen
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
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

public:

    

   static void ShowUpdateClientScreen() {

        _DrawScreenHeader("\t  Update Client Screen");
        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients)) {
            return;
        }

        string AccountNumber = "";

        cout << "please enter the AccountNumber" << endl;

        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account number is not found , enter again" << endl;
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);

        _PrintClient(client);

        cout << "Updated Client Info : " << endl;
        cout << "------------------------" << endl;

        _ReadClientInfo(client);
            
        clsBankClient::enSaveResults enresult;

        enresult = client.Save();

        switch (enresult) {

        case clsBankClient::enSaveResults::svSucceeded:

            cout << "\nclient updated successuflly\n" << endl;
            break;

        case clsBankClient::enSaveResults::svFaildEmptyObject:

            cout << "\nerror account was not saved because it's empty\n" << endl;
            break;
        }

    }


};

