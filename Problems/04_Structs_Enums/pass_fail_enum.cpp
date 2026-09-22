
#include <iostream>

using namespace std;

#include <string>;

enum enstatus
{
    pass =0 , fail =1
};

int readnum() {
    int num;
    cout << "please enter your sign " << endl;
    cin >> num;
    return num;
}


enstatus checkmark(int num) {
    if (num >= 50)
        return enstatus::pass;
    else
        return enstatus::fail;

}

void printcheck(int num) {

    if (checkmark(num) == enstatus::pass)
        cout << "you passed ";
    else
        cout << "you failed";
}


//string clcusign(int num) {
//
//    if (num>=50)
//    {
//        return "pass";
//    }
//    else
//    {
//        return  "fail";
//    }
//
//}

//void printresult(int num) {
//    cout << "you are : " << clcusign(num) << endl;
//}






int main()
{
    printcheck(readnum());
    
    
}


