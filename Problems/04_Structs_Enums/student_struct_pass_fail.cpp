
#include <iostream>
using namespace std;


struct ststudent
{
    int grade1;
    int grade2;
    int grade3;
};
void readgrade(ststudent &student) {
    cout << "please enter your grade1 " << endl;
    cin >> student.grade1;
    cout << "please enter your grade2 " << endl;
    cin >> student.grade2;
    cout << "please enter your grade3 " << endl;
    cin >> student.grade3;


}

void cluclategrad(int grad1 , int grad2, int grad3) {


    float avarege = (grad1 + grad2 + grad3) / 3;
    if (avarege >= 50)
    {
        cout << avarege << endl;
        cout << "pass";
    }
    else
    {
        cout << avarege << endl;

        cout << "fail";
    }

    


}

//******************************************************
struct stperson
{
    int age;
    string license;
};




void readperson(stperson &person) {
    cout << "please enter your age " << endl;
    cin >> person.age;
    cout << "please enter your license between hired and not hired " << endl;
    cin >> person.license;

}

void cluclatelicense(int age , string license) {
     
    if (age >= 21 && license == "hired")
    {
        cout << "hired" << endl;

    }
    else
    {
        cout << "reject";
    }


}





int main()
{
    //stperson person1;
    //readperson(person1);
    //cluclatelicense(person1.age, person1.license);




    ststudent student1;
    readgrade(student1);
    cluclategrad(student1.grade1 , student1.grade2, student1.grade3);

}


