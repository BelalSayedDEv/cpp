#pragma once
#include"clsCurrency.h"
#include<iomanip>
#include"clsScreen.h"
#include<iostream>

using namespace std;

class clsShowcurrencyList : protected  clsScreen
{
private:

	static void _PrintCurrencye(clsCurrency currency) {

		cout << "\n\t " << " | " << left << setw(30) << currency.Country() <<
			" | " << left << setw(10) << currency.CurrencyCode() <<
			" | " << left << setw(30) << currency.CurrencyName() <<
			" | " << left << setw(10) << currency.Rate() << endl;
	}

public:
	
	static void ShowCurrencyList() {
		vector<clsCurrency>vscurrency;
		vscurrency = clsCurrency::GetCurrenciesList();

		
		string title = "\t Currency List";
		string subtitle = "\t (" + to_string(vscurrency.size()) + ") Currency";
		_DrawScreenHeader(title,subtitle);

		if (vscurrency.size() == 0) {
			cout << "Not Found Currencies ,Call Admin" << endl;
		}
		else
		{

			cout << "\t " << " | " << left << setw(30) << "Country" <<
				" | " << left << setw(10) << "C_Code" <<
				" | " << left << setw(30) << "Currency Name" <<
				" | " << left << setw(10) << "Rate/(1$)" << endl;

			for (clsCurrency& c : vscurrency)
			{
				_PrintCurrencye(c);
			}
		}
	}

};

