#include<iostream>
#include<iomanip>
using namespace std;


struct ststudent {
    string name;
    int age;
    float grade;
};


int readnumber() {
    int number ;
    cout << "Enter number of student : " << endl;
    cin >> number;
    return number;
}

ststudent* allocatmemory(int number) {

    ststudent* student= new ststudent[number];
    return student;
}

void readstudent(ststudent * student,int n) {

    for(int i =0; i< n; i++) {
        cout << "Enter student "<<i+1 << endl;
        cout << "name: ";
        cin >> (student +i)->name;
        cout << "age: ";
        cin >> (student +i)->age;
        cout << "grade: ";
        cin >> (student +i)->grade;
    }
}
void printstudent(ststudent *student,int n) {

    for(int i =0; i< n; i++) {
        cout << "----------------------------" << endl;
        cout << "Information'student"<<i+1 << endl;
        cout << "----------------------------" << endl;
        cout << "name: ";
        cout << (student +i)->name<<endl;
        cout << "age: ";
        cout <<(student +i)->age <<endl;
        cout << "grade: ";
        cout<< (student +i)->grade<<endl;
        cout << "----------------------------\n" << endl;

    }

}
float clcaverage (ststudent *student,int n)
{
    float sum = 0;

    for(int i =0; i< n; i++) {
        sum+= (student+i)->grade;
    }

    return (float)sum/n;
}

ststudent * deallocatememory(ststudent * &student) {

    delete[] student;
    student= nullptr;
    cout << "the memory is realsed" << endl;
}

void update(ststudent*student,int n) {
    bool addmore = true;
    string oldname = "";
    float newgrade= 0.1;

    do {

        cout << "enter student's name " << endl;
        cin >> oldname;
        bool found =false;
        for(int i =0; i< n; i++) {
            if((student +i)->name ==oldname) {
                cout << "enter new grade " << endl;
                cin>>newgrade;
                (student +i)->grade = newgrade;
                found = true;
            }
        }
        if (!found) {
            cout << "-----------------------------------------" << endl;
            cout << "student is not found try onther student" << endl;
            cout << "-----------------------------------------" << endl;
        }
        cout << "do you want any update yes(1),no(0)" << endl;
        cin >> addmore;
    }
    while(addmore);
}

int main()
{
    int number = readnumber();
    ststudent*student = allocatmemory(number);
    readstudent(student,number);
    printstudent(student,number);
    cout << "the avarege grades to all students " << endl;
    cout << "----------------------------" << endl;
    cout << "grade : " <<clcaverage(student,number)<< endl;
    cout << "----------------------------" << endl;
    update(student,number);
    printstudent(student,number); 
    cout << "----------------------------" << endl;
    deallocatememory(student);
    cout << "----------------------------" << endl;
    return 0;
}