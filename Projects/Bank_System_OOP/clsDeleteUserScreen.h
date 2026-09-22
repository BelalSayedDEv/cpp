#pragma once
#include"clsUser.h"
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen :protected clsScreen
{

private:

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

public:
    static void ShowDeleteUser() {

        _DrawScreenHeader("\t Delete User");

        string UserName = "";

        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {

            cout << "UserName is not Found try onther one " << endl;
            UserName = clsInputValidate::ReadString();
        }

        clsUser user = clsUser::Find(UserName);
        _PrintClient(user);

        char choise;
        cout << "are you suer to delete this user  y or n " << endl;
        cin >> choise;

        if(choise == 'y' || choise == 'Y')
        {
            if (user.Delete()) {

                cout << "user deleted successfully " << endl;
                _PrintClient(user);
            }
            else
            {
                cout << "error ,deleted not complete successffuly " << endl;
            }
        }
    }
};

