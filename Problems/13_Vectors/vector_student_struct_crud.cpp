#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct ststudent {
    string firstname;
    int age;
    float grade;
};

//-------------------------------------------------
void readnewstudent(vector<ststudent> &vstudent) {
    ststudent tstudent;
    bool addmore = 1;
    do {
        cout << "please enter your first name: ";
        cin >> tstudent.firstname;
        cout << "please enter your Age: ";
        cin >> tstudent.age;
        cout << "please enter your grade: ";
        cin >> tstudent.grade;

        vstudent.push_back(tstudent);
        cout << "to enter new student 1(yes),0(no): ";
        cin >> addmore;

    } while (addmore);
}

//-------------------------------------------------
void printstudent(const vector<ststudent> &vstudent) {
    cout << "---------------------------------" << endl;
    cout << "       Vector elements is :      " << endl;
    cout << "---------------------------------" << endl;

    for (const ststudent &student : vstudent) {
        cout << setw(14) << "First name :" << setw(8) << student.firstname << endl;
        cout << setw(14) << "Age :" << setw(8) << student.age << endl;
        cout << setw(14) << "grade :" << setw(8) << student.grade << endl;
        cout << " " << endl;
    }

    cout << "Total students: " << vstudent.size() << endl;
}

//-------------------------------------------------
void UpdateGrade(ststudent &student, float newGrade) {
    student.grade = newGrade;
}

//-------------------------------------------------
void updateelement(vector<ststudent> &vstudent) {
    int number;
    cout << "Do you want to update any student's grade? yes(1), no(0): ";
    cin >> number;
    if (number == 0) return;

    string name;
    cout << "Enter the student name to update: ";
    cin >> name;

    bool found = false;
    for (ststudent &student : vstudent) {
        if (student.firstname == name) {
            float newgrade;
            cout << "Enter new grade for " << name << ": ";
            cin >> newgrade;
            UpdateGrade(student, newgrade);
            cout << "Student grade updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";
}

//-------------------------------------------------
void removeelement(vector<ststudent> &vstudent) {
    cout << "---------------------------------" << endl;
    cout << "   Removing last added student : " << endl;
    cout << "---------------------------------" << endl;

    if (!vstudent.empty()) {
        cout << "Removing student: " << vstudent.back().firstname << endl;
        vstudent.pop_back();
    } else {
        cout << "No students to remove.\n";
    }
}

//-------------------------------------------------
int main() {
    vector<ststudent> vstudent;
    readnewstudent(vstudent);

    printstudent(vstudent);
    updateelement(vstudent);
    printstudent(vstudent);

    removeelement(vstudent);
    printstudent(vstudent);

    return 0;
}