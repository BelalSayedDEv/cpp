#include<iostream>
using namespace std;

double readnumber(string message) {

    double number;
    cout << message << endl;
    cin >> number;
    return number;
}

int readchois() {
    int number;
    cout << "choose type : " << endl;
    cout << "1- int \n 2- float\n 3- double" <<endl;
    cin >> number;
    return number;
}
int clc (int num1,int num2) {
    return num1+num2;
}
float clc (float num1,float num2) {
    return num1+num2;
}
double clc (double num1,double num2) {
    return num1+num2;
}


void resultchoise(int number, double num1, double num2) {

    (number ==1) ? cout << clc((int)num1,(int)num2): ((number ==2) ? cout<< clc((float)num1,(float)num2)  :  cout<< clc((double)num1,(double)num2));
}



int main()
{
    double num1 = readnumber("please enter your first number ") ;
    double num2 = readnumber("please enter your second number ") ;
    int choise = readchois();
    cout << "the result is : " ;
    resultchoise(choise,num1,num2);
    

    return 0;
}