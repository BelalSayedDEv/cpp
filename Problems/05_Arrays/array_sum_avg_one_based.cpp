
#include <iostream>
using namespace std;

void readnumarr(int arr[100] , int &maxnumber) {
	
	cout << "how many numbers do you want to enter ?  1 to 100 \n";
	cin >> maxnumber;
	

	for (int i = 1; i <= maxnumber; i++)
	{
		cout << "please enter number " << i << endl;
		cin >> arr[i];
	}
}

void printnumarr(int arr[100], int maxnumber) {
	
	for (int i = 1 ; i <=maxnumber ; i++)
	{
		cout << "Number  " << "["<<i<<"]" <<"  :  " << arr[i] << endl;
	}
}


int sumarrynum(int arr[100], int maxnumber) {


	int sum = 0;
	for (int i = 1; i <= maxnumber; i++)
	{
		sum += arr[i];
	}
	return sum;
	

}

float avaregearrnum(int arr[100], int maxnumber) {

	int sum = 0;
	for (int i = 1; i <= maxnumber; i++)
	{
		sum += arr[i];
	}

	float avarege = (float)sum/maxnumber ;
	return avarege;

	
}





int main()
{
	int arr[100];
	int maxnumber =0;

	readnumarr( arr, maxnumber);
	printnumarr(arr, maxnumber);

	cout << "******************************************************\n";
	cout << "Sum = " << sumarrynum(arr, maxnumber)<< endl;
	cout << "Avarege = " << avaregearrnum(arr, maxnumber) << endl;



}


