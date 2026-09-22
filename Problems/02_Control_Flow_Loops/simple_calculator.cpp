#include <iostream>

using namespace std;
int main()
{
	int num1, num2;
	string operation_type;
	cin >> num1;
	cin >> num2;
	cin >> operation_type;
	if (operation_type == "+")
	{
		cout <<num1 + num2 << endl;
	}
	else if (operation_type == "-"){

		cout << num1 - num2 << endl;
	}
	else if (operation_type == "*"){

		cout << num1 *num2 << endl;
	}
	else if (operation_type == "/"){

		cout << num1 /num2 << endl;
	}

}