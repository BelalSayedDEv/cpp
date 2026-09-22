#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
#include"global.h"

class clsFindScreen :  protected clsScreen
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
    static void ShowFindClientScreen() {

        _DrawScreenHeader("\t Find Client Screen");
        if (!CheckAccessRight(clsUser::enPermissions::pFindClient)) {
            return;
        }
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);

        _PrintClient(client);
    }
};

