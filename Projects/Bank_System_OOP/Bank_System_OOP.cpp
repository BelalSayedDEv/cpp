#pragma warning(disable : 4996)

#include <iostream>
#include<string>
#include "clsString.h"
#include <iomanip>
#include"clsdate.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include "clsBankClient.h"
#include"clsShowMainScreens.h"
#include"clsLoginScreen.h"

using namespace std;


int main()

{
	while (true) {
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}
	}

	return 0;
}


