#include<iostream>
using namespace std;


int readnumber(){
    int number;
    cout << "please enter your number" << endl;
    cin >> number;
    while(cin.fail()){
    
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "Invaild number , Enter A number" << endl;
    cin >> number;
    while(number < 0)
    {
    cout << "Enter postive number " << endl;
    cin >> number ;
    }
    
    }
    return number;
}
void printNumbers(int n ,int m){
    
    if(m <= n)
    {
    cout << m << " ";
    printNumbers(n, m + 1);
    }

}



int main()
{
    int N = readnumber();
    int m = 1;
    printf("Entered number : %d \n",N);
    printNumbers(N , 1);
    
    return 0;
}