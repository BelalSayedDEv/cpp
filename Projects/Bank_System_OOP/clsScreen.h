#pragma once

#include <iostream>
#include"clsUser.h"
#include "global.h"
#include"clsdate.h"
using namespace std;


class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        clsDate Date;
        cout << "\t\t\t\t\t User : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t Date : ";
        Date.Print();
        cout << endl;
    }

    static bool CheckAccessRight(clsUser::enPermissions Permissation) {

        if (!CurrentUser.checkAccessScreen(Permissation)) {

            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
            
        }
        else {
            return true;
        }
    }

};