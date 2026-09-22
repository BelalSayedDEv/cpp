
#include <iostream>
using namespace std;

float readelement() {
    float a, b;
    cout << "please enter the element of a " << endl;
    cin >> a;
    cout << "please enter the element of b" << endl;
    cin >> b;
    return a, b;
}

float clcarea(float a, float b) {
    float area = (2 * a - b) / (2 * a + b);
    return area;

}
void printarea(float area) {
    cout << "the area is : " << area << endl;
}
int main()
{
    float a, b;
    readelement();
    printarea(clcarea(a, b));


}


