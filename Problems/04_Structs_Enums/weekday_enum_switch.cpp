#include <iostream>
 

using namespace std;

//enum encolors
//{
//	red =1 , blue =2 ,green = 3, yallo = 4
//};


enum enweekday
{
	sun = 1, mon = 2, tue = 3, wen = 4, thu = 5, fri = 6, sat = 7
};

void showmanu() {
		cout << "************************" << endl;
		cout << "       Week Days        " << endl;
		cout << "************************" << endl;
		cout << "1: Sunday" << endl;
		cout << "2: Monday" << endl;
		cout << "3: Tuesday" << endl;
		cout << "4: Wednesday" << endl;
		cout << "5: Thursday" << endl;
		cout << "6: Friday" << endl;
		cout << "7: Saturday" << endl;
		cout << "************************" << endl;
		cout << "Please enter the number of day?" << endl;
}

enweekday readday() {
	int d;
	cin >> d;
	return (enweekday)d;

}

string clcday(enweekday weekday) {
	switch (weekday)
	{
	case enweekday::sun:
		return"sunday";
		break;
		case enweekday::mon:
		return "monday";
		break;
		case enweekday::tue:
			return "tuesday";
		break;
		case enweekday::wen:
			return "wednesday";
		break;
		case enweekday::thu:
			return "thusday";
		break;
		case enweekday::fri :
			return "friday";
		break;
		case enweekday::sat:
			return "saturday";
		break;
	default:
		return "the number is not define";
		break;
	}
}

int main()
{

  /*  int day;
    cout << "enther the number of week \n";
    cin >> day;
	switch (day)
	{
	case 1 :
		cout << "the day is saterday";
		break;

	case 2 :
		cout << "the day is sunday";
		break;
	case 3:
		cout << "the day is monday ";
		break;
	case 4:
		cout << "the day is tuseday";
		break;
	case 5:
		cout << "the day is wensday";
		break;
	case 6:
		cout << "the day is tharsday";
		break;
	case 7:
		cout << "the day is friday";
		break;

	default:
		cout << "this number is notvbelonge to  day's week";
		break;
	}*/


	/*encolors color;
	int c;
	cout << "please enter your color number " << endl;
	cin >> c;
	color = (encolors)c;
	switch (color)
	{
	case  encolors:: red:
		system("color 4F");
		break;
	case encolors::blue:
		system("color 1F");

		break;
	case  encolors::green:
		system("color 2F");
		break;
	case encolors::yallo:
		system("color 4F");
		break;
	default:
		system("color 4F");
		break;
	}*/

	/********************************************************************************************************************************/
	//int n1, n2;
	//char operations_type;
	//cout << "please enter the first number \n";
	//cin >> n1;
	//cout << "please enter the second number \n";
	//cin >> n2;
	//cout << "please enter the type opreation you want \n";

	//cin >> operations_type;

	//switch (operations_type)
	//{
	//case  '+':
	//	cout << n1 + n2 << endl;
	//	break;
	//case '-':
	//	cout << n1 - n2 << endl;
	//	break;
	//case'*':
	//	cout << n1 * n2 << endl;
	//	break;
	//case '/':
	//	cout << n1 / n2 << endl;
	//	break;

	//	
	//default:
	//	cout << "please enter the sign again";

	//	break;
	//}
	/****************************************************************************************************************/

	showmanu();
	cout << "it's " << clcday(readday()) << endl;



}



