#pragma once
#include <iostream>
#include "clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsShowcurrencyList.h"
#include"clsShowFindCurrencyScreen.h"
#include"clsShowUbdateCurrencyScreen.h"
#include"clsCalculatorCurrency.h"
class clsShowCurrencyScreen : protected clsScreen
{

private:

	enum enCurrencyMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, 
		eUpdateRate = 3, eShowCurrencyCalculater = 4, eExit = 5
	};
	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
		return Choice;
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");

		ShowCurrencyScreen();

	}

	static void _ShowListCurrenciesScreen()
	{
		 /* cout << "\nClient List Screen Will be here...\n";*/
		
		clsShowcurrencyList::ShowCurrencyList();

	}

	static void _ShowFindCurrencyScreen()
	{
		/* cout << "\nAdd New Client Screen Will be here...\n";*/

		 clsShowFindCurrencyScreen::FindCurrency();

	}

	static void _ShowUpdateRateScreen()
	{
		  /*cout << "\nDelete Client Screen Will be here...\n";*/
		clsShowUbdateCurrencyScreen::UpdateRate();
	}

	static void _ShowCurrencyCalculaterScreen()
	{
		/*cout << "\nUpdate Client Screen Will be here...\n";*/
		
		clsCalculatorCurrency::showExchangeCurrencies();
	}

    static void _PerfromCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)

    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyMenueOptions::eListCurrencies:
        {
            system("cls");
			_ShowListCurrenciesScreen();
            _GoBackToMainMenue();
            break;
        }
        case enCurrencyMenueOptions::eFindCurrency:
            system("cls");
			_ShowFindCurrencyScreen();
            _GoBackToMainMenue();
            break;

        case enCurrencyMenueOptions::eUpdateRate:
            system("cls");
			_ShowUpdateRateScreen();
            _GoBackToMainMenue();
            break;

        case enCurrencyMenueOptions::eShowCurrencyCalculater:
            system("cls");
			_ShowCurrencyCalculaterScreen();
            _GoBackToMainMenue();
            break;

      
		case enCurrencyMenueOptions::eExit:

            break;
        }

    }

public:

	static void ShowCurrencyScreen() {

		system("cls");

		_DrawScreenHeader("\t Currency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculater.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrencyMenueOption((enCurrencyMenueOptions)_ReadMainMenueOption());
	}
	
};

