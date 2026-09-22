#include <iostream>
#include <string>

using namespace std;


int readnumber(string message){
    int number;
    do{
        cout<<message<<endl;
        cin>>number;
        
        
        
        }while(number <=0);
        return number;
    }
string convertstring(int number){
            
            string num = to_string(number);
            return num;
            }
            
void printreverse (string number){
    for (int i=number.length()-1 ; i >=0 ;i--){
        cout << number[i]<<endl;
        }
    }





int main()
{
	printreverse(convertstring(readnumber ("please enter positive number ")));
}