
#include <iostream>
using namespace std;

//
//struct stpersoninfo
//{
//    string name;
//    string phone;
//    string adress;
//    int age;
//
//};
//
//void readpersoninfo(stpersoninfo &info) {
//    cout << "please enter your name \n";
//    cin >> info.name;
//    cout << "please enter your age" << endl;
//    cin >> info.age;
//    cout << "please enter your adress" << endl;
//    cin >> info.adress;
//    cout << "please enter yor phone \n";
//    cin >> info.phone;
//
//}
//void printinfo(stpersoninfo info) {
//    cout << info.name <<endl;
//    cout << info.age <<endl;
//    cout << info.adress <<endl;
//    cout << info.phone << endl;
//}

 /*stpersoninfo infoperson1;
    readpersoninfo(infoperson1);
    printinfo(infoperson1);*/

enum engender
{
    male,female
};
enum enstatues
{
    marraied ,single
};
struct stperson {
    string name;
    string city;
    string country;
    int age;
    int salary;
    enstatues statues;
    engender gender;
};

void readpersoninfo(stperson &info) {
    cout << "please enter your name" << endl;
    cin >> info.name;
    cout << "please enter your age " << endl;
    cin >> info.age;
    cout << "please enter your city\n";
    cin >> info.city;
    cout << "please enter your country \n";
    cin >> info.country;
    cout << "please enter your salary" << endl;
    cin >> info.salary;
    

}

void printpersoninfo(stperson info) {
    cout << "**********************************" <<endl;
    cout << "name : " << info.name << endl;
    cout << "age : " << info.age << endl;
    cout << "country : " << info.country << endl;
    cout << "monthly salary : " << info.salary << endl;
    cout << "yearly salary : " << info.salary * 12 << endl;
    info.gender = engender::male;
    cout << "gender : " <<info.gender;
    info.statues = enstatues::marraied;



}


int main()
{
    stperson infoperson2;
    readpersoninfo(infoperson2);
    printpersoninfo(infoperson2);
}

