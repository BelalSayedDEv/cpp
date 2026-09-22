#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;

class clsShowUbdateCurrencyScreen : protected clsScreen
{

protected:

	static void _print(clsCurrency currency) {

		cout << "\n\tCurrency Card" << endl;
		cout << "-------------------------------" << endl;
		cout << "\tCountry  :" << currency.Country() << endl;
		cout << "\tCode     :" << currency.CurrencyCode() << endl;
		cout << "\tName     :" << currency.CurrencyName() << endl;
		cout << "\tRate(1$) :" << currency.Rate() << endl;
		cout << "-------------------------------" << endl;
	}

	static float _ReadNewRate() {

		cout << "\n\tCurrency Card" << endl;
		cout << "-------------------------------" << endl;
		cout << "\n Enter New Rate : ";

		float number = clsInputValidate::ReadFloatNumber();
		return number;

	}

	static bool showreslute(clsCurrency Currency) {

		if (!Currency.IsEmpty()) {

			return true;

		}
		else
		{
			return false;

		}
	}

public:

	static void UpdateRate() {

		_DrawScreenHeader("\t Update Rate Screen ");

		cout << "please Enter Currency Code : ";
		string Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(clsstring::UpperString(Code));

		if (showreslute(Currency)) {
			_print(Currency);
			cout << "\nAre you sure you want to Update the rate of this Currency y/n ?  ";
			char choise;
			cin >> choise;
			if (choise == 'y' || choise == 'Y') {
				float NewRate = _ReadNewRate();
				Currency.UpdateRate(NewRate);
				cout << "\nCurrency Rate Updated Successfully :-)" << endl;
			}

		}else
		{
			cout << "Currency is Not found " << endl;
		}
	}


};

