#pragma once

#include<iostream>	
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowUsersList.h"
#include"clsAddUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;


class clsMangeUsers :  protected clsScreen
{

private:

    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static short ReadManageUsersMenueOption() {

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short number = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1 : 6 ");
        return number;
   }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions) {
        switch (ManageUsersMenueOptions)
        {
        case clsMangeUsers::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case clsMangeUsers::eAddNewUser:
            system("cls");
            _ShowAddUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case clsMangeUsers::eDeleteUser:
            system("cls");
            _ShowDeleteUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case clsMangeUsers::eUpdateUser:
            system("cls");
            _ShowUpdateUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case clsMangeUsers::eFindUser:
            system("cls");
            _ShowFindUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case clsMangeUsers::eMainMenue:
           {

           }
        }
    }

    static void _ShowListUsersScreen() {

        /*cout << "will after be soon" << endl;*/
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddUsersScreen() {
       /* cout << "will after be soon" << endl*/;
       clsAddUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUsersScreen() {
        /*cout << "will after be soon" << endl;*/
        clsDeleteUserScreen::ShowDeleteUser();
    }
    static void _ShowUpdateUsersScreen() {
       /* cout << "will after be soon" << endl;*/
        clsUpdateUserScreen::ShowUpdateUser();
    }
    static void _ShowFindUsersScreen() {
        /*cout << "will after be soon" << endl;*/
        clsFindUserScreen::ShowFindUser();
        
    }

    

    static void _GoBackToMangeUsersMenue() {
        cout << "\npress any key to back to mange users menue" << endl;
        system("pause > 0");
         ShowManageUsersMenue();
    }
public:
    static void ShowManageUsersMenue()
    {

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");
        if (!CheckAccessRight(clsUser::enPermissions::pManageUsers)) {
            return;
        }

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions) ReadManageUsersMenueOption());
    }

};

