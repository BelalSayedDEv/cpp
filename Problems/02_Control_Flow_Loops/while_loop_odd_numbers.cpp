#include <iostream>


using namespace std;

int main()
{
 

	/*int i = 1 ;
	while (i <= 10) {
		
		cout << i << endl;
		i++;

	}*/


	/*int i = 10 ;
	while (i >= 1) {

		cout << i << endl;
		i--;

	}*/

	int i;
	cout << "please enter the  max number \n";
	cin >> i;
	int sum = 0;
	while (i >= 0) {


		if (i % 2 == 0) {
			
			
		}
		else
		{
			sum += i;
		}
		i--;
	}
	cout << "sum " << sum;




}


