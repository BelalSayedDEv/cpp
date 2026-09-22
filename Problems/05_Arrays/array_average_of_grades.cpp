
#include <iostream>
using namespace std;


void readarray(float x[3]) {

	cout << "please enter your grad1" << endl;
	cin >> x[0];
	cout << "please enter your grad2 " << endl;
	cin >> x[1];
	cout << "please enter your grad3 " << endl;
	cin >> x[2];

}

void printarray(float x[3]) {

	float result = (x[0] + x[1] + x[2]) / 3;
	cout << "the avareg of grades is : " << result << endl;

}


int main()
{
	/*float grade[3];

	cout << "please enter grade1 \n" ;
	cin >> grade[0];
	cout << "please enter grade2\n";
	cin >> grade[1];
	cout << "please enter grad3 " << endl;
	cin >> grade[2];
	
	cout <<"the average of grade is : " << (grade[0] + grade[1] + grade[2])/3 << endl;*/

	float grades[3];
	readarray(grades);
	printarray(grades);



   
}

