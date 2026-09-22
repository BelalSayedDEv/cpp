#pragma once

#include"clsScreen.h"
#include<iomanip>
#include"clsCurrency.h"
#include<iostream>
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;

class clsShowFindCurrencyScreen:protected clsScreen
{

private:
	static void _print(clsCurrency currency) {

		cout << "\n\tCurrency Card" << endl;
		cout << "-------------------------------" << endl;
		cout << "\tCountry  :" << currency.Country() << endl;
		cout << "\tCode     :" << currency.CurrencyCode() << endl;
		cout << "\tName     :" << currency.CurrencyName() << endl;
		cout << "\tRate(1$) :" << currency.Rate() << endl;
		cout << "-------------------------------" << endl;
	}

public:
	static void FindCurrency() {

		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country ?  : ";
		int number = clsInputValidate::ReadIntNumberBetween(1, 2, "please enter number from 1 : 2 ");

		if (number == 1) {
			cout << "\nplease enter CurrentCode  :  ";
			string code = clsInputValidate::ReadString();
			if (!clsCurrency::IsCurrencyExist(clsstring::UpperString(code))) {
				cout << "\n currency is Not found try again :  " << endl;
				code = clsInputValidate::ReadString();
			}
			clsCurrency currency = clsCurrency::FindByCode(code);
			cout << "\nCurrency is Found :-)" << endl;
			_print(currency);
			
		}
		else {
			cout << "\nplease enter Country  :  ";
			string country = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCountry(country);

			if(currency.IsEmpty()) {

				cout << "\n currency is Not found try again :  " << endl;
				
			}else
			{
				
				cout << "\nCurrency is Found :-)" << endl;
			}

			
			_print(currency);
		}
	}
};

