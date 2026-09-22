#pragma once

#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>
using namespace std;

class clsFindUserScreen :protected clsScreen
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

public:
    static void ShowFindUser() {

        _DrawScreenHeader("\t Update User Screen");

        string username = "";

        cout << "please enter your username : " << endl;

        username = clsInputValidate::ReadString();

        if (!clsUser::IsUserExist(username)) {

            cout << "UserName is not found , choose another one  " << endl;
            username = clsInputValidate::ReadString();
        }

        clsUser user = clsUser::Find(username);


        if (!user.IsEmpty()) {

            cout << "\nUser is Found " << endl;
        }
        else {

            cout << "\nUser is not Found " << endl;

        }

        _PrintUser(user);
    }

};

