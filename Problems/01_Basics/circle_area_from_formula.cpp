

#include <iostream>
using namespace std;

void readelement(float& a, float& b, float& c) {

    cout << "please enter the element of a" << endl;

    cin >> a;

    cout << "please enter the element of b" << endl;
    
    cin >> b;

    cout << "please enter the element of c " << endl;
    cin >> c;

}

float clcarea(float a, float b, float c) {

    const float PI = 3.141592653589793238;

    const float p = (a + b + c) / 2;

    float area = PI * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);

    return area;
}
void printarea(float area) {

    cout << "the area is : " << area << endl;
}

int main()
{
    float a, b, c;
    readelement(a, b, c);
    printarea(clcarea(a, b, c));

}


