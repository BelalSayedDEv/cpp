
#include <iostream>
using namespace std;


int readgrade(int from,int to) {
	int grade = 0 ;
	do
	{
		cout << "please enter number between 0 to 100 " << endl;
		cin >> grade;
	} while ( grade < from || grade > to);
	return grade;
}

char getlettargrad(int grad) {
	if (grad >=90 || grad <=100)
	{
		return 'A';
	}
	else if (grad >= 80 || grad <= 89)
	{
		return'B';
	}
	else if (grad >= 70 || grad <= 79)
	{
		return'C';
	}
	else if (grad >= 60 || grad <= 69)
	{
		return'D';
	}
	else if (grad >= 50 || grad <= 59)
	{
		return'E';
	}
	else 
	{
		return'F';
	}
}

int main()
{
	cout << "Result = " << getlettargrad(readgrade(0, 100)) << endl;
}


