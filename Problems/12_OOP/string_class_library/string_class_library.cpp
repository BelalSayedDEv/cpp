#include <iostream>

#include "clsString.h";

using namespace std;



int main()
{
	clsstring String;

	cout << "the First letter is : " << String.Firstletter(" mohamed") << endl;
	
	cout << "the sentance after captalize sentance : " << String.ToTitleCase("belal sayed isa") << endl;
	cout << "the sentance after captalize sentance : " << String.CountWord(" belal sayed isa tamame hassan ");
	
}

