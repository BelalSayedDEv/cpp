

#include <iostream>
using namespace std;
#include <string>;

float readnumber(string message) {
    
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}
enum entypeopreation
{
    add = '+', subtract = '-', multiply = '*', divide = '/'
};


entypeopreation readtypeopreation() {
    char ot = '+';
    cout << "please enter opreation type (+ - / *)" << endl;
    cin >> ot;
    return (entypeopreation)ot;

};

float clc(float num1, float num2, char opereation) {
    switch (opereation)
    {
    case entypeopreation::add :
        return num1 + num2;
    case entypeopreation::divide:
        return num1 / num2;
    case entypeopreation ::multiply:
        return num1 * num2;
    case entypeopreation::subtract:
        return num1 - num2;        
    default:
        return num1 + num2;
    }
}


int main()
{
    float num1 = readnumber(" please enter first number ");
    float num2 = readnumber("please enter second number ");

    entypeopreation optype = readtypeopreation();

    cout << "the result = " << clc(num1, num2, optype);


}


