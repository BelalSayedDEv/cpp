#pragma warning(disable : 4996)
#include <iostream>
#include"clsdate.h"
#include"clsString.h"

using namespace std;

int main()
{
    clsDate date(31,1,2009);
    
    cout << "the days from the beganing of year" << clsDate::NumberOfDaysFromTheBeginningOfTheYear(date.Day,date.Month,date.Year) << endl;


}

