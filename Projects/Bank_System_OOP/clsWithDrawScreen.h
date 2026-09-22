#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsWithDrawScreen :protected clsScreen
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

    static void ShowWithDrawClient() {

        _DrawScreenHeader("\t WithDraw Screen");

        string AccountNumber = "";

        AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account number is not found , enter again" << endl;
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);

        _PrintClient(client);
        cout << "\nplease enter an amount of deposition " << endl;


        double InputofWithdraw = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure to WithDraw " << InputofWithdraw << "  from Account balance y or n" << endl;

        char choise;
        cin >> choise;

        if (choise == 'Y' || choise == 'y')
        {
            if (client.Withdraw(InputofWithdraw))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << InputofWithdraw;
                cout << "\nYour Balance is: " << client.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};


