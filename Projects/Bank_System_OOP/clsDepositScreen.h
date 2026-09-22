#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen:protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    


public:

    static void ShowDepositClient() {

        _DrawScreenHeader("\t Deposit Screen");

        string AccountNumber = "";

        AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account number is not found , enter again" << endl;

            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);

        _PrintClient(client);

        cout << "please enter an amount of deposition " << endl;
        double InputofDeposit = clsInputValidate::ReadDblNumber();

        cout << "Are you sure to add " << InputofDeposit << " y or n" << endl;

        char choise;
        cin >> choise;

        if (choise == 'y' || choise == 'Y') {

            client.Deposit(InputofDeposit);
            cout << "Amount Deposited Successfully" << endl;
            cout << "New Account Balance : " <<client.AccountBalance<< endl;
        }
        else
        {
            cout << "Opreation Was cancelled " << endl;
        }

    }
};

