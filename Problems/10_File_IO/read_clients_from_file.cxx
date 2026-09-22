#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct stuser {
    string accountnumber;
    string pincode;
    string name;
    string phone;
    double balance;
};

void makelist() {
    cout << "\n-------- System Manager --------\n";
    cout << "[1] Show All Users\n";
    cout << "[2] Add Users\n";
    cout << "[3] Search User\n";
    cout << "[4] Delete User\n";
    cout << "[0] Exit\n";
    cout << "--------------------------------\n";
}

int readchoise(string message) {
    int number;
    cout << message << endl;
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

stuser readuser() {
    stuser user;
    cout << "Enter Account Number: ";
    getline(cin >> ws, user.accountnumber);
    cout << "Enter Pincode: ";
    getline(cin, user.pincode);
    cout << "Enter Name: ";
    getline(cin, user.name);
    cout << "Enter Phone: ";
    getline(cin, user.phone);
    cout << "Enter Balance: ";
    cin >> user.balance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return user;
}

string convertstructtooneline(stuser user, string delim) {
    string line = "";
    line += user.accountnumber + delim;
    line += user.pincode + delim;
    line += user.name + delim;
    line += user.phone + delim;
    line += to_string(user.balance);
    return line;
}

void pushclintintofile(string namefile, string line) {
    fstream file;
    file.open(namefile, ios::out | ios::app);
    if (file.is_open()) {
        file << line << endl;
        cout << "Client added successfully.\n";
        file.close();
    } else {
        cout << "Error opening file.\n";
    }
}

vector<string> split(string s, string delim) {
    vector<string> vstring;
    string word = "";
    size_t pos = s.find(delim);

    while (pos != string::npos) {
        word = s.substr(0, pos);
        if (!word.empty())
            vstring.push_back(word);
        s.erase(0, pos + delim.length());
        pos = s.find(delim);
    }

    if (!s.empty())
        vstring.push_back(s);

    return vstring;
}

stuser convertlinetostruct(string line, string delim) {
    stuser user;
    vector<string> vstring = split(line, delim);
    if (vstring.size() == 5) {
        user.accountnumber = vstring[0];
        user.pincode = vstring[1];
        user.name = vstring[2];
        user.phone = vstring[3];
        user.balance = stod(vstring[4]);
    }
    return user;
}

vector<stuser> readdatafromfile(string namefile, string delim) {
    vector<stuser> vuser;
    stuser user;
    fstream file;
    file.open(namefile, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                user = convertlinetostruct(line, delim);
                vuser.push_back(user);
            }
        }
        file.close();
    }
    return vuser;
}

void printuser(stuser user) {
    cout << left << setw(15) << user.accountnumber << "|";
    cout << left << setw(15) << user.pincode << "|";
    cout << left << setw(15) << user.name << "|";
    cout << left << setw(15) << user.phone << "|";
    cout << left << setw(15) << user.balance << "|\n";
}

void printallusers(vector<stuser> vuser) {
    cout << "---------------------------------------------------------------\n";
    cout << left << setw(15) << "Acc_Number" << "|";
    cout << left << setw(15) << "Pincode" << "|";
    cout << left << setw(15) << "Client_Name" << "|";
    cout << left << setw(15) << "Phone_Number" << "|";
    cout << left << setw(15) << "Balance" << "|\n";
    cout << "---------------------------------------------------------------\n";

    if (vuser.empty()) {
        cout << "No clients found.\n";
    } else {
        for (stuser &us : vuser)
            printuser(us);
    }

    cout << "---------------------------------------------------------------\n";
}

void updateuser(vector<stuser> vuser, string oldrecord) {
    bool found = false;
    for (stuser &us : vuser) {
        if (us.accountnumber == oldrecord) {
            cout << "\n User found:\n";
            printuser(us);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n User not found.\n";
    }
}

void Additionprocess(string namefile, string delim) {
    stuser user = readuser();
    string line = convertstructtooneline(user, delim);
    pushclintintofile(namefile, line);
}

void program() {

    stuser user;
    vector<stuser> vuser;
    string delim = "#\\#";
    string namefile = "client.txt";
    int choice = 0;

    do {
        makelist();
        choice = readchoise("Please enter your choice:");

        if (choice == 1) {
            vuser = readdatafromfile(namefile, delim);
            printallusers(vuser);
        }
        else if (choice == 2) {
            Additionprocess(namefile, delim);
        }
        else if (choice == 3) {
            string oldrecord;
            cout << "Enter Account Number to search: ";
            cin >> oldrecord;
            vuser = readdatafromfile(namefile, delim);
            updateuser(vuser, oldrecord);
        }
        else if (choice == 4) {
            cout << "Delete feature coming soon.\n";
        }

        if (choice != 0) {
            cout << "\nDo you want to continue? (1 = yes, 0 = no): ";
            cin >> choice;
            cin.ignore();
        }

    } while (choice != 0);
}

int main() {
    program();
    return 0;
}