

#include <iostream>
using namespace std;




//****************************second problem************************

//int space(int wide, int hight) {
//	int area = wide * hight;
//	return area;
//
//}

//******************************third poblem*************************


//float space(float a, float d) {
//	float area = a * sqrt(pow(d, 2) - pow(a, 2));
//	return area;
//
//}


//**************************fourth problem***************************
 

//float space(float r) {
//	float area = pow(r, 2) * 3.14;
//	return area;
//}

//***************************fifth problem*****************************
//
//float space( float d) {
//	float area = (pow(d, 2) * 3.14) * 0.25;
//	return area;
//}
//*******************************sixth problem**************************


//float space(float a) {
//	float area = (3.14 * pow(a, 2)) * 0.25;
//	return area;
//}
//**********************************eighth problem***********************

//float space( float l) {
//	float area = pow(l, 2) / (4 * 3.14);
//	return area;
//          }
//****************************************************************************
// 
//float space(float , float b, float c) {
//	float p = (a + b + c) / 2;
//
//	float area = 3.14 * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
//	return area;
//}
// 
// 
//
//*****************************************************************


//int power(int num, int m) {
//	int reslute = pow(num, m);
//	return reslute;
//}
//int duration(int day, int hour, int minutes, int seconds) {
//		
//	int resulte = day * 24 * 60 * 60 + hour * 60 * 60 + minutes * 60 + seconds;
//
//	return resulte;
//	}


//******************************first problem**********************

void swap(int &num1, int &num2) {

	int swaper;
	swaper = num1;
	num1 = num2;
	num2 = swaper;
	cout << num1 << endl << num2 << endl;
}



//int x = 300;
//
//void space(){
//
//	::x += 200;
//	cout << "the value in function is " << x << endl;
//
//}

int main()
{ 
	int num1, num2;
	cout << "please enter num1" << endl;
	cin >> num1;
	cout << "please enter num2" << endl;
	cin >> num2;
	swap(num1, num2);

	cout << num1 << endl << num2 << endl;
//************************************************************************
	//int wide, hight;
	//cout << "please enter the wide" << endl;
	//cin >> wide;
	//cout << "please enter the hight" << endl;
	//cin >> hight;
	//cout << "the area is :" << space(wide, hight) << endl;
//************************************************************************


	/*float a, d;
	cout << "please enter the wide" << endl;
	cin >> a;
	cout << "please enter the hight" << endl;
	cin >> d;
	cout << "the area is :" << space(a, d) << endl;*/

//************************************************************************

	/*float r;
	cout << "please enter the r" << endl;
	cin >> r;
	cout << " the area is :" << space(r) << endl;*/
//*************************************************************************
	/*float d;
	cout << "please enter the dimater" << endl;
	cin >> d;
	cout << "the area is :" << space(d) << endl;*/
//*************************************************************************

	/*float a;
	cout << "please enter a " << endl;
	cin >> a;
	cout << "area is :" << space(a) << endl;*/
//**************************************************************************

	//float l;
	//cout << "please enter the lenth " << endl;
	//cin >> l;
	//cout << "the area is " << space(l) << endl;

//**************************************************************************


	/*float a, b, c;
	cout << "please enter the a " << endl;
	cin >> a;
	cout << "please enter the b " << endl;
	cin >> b;
	cout << "please enter the c " << endl;
	cin >> c;
	cout << "area is " << space(a, b, c) << endl;*/

//***************************************************************************
//	int num, m;
//	 
//	cout << "please enter the number :" << endl;
//	cin >> num;
//	cout << "please enter the power :" << endl;
//	cin >> m;
//	cout << "the result of number " << num << " power " << m << " is " << power(num, m) << endl;

	/*int day, hour, minutes, seconds;
	cout << "please enter the days\n";
	cin >> day;
	cout << "please enter the hour\n";
	cin >> hour;
	cout << "please enter the minutes\n";
	cin >> minutes;
	cout << "please enter the seconds\n";
	cin >> seconds;
	cout << "the resulte of all this duration is : \n" << duration(day, hour, minutes, seconds) << endl;*/

	/*int x = 400;
	cout << "the valu in local main is " << x << endl;
	space();
	cout << "the value in the global variables is " << ::x << endl;*/





}


