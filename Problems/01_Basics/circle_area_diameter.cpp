#include <iostream>
#include <string>

    using namespace std;


   /* enum enstatus
    {
        pass = 0, fail = 1
    };

    void readnumber(int& num1,int &num2,int &num3) {

        cout << "please enter the first number " << endl;
        cin >> num1;
        cout << "please enter the second number " << endl;
        cin >> num2;
        cout << "please enter the third number  " << endl;
        cin >> num3;
    }

    float clcuavarege(int num1, int num2, int num3) {
        return(float)(num1 + num2 + num3) / 3;
    }

    enstatus checkavarege(float total) {
        if (total >= 50)
            return enstatus::pass;
        else
            return enstatus::fail;
    
    }

    void printresulte(float total) {

        cout << "the Avarege = " << total << endl;
        if (checkavarege(total) == enstatus::pass)
            cout << "you passed";
        else
            cout << "you falied";
    }
    */

    /****************************************************************************************************************************/

    /*void readnumbers(int& num1, int& num2 ,int &num3) {
        cout << "please enter the first number " << endl;
        cin >> num1;
        cout << "please enter the second number " << endl;
        cin>> num2;
        cout << "please enter the third number" << endl;
        cin >> num3;
    }

    int checkmax(int num1 , int num2 ,int num3) {
        if (num1 > num2 && num1 > num3)
            return num1;
        else if (num2 > num1 && num2 > num3)
            return num2;
        else
            return num3;

    }
    void printresult(int max){
        cout << "the big number is  " << max << endl;
    }*/
    /******************************************************************************************************************************/

    /*void readnumbers(int& num1, int& num2 ) {
        cout << "please enter the first number " << endl;
        cin >> num1;
        cout << "please enter the second number " << endl;
        cin >> num2;
    }

    int swaping(int &num1, int &num2 ) {
        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
        return num1;
        return num2;
    }
    void printnumbers(int num1, int num2) {
        cout << "the first number after swaping is : " << num1 << endl;
        cout << "the second number after swaping is : " << num2 << endl;
    }*/
    /*****************************************************************************************************************/

    float readnumbers( )
    {
        float d;
        cout << "please enter the diamater" << endl;
        cin >> d;
        return d;
    }

    float clcuarea(float d) {
        const float pi = 3.141592653589793238;
        float area = pi * pow(d, 2)* 0.25;
        return area;
    }
    void printarea(float area) {
        cout << "the area is : " << area << endl;
    }
    /************************************************************************************************************/
    
    



    int main()
    {
        /*int num1, num2, num3;
        readnumber(num1, num2, num3);
        printresulte(clcuavarege(num1, num2, num3));*/
        /********************************************************************************************************/
        /*int num1, num2 ,num3;
        readnumbers(num1, num2, num3);
        printresult(checkmax(num1,num2 ,num3));*/
        /********************************************************************************************************/
        /*int num1, num2,temp;
        readnumbers(num1, num2);
        swaping(num1, num2);
        printnumbers(num1, num2);*/
        /********************************************************************************************************/
        printarea(clcuarea(readnumbers()));
        /********************************************************************************************************/


    }