#include <iostream>

using namespace std;

//int readpostivenum(int &number) {
//
//	cout << "please enter postive number : ";
//	cin >> number;
//	while (number < 0) {
//		cout << "wrong number, please enter postive number \n ";
//		cin >>number;
//	}
//
//	return number;
//}

// 
int readrange(int from, int to) {
	int rangenum;
	cout << "please enter number between " <<from <<" to "<< to<<endl;
	cin >> rangenum;

	while (rangenum < from || rangenum > to) {

		cout << "wrong number , please enter number between " << from << " to " << to << endl;
		cin >> rangenum;
	}
	return rangenum;
}
int main()
{
	/*int number;
	cout << "number is  : " << readpostivenum(number) << endl;*/

	int range;
	cout << "number is " << readrange(40,80);


}

