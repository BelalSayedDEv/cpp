#include <iostream>
using namespace std;



enum engender
{
    male , female
};


enum enstatus
{
    married, single
};


struct stemployee {

    string name;
    int age;
    string country;
    string city;
    int salary;
    enstatus status;
    engender gender;


};


void reademployee(stemployee &emp) {

    cout << "please enter your name" << endl;
    cin >> emp.name;
    cout << "please enter your age" << endl;
    cin >> emp.age;
    cout << "please enter your country" << endl;
    cin >> emp.country;
    cout << "please enter your city" << endl;
    cin >> emp.city;
    cout << "please enter your salary" << endl;
    cin >> emp.salary;
    emp.gender = engender::male;
    emp.status = enstatus::married;

}

int yearlysalary(int salary) {

    int yearlsalary = salary * 12;
    return yearlsalary;



}

void printemployee(stemployee emp) {


    cout << "name :" << emp.name << endl;
    cout << "age   :" << emp.age << endl;
    cout << "counntruy : " << emp.country << endl;
    cout << "city  :" << emp.city << endl;
    cout << "month salary :" << emp.salary << endl;
    cout << "yearly salary " << yearlysalary(emp.salary) <<endl;
    cout << "gender :" << emp.gender<< endl;
    cout << "status :" << emp.status<<endl;
    cout << "gender" << emp.gender;
    cout << "status :" << emp.status;
}




int main() {
    stemployee new_employee;
    reademployee(new_employee);
    printemployee(new_employee);

}




