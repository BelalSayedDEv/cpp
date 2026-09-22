#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsUser.h"

class clsAddUserScreen :protected clsScreen
{

private:

    static void _ReadClientInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();
    
        cout << "\nRead Permations: ";
        User.Permissions = _ReadPermations();
    }

    static void _PrintClient(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
       
        cout << "\n___________________\n";

    }

    static int _ReadPermations() {
        int permation = 0 ;
        char choise;
        cout << "Do you want give him full access y or no" << endl;
        cin >> choise;
        if (choise == 'y'||choise == 'Y')
        {
            return -1;
        }
        cout << "Do you want give him Show list of client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pListClients;
        }
        cout << "Do you want give him add  client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pAddNewClient;
        }
        cout << "Do you want give him delete  client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pDeleteClient;
        }
        cout << "Do you want give him update client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pUpdateClients;
        }
        cout << "Do you want give him find client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pFindClient;
        }
        cout << "Do you want give him manage trasactions  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pTranactions;
        }
        cout << "Do you want give him manage users  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pManageUsers;
        }
        cout << "Do you want give him Show Log Register of users  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pLogRegister;
        }
        return permation;
    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New Client Screen");

        string UserName = "";

        cout << "\nPlease Enter user name: ";

        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);


        _ReadClientInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded :
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject :
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists :
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }
};

