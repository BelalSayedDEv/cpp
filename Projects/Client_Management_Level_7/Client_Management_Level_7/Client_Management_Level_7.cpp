#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

const string filename = "client.txt";
const string delim = "#\\#";

void list() {
    cout << "\n==================================" << endl;
    cout << "         main menu screen        " << endl;
    cout << "==================================\n" << endl;
    cout << "[1] Show Client List" << endl;
    cout << "[2] Add New Client" << endl;
    cout << "[3] Delete Client" << endl;
    cout << "[4] Update Client INFO" << endl;
    cout << "[5] Find Client" << endl;
    cout << "[6] Transactions" << endl;
    cout << "[7] Exit" << endl;
    cout << "==================================" << endl;
}

struct stuser {
    string accountnumber;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markeasdeleted = false;
};

int readnumber(string message) {
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

stuser readuser() {
    stuser user;
    cout << "enter Account_number : ";
    getline(cin >> ws, user.accountnumber);
    cout << "enter pincode : ";
    getline(cin >> ws, user.pincode);
    cout << "enter name_user : ";
    getline(cin >> ws, user.name);
    cout << "enter phone_user : ";
    getline(cin >> ws, user.phone);
    cout << "enter balance_user : ";
    cin >> user.balance;
    cin.ignore();
    return user;
}

string converttoline(stuser user, string delim) {
    string line = "";
    line += user.accountnumber + delim;
    line += user.pincode + delim;
    line += user.name + delim;
    line += user.phone + delim;
    line += to_string(user.balance);
    return line;
}

void pushlinetofile(string line, string filename) {
    fstream file;
    file.open(filename, ios::out | ios::app);
    if (file.is_open()) {
        file << line << endl;
        file.close();
        cout << "client added successfully" << endl;
    }
    else {
        cout << "error opening file!" << endl;
    }
}

vector<string> split(string line, string delim) {
    vector<string> vusers;
    short pos = 0;
    string word = "";
    pos = line.find(delim);
    while (pos != string::npos) {
        word = line.substr(0, pos);
        vusers.push_back(word);
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
    }
    vusers.push_back(line);
    return vusers;
}

stuser convertlinetostruct(string line, string delim) {
    stuser user;
    vector<string> vstring = split(line, delim);
    user.accountnumber = vstring[0];
    user.pincode = vstring[1];
    user.name = vstring[2];
    user.phone = vstring[3];
    user.balance = stod(vstring[4]);
    return user;
}

vector<stuser> readdatafromfile(string filename) {
    vector<stuser> vuser;   
    fstream file;
    stuser user;
    string line;
    file.open(filename, ios::in);

    if (file.is_open()) {
        while (getline(file, line)) {
            user = convertlinetostruct(line, "#\\#");
            vuser.push_back(user);
        }
        file.close();
    }
    return vuser;
}

void printusers(const stuser& user) {
    cout << "-----------------------------------" << endl;
    cout << "Account_number : " << user.accountnumber << endl;
    cout << "pincode : " << user.pincode << endl;
    cout << "name_user : " << user.name << endl;
    cout << "phone_user : " << user.phone << endl;
    cout << "balance_user : " << user.balance << endl;
    cout << "-----------------------------------\n" << endl;
}

void showallusers(vector<stuser>& vuser, string filename) {
    vuser = readdatafromfile(filename);
    cout << "------ count of clients (" << vuser.size() << ") -------\n";
    for (stuser& user : vuser) {
        printusers(user);
    }
}

bool markeasdeleted(vector<stuser>& vuser, string accountnumber) {
    for (stuser& user : vuser)
    {
        if (user.accountnumber == accountnumber)
        {
            user.markeasdeleted = true;
            return true;
        }
    }
    return false;
}

bool finduser(vector<stuser>& vuser, string accountnumber, stuser& user) {
    for (stuser& c : vuser)
    {
        if (c.accountnumber == accountnumber)
        {
            user = c;
            return true;
        }
    }
    return false;
}

void savevectortofile(string filename, vector<stuser>& vuser) {
    fstream file;
    string line;

    file.open(filename, ios::out);
    if (file.is_open()) {

        for (stuser& use : vuser) {
            if (!use.markeasdeleted) {
                line = converttoline(use, delim);
                file << line << endl;
            }
        }
        file.close();
    }
}

void deleteuser(vector<stuser>& vuser, string accountnumber, string filename) {

    vuser = readdatafromfile(filename);  

    cout << "Enter an Account Number : ";
    cin >> accountnumber;
    cin.ignore();

    stuser user;
    char delet = 'n';

    if (finduser(vuser, accountnumber, user)) {

        printusers(user);

        cout << "Do you want to delete this user ? y/n" << endl;
        cin >> delet;

        if (tolower(delet) == 'y')
        {
            markeasdeleted(vuser, accountnumber);
            savevectortofile(filename, vuser);
            cout << "User deleted successfully " << endl;
        }
    }
    else
        cout << "User not found!" << endl;
}

stuser readupateddata(string accountnumber) {
    stuser user;
    user.accountnumber = accountnumber;
    cout << "enter pincode : ";
    getline(cin >> ws, user.pincode);
    cout << "enter name_user : ";
    getline(cin >> ws, user.name);
    cout << "enter phone_user : ";
    getline(cin >> ws, user.phone);
    cout << "enter balance_user : ";
    cin >> user.balance;
    cin.ignore();
    return user;
}

void upadteuser(vector<stuser>& vuser, string filename) {

    vuser = readdatafromfile(filename); 

    string accountnumber;
    cout << "Enter an Account Number : ";
    cin >> accountnumber;
    cin.ignore();

    bool found = false;

    for (stuser& use : vuser) {

        if (use.accountnumber == accountnumber) {
            use = readupateddata(accountnumber);
            cout << "User updated successfully " << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "This user is not found" << endl;
    }

    savevectortofile(filename, vuser);
}

void finduserfromfile(vector<stuser>& vuser, string accountnumber, stuser& user) {

    cout << "please enter your id to search " << endl;  
    cin >> accountnumber;
    if (finduser(vuser, accountnumber,user))
    {
        printusers(user);
    }
    else
    {
        cout << "this user is not found" << endl;
    }
}

void listtransactios() {
    cout << "\n==================================" << endl;
    cout << "         Transactions menu screen        " << endl;
    cout << "==================================\n" << endl;
    cout << "[1] Deposit." << endl;
    cout << "[2] withdraw." << endl;
    cout << "[3] Total Balances." << endl;
    cout << "[4] Main menue." << endl;
    cout << "==================================" << endl;
}

void deposit(vector<stuser>& vuser, string filename) {
    bool found = false;
    vuser = readdatafromfile(filename);
    string accountnumber;
    cout << "\n=-----------------------------------" << endl;
    cout << "            deposit screen          " << endl;
    cout << "-----------------------------------\n" << endl;
    cout << "please enter Account_number";
    getline(cin, accountnumber);

    for (stuser &user : vuser) {

        if (user.accountnumber == accountnumber)
        {
            found = true;
            cout << "the following are the clint details" << endl;
            printusers(user);
            
            cout << "please enter deposit amount ?" ;
            double amount = 0;
            cin >> amount;
            
            char yesorno = 'n';
            cout << "Are you sure you want perform this transaction ? y/n ?";
            cin >> yesorno;
            if (tolower(yesorno) == 'y')
            {
                user.balance = user.balance - amount;
                cout << "the balance become : " << user.balance << endl;
            }
        }
    }

    if (!found) {
        cout << "client with [" << accountnumber << "] does not exist. " << endl;
    }

    savevectortofile(filename, vuser);
}

void programtransaction(vector<stuser>& vuser, string filename) {
    int number;
    number = readnumber("choose what do you want to do ? [1 to 4] ? ");

    do
    {
        if (number == 1)
        {
            deposit(vuser, filename);
        }
        else if (number == 2)
        {

        }
        else if (number == 3)
        {

        }
    } while (number != 4);

}







void program() {

    vector<stuser> vuser;

    list();
    int choise = readnumber("please enter what you want (1 to 6)");

    while (choise != 7) {

        if (choise == 1) {
            showallusers(vuser, filename);
        }
        else if (choise == 2) {
            stuser user = readuser();
            string line = converttoline(user, delim);
            pushlinetofile(line, filename);
        }
        else if (choise == 3) {
            string accountnumber;
            deleteuser(vuser, accountnumber, filename);
        }
        else if (choise == 4) {
            upadteuser(vuser, filename);
        }
        else if (choise == 5) {
            string accountnumber;
            stuser user;
            finduserfromfile(vuser, accountnumber, user);
        }
        else if (choise == 6) {
            programtransaction(vuser, filename);
        }
        list();
        choise = readnumber("please enter what you want (1 to 6)");
    }
}

int main() {
    program();
    return 0;
}
