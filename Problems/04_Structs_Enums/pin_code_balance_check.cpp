#include <iostream>
using namespace std;



struct stbalance
{
	string pin_code;
	
};


void readbalance(stbalance& balance) {
	cout << "pleas enter your pin " << endl;
	cin >> balance.pin_code;
}

void clcubalance(string pin) {
	if (pin =="1234")
	{
		cout << "your balance is : 7500";

	}
	else
	{
		cout << "wrong password  : please enter your pin again";
	}
}


int main()
{
	stbalance balance1;
	readbalance(balance1);
	clcubalance(balance1.pin_code);
}
