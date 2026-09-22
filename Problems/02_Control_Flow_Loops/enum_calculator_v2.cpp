

#include <iostream>
#include <string>

using namespace std;

float readnumber(string message) {
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}


enum entypeopreation {
    add='+',divide='/',subtract='-',multibly='*'
};


entypeopreation readopreationtype() {
    char optype = '+';
    cout << "please enter type of opreation " << endl;
    cin >> optype;
    return (entypeopreation)optype;
}

float opreationtype(float num1, float num2, char opreation) {
    switch (opreation)
    {
    case entypeopreation::add:
        return num1 + num2;
    case entypeopreation::divide:
        return num1 / num2;
    case entypeopreation::multibly:
        return num1 * num2;
    case entypeopreation::subtract:
        return num1 - num2;
    default:
        num1 + num2;
    }
}


int main()
{
    float num1 = readnumber("please enter first number ");
    float num2 = readnumber("please enter second number ");

    entypeopreation optype = readopreationtype();

    cout << "the result is : " << opreationtype(num1, num2, optype);
}

