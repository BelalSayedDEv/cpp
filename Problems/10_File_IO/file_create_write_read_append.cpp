#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createAndWriteFile(string filename) {

    ofstream file(filename, ios::out); // إنشاء ملف وكتابة جديدة
  
    if (file.is_open()) {
        cout << "Enter your name: ";
        string name;
        getline(cin, name);

        cout << "Enter your age: ";
        int age;
        cin >> age;
        cin.ignore(); // لمسح الـ \n من البافر

        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        cout << "✅ File created and data saved successfully.\n";
        file.close();
    } else {
        cout << "❌ Error: could not open file for writing.\n";
    }
}

void readFile(string filename) {
    ifstream file(filename, ios::in); // فتح الملف للقراءة
    if (file.is_open()) {
        cout << "\n📖 File content:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "❌ Error: could not open file for reading.\n";
    }
}

void appendToFile(string filename) {
    ofstream file(filename, ios::app); // فتح الملف في وضع الإضافة
    if (file.is_open()) {
        cout << "\nEnter something to add: ";
        string newLine;
        getline(cin, newLine);
        file << newLine << endl;
        cout << "✅ Data added successfully.\n";
        file.close();
    } else {
        cout << "❌ Error: could not open file for appending.\n";
    }
}

int main() {
    string filename = "data.txt";
    int choice;

    do {
        cout << "\n==== File Manager ====\n";
        cout << "1. Create and write file\n";
        cout << "2. Read file\n";
        cout << "3. Append to file\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            createAndWriteFile(filename);
            break;
        case 2:
            readFile(filename);
            break;
        case 3:
            appendToFile(filename);
            break;
        case 4:
            cout << "👋 Exiting program.\n";
            break;
        default:
            cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}