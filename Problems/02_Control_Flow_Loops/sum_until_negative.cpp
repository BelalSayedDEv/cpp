
#include <iostream>
#include<string>
using namespace std;

int readnumber(string message) {
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}
int prosses() {
    int result = 0;
    int number = 0;
    do
    {
        number = readnumber("please enter onther number");
       

        if (number == -99) {
            break;
        }
        result = number + result;

    } while (number != -99);
    return result;
}

int main()
{
   cout<<"the result is : "<< prosses();
}

