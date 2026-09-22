#pragma once
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>

class clsUpdateUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
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
        cout << "\nPermation    : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermations() {
        int permation = 0;
        char choise;
        cout << "\n=========================" << endl;
        cout << "     Permations INFO  " << endl;
        cout << "=========================" << endl;
        cout << "\nDo you want give hime full access y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            return -1;
        }
        cout << "Do you want give hime Show list of client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pListClients;
        }
        cout << "Do you want give hime add  client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pAddNewClient;
        }
        cout << "Do you want give hime delete  client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pDeleteClient;
        }
        cout << "Do you want give hime update client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pUpdateClients;
        }
        cout << "Do you want give hime find client  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pFindClient;
        }
        cout << "Do you want give hime manage trasactions  y or no" << endl;
        cin >> choise;
        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pTranactions;
        }
        cout << "Do you want give hime manage users  y or no" << endl;
        cin >> choise;

        if (choise == 'y' || choise == 'Y')
        {
            permation += clsUser::enPermissions::pManageUsers;
        }

        return permation;
    }

    static void _ReadUserInfo(clsUser& User)
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
  

public:
    static void ShowUpdateUser() {

        _DrawScreenHeader("\t Update User Screen");

        string username = "";

        cout << "please enter your username" << endl;
        username = clsInputValidate::ReadString();

        if (!clsUser::IsUserExist(username)) {

            cout << "UserName is not found , choose another one  " << endl;
            username = clsInputValidate::ReadString();
        }

        clsUser user = clsUser::Find(username);

        _PrintUser(user);

        char choise;
        cout << "are you suer to delete this user  y or n " << endl;
        cin >> choise;

        if (choise == 'y' || choise == 'Y')
        {
            cout << "\n=========================" << endl;
            cout << "     Update INFO  " << endl;
            cout << "=========================" << endl;

            _ReadUserInfo(user);

            clsUser::enSaveResults result;
            result = user.Save();

            switch (result) {
            case clsUser::enSaveResults::svSucceeded:

                cout << "\nclient updated successuflly\n" << endl;
                break;

            case clsUser::enSaveResults::svFaildEmptyObject:

                cout << "\nerror account was not saved because it's empty\n" << endl;
                break;
            }
        }
        
        

    }
};

