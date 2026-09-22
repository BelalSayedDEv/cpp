#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalances.h"
#include"clsShowTransferScreen.h"
#include"clsShowLogOfListTransfeer.h"


using namespace std;


class clsTransactionsScreen : protected clsScreen
{

private:

    enum enMainMenueOptions {

        DepositScreen = 1, Withdraw = 2, TotalBalances = 3 , Transfer = 4, LogTransfeer = 5 , MainMenu = 6
   };

   static short _ReadMainMenueOption() {

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
         
   }

   static  void _GoBackToMainMenue()
   {
       cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

       system("pause>0");
       ShowTransactionsMenue();
   }

   static void  _PerfromMainMenueOption(enMainMenueOptions enMainMenueOptions) {

      switch (enMainMenueOptions)
      {
      case enMainMenueOptions::DepositScreen :
          system("cls");
          ShowDepositeScreen();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::Withdraw :
          system("cls");
          ShowWithdrawScreen();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::TotalBalances :
          system("cls");
          ShowTotalBalancesScreen();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::Transfer:
          system("cls");
          ShowTransferprocessScreen();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::LogTransfeer:
          system("cls");
          ShowLogTransfeerUsersScreen();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::MainMenu :
         {

         }
      }
    }

   static void ShowDepositeScreen() {
       clsDepositScreen::ShowDepositClient();
   }
   static void ShowWithdrawScreen() {
       /*cout << "\nTransactions Menue Will be here...\n";*/
       clsWithDrawScreen::ShowWithDrawClient();
   }
   static void ShowTotalBalancesScreen() {
      /* cout << "\nTransactions Menue Will be here...\n";*/
       clsTotalBalancesScreen::ShowTotalBalances();
   }
   static void ShowTransferprocessScreen() {
       /* cout << "\nTransactions Menue Will be here...\n";*/
       clsShowTransferScreen::ShowTransferScreen();
   }
   static void ShowLogTransfeerUsersScreen() {
       /* cout << "\nTransactions Menue Will be here...\n";*/
       clsShowLogOfListTransfeer::ShowTransferLogScreen();
   }
   static void ShowMainMenue() {
       
   }
public:


    static void ShowTransactionsMenue()
    {

        system("cls");

        _DrawScreenHeader("\t  Transactions Screen");
        if (!CheckAccessRight(clsUser::enPermissions::pTranactions)) {
            return;
        }

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw Client.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances Client.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
     
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

