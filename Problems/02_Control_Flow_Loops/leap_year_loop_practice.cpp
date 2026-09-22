
#include <iostream>

#include <string>


       
using namespace std;





bool leapyear(int number) {

    if (number % 400 == 0) {
        return true;
    }
    else if (number % 100 == 0) {
        return false;
    }
    else if (number % 4 == 0) {
        return true;

    }
    else {
        return false;
    }
}
bool leapyearinoneline(int number) {

    return (number % 400 == 0) ? true : (number % 100 != 0 && number % 4 == 0) ? true : false;

}
int numberDaysINFeb(bool ji) {
    if (ji) {
        return 29;
    }
    else
        return 28;
}

int main()
{
   /* int number = 2002;
    int yu = numberDaysINFeb(leapyear(number));
    cout << " the number of days in feb is " << yu << endl;*/



    int i;
    for (i = 0;i < 6; i++) {
        cout << i << endl;
    }

    cout << "\n\n\n i after loop " << ++i << endl;

}
