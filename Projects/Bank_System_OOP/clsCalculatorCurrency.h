#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;

class clsCalculatorCurrency : protected clsScreen
{
private:

	/*static void _print(clsCurrency currency) {

		
		cout << "-------------------------------" << endl;
		cout << "\tCountry  :" << currency.Country() << endl;
		cout << "\tCode     :" << currency.CurrencyCode() << endl;
		cout << "\tName     :" << currency.CurrencyName() << endl;
		cout << "\tRate(1$) :" << currency.Rate() << endl;
		cout << "-------------------------------" << endl;
	}*/

	static float _ReadAmount() {

		cout << "\n Enter Amount to Exchange: ";

		float number = clsInputValidate::ReadFloatNumber();
		return number;

	}

	static clsCurrency GetCurrency(string message) {

		cout <<message ;
		string code1 = clsInputValidate::ReadString();


		if (!clsCurrency::IsCurrencyExist(clsstring::UpperString(code1))) {

			cout << "\n\tCurrency Code Is Not Found, try again : ";
			code1 = clsInputValidate::ReadString();
		}
		clsCurrency currency1 = clsCurrency::FindByCode(clsstring::UpperString(code1));
		return currency1;
	}

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ExchangetoUsd(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ExchangeFromUsdtoAnyOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


public:

	static void showExchangeCurrencies() {

		_DrawScreenHeader("\t Calculator Exchange Screen");

		char choise= 'y';

		while(choise == 'y' || choise == 'Y') {

			clsCurrency currency1 = GetCurrency("\n\tplease enter Currency1 Code : ");
			clsCurrency currency2 = GetCurrency("\n\tplease enter Currency2 Code : ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, currency1, currency2);
			cout << "do you want to make other exchange y or n " << endl;
			cin >> choise;

		}
	}

};

