

#include <iostream>
#include"clsInputValidate.h"

int main()
{
	int intnumber = clsInputValidate<int>::ReadIntNumber();
	cout << "\n number :" << intnumber;
	
	float floatnumber = clsInputValidate<float>::ReadIntNumber();
	cout << "\n number :" << floatnumber;

	float floatbetweeNnumber = clsInputValidate<float>::ReadShortNumberBetween(1.4,5.4);
	cout << " number :" << floatbetweeNnumber;
}
