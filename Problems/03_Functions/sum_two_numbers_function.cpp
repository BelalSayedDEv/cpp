

#include <iostream>
using namespace std;
#include<string>


////...............................adress 
//struct  stadress {
//    string city, country, street;
//};
//
//
////..............................contact information
//
//struct stcontact {
//    stadress adress;
//    string phone;
//    string email;
//    string zipcode;
//};
//
////............................person information  
//struct stperson {
//    stcontact contact;
//    string name;
//    int age;
//    encolor favouritcolor;
//    engender gender;
//
//};
//
////............................enum color..........
//enum encolor
//{   red, blue,green,white };
////............................enum gender..........
//enum engender
//{
//    male,female
//};
//
//// .......................first fuction............................
//
//void myfunction()
//
//{
//    stperson person1;
//    cout << "please enter your name " << endl;
//  
//   
// 
//
//
//
//}


////////////////////////example two/////////////////////
void someprocducers()
{
    int num1, num2;

    cout << "please enter number1\n";
    cin >> num1;
    cout << "please enter number2\n";
    cin  >> num2;
    int sum_someprocducers = num1 + num2;
    
    cout << "the sum of function procducers is :" << sum_someprocducers << endl;
}
//////////////example two /////////////////////////////
int mysomefunction() {
    int num1, num2;

    cout << "please enter number1\n";
    cin >> num1;
    cout << "please enter number2\n";
    cin >> num2;
    int sum_function = num1 + num2;
    return sum_function;
}



int main()
{
    someprocducers();

    int result;
    result = mysomefunction();
    cout << "the result of the function is :" << result << endl;

   
}

