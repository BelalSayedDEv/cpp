#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsers.h"
#include "clsShowListRigsterLogScreen.h"
#include"clsShowCurrencyScreen.h"

using namespace std;

class clsMainScreen :protected clsScreen
{


private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eRigsterLOGUsers = 8, eShowCurrency = 9 ,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10 ? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
      /*  cout << "\nDelete Client Screen Will be here...\n";*/
        clsDeleteClientScreen::DeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        /*cout << "\nUpdate Client Screen Will be here...\n";*/
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }   

    static void _ShowFindClientScreen()
    {
      /*  cout << "\nFind Client Screen Will be here...\n";*/
        clsFindScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        /*cout << "\nTransactions Menue Will be here...\n";*/
        
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        /*cout << "\nUsers Menue Will be here...\n";*/
        clsMangeUsers::ShowManageUsersMenue();
    }

    static void _ShowListRigsterLog()
    {
        /*cout << "\nUsers Menue Will be here...\n";*/
        clsShowListRigsterLogScreen::ShowLogRigstersList();
    }

    static void _ShowCurrencyScreen()
    {
        /*cout << "\nUsers Menue Will be here...\n";*/
        clsShowCurrencyScreen::ShowCurrencyScreen();
    }

   /* static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/

    static void _Logout() {

        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eRigsterLOGUsers:
            system("cls");
            _ShowListRigsterLog();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowCurrency:
            system("cls");
            _ShowCurrencyScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
           break;
        }

    }

public:


    static void ShowMainMenue()
    {

        system("cls");

        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] List Users Log.\n";
        cout << setw(37) << left << "" << "\t[9] Currecy .\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

