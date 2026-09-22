
#include <iostream>

using namespace std;

int readcircle() {
    int l;
    cout << "please enter your lenght" << endl;
    cin >> l;
    return l;
}

float clcarea(int l) {

    const float PI = 3.141592653589793238;

    float area = (pow(l, 2)) / (4 * PI);

    return area;
}
void printarea(float area) {
    cout << "the area is : " << area << endl;
}
int main()
{  
    printarea(clcarea(readcircle()));
}

 