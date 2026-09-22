
#include <iostream>
using namespace std;

void readelement(float &a, float &b) {

    cout << "please enter the element of a " << endl;
    cin >> a;
    cout << "please enter the element of b" << endl;
    cin >> b;
    
}



float clcarea(float a, float b) {
    const float PI = 3.141592653589793238;
    float area =  PI*(pow(b,2)/4)*((2 * a) - b) / ((2 * a ) + b);
    return area;

}


void printarea(float area) {
    cout << "the area is : " << area << endl;
}
int main()
{
    float a, b;
    readelement(a,b);
    printarea(clcarea(a, b));


}


