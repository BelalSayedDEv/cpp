#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;
const string delim = "#||#";

int readnumber(string message) {
    int number = 0;
    cout << message;
    cin >> number;
    return number;
}

void list() {
    cout << "\n==================================" << endl;
    cout << "          main menue screen         " << endl;
    cout << "==================================\n" << endl;
    cout << "[1] Show CLient list" << endl;
    cout << "[2] Add New Client" << endl;
    cout << "[3] Delete Client" << endl;
    cout << "[4] Update Client INFO" << endl;
    cout << "[5] Find CLient" << endl;
    cout << "[6] transactions" << endl;
    cout << "[7] manage Users" << endl;
    cout << "[8] logout" << endl;
    cout << "==================================" << endl;
}

struct stuser {
    string name;
    string acc_number;
    int balance;
    string phone;
    string pin_code;
    bool softdelet = false;
};

stuser readfulluser() {
    stuser user;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nplease enter your name " << endl;
    getline(cin, user.name);
    cout << "please enter your Account_number " << endl;
    getline(cin, user.acc_number);
    cout << "please enter your phone " << endl;
    getline(cin, user.phone);
    cout << "please enter your pin_number " << endl;
    getline(cin, user.pin_code);
    cout << "please enter your balance " << endl;
    cin >> user.balance;
    return user;
}

string convertusertoline(stuser user, string delim) {
    string line = "";
    line += user.acc_number + delim;
    line += user.pin_code + delim;
    line += user.name + delim;
    line += user.phone + delim;
    line += to_string(user.balance);
    return line;
}

void pushtofile(string line, string filename) {
    fstream myfile;
    myfile.open(filename, ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << line << endl;
        myfile.close();
        cout << "the cleints added successfully" << endl;
    }
    else {
        cout << "the program is not responding , error 404 " << endl;
    }
}

vector<string> split(string line, string delim) {
    vector<string> vuser;
    size_t pos = 0;
    string word = "";
    pos = line.find(delim);
    while (pos != string::npos) {
        word = line.substr(0, pos);
        if (!word.empty()) vuser.push_back(word);
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
    }
    if (!line.empty()) vuser.push_back(line);
    return vuser;
}

stuser convertverctoretostruct(string line, string delim) {
    stuser user;
    vector<string> vstring = split(line, delim);
    if (vstring.size() == 5) {
        user.acc_number = vstring[0];
        user.pin_code = vstring[1];
        user.name = vstring[2];
        user.phone = vstring[3];
        user.balance = stoi(vstring[4]);
    }
    return user;
}
void screanofprintingclient() {
    cout << "\n================================================================================================" << endl;
    cout <<" | " << setw(15) << "Account_id" << " | " << setw(10) << "pincode" << " | " << setw(15) << "Name" ;
    cout << " | " << setw(13) << "phone_user" << " | " << setw(10) << "Balance" << endl;
    cout << "================================================================================================\n" << endl;
}
void printusers(stuser user) {

    cout << " | " << setw(15) << user.acc_number ;
    cout << " | " << setw(10) << user.pin_code;
    cout << " | " << setw(15) << user.name;
    cout << " | " << setw(13) << user.phone;
    cout << " | " << setw(10) << user.balance << endl;
}

vector<stuser> readfile(string filename, string delim) {
    vector<stuser> vuser;
    stuser user;
    string line;
    fstream myfile;
    myfile.open(filename, ios::in);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            user = convertverctoretostruct(line, delim);
            vuser.push_back(user);
        }
        myfile.close();
    }
    return vuser;
}

void adduser(string filename, string delim) {
    stuser user = readfulluser();
    string line = convertusertoline(user, delim);
    pushtofile(line, filename);
}

void showclient(string filename, string delim) {

    vector<stuser> vuser = readfile(filename, delim);
    screanofprintingclient();
    for (stuser& c : vuser)
        printusers(c);

    cout << "================================================================================================" << endl;

}

string readsearchkey(string message) {
    string searchkey;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << message << endl;
    getline(cin, searchkey);
    return searchkey;
}

void pushtofileafterdeltion(vector<stuser> vuser, string filename, string delim) {
    fstream myfile;
    myfile.open(filename, ios::out);
    if (myfile.is_open()) {
        for (stuser& c : vuser) {
            if (!c.softdelet) {
                string line = convertusertoline(c, delim);
                myfile << line << endl;
            }
        }
        myfile.close();
    }
}

void deleteuser(string filename, string delim) {
    string searchkey = readsearchkey("\nplease enter id to search ");
    vector<stuser> vuser = readfile(filename, delim);
    bool found = false;
    for (stuser& c : vuser) {
        if (c.acc_number == searchkey) {
            c.softdelet = true;
            found = true;
        }
    }
    if (found)
    {
        pushtofileafterdeltion(vuser, filename, delim);
        cout << "\nthe client deleted successfully" << endl;
    }

    else cout << "Not Found User " << endl;
}

void updateclient(string filename, string delim) {
    string searchkey = readsearchkey("please enter id to search ");
    vector<stuser> vuser = readfile(filename, delim);
    bool found = false;
    for (stuser& c : vuser) {
        if (c.acc_number == searchkey) {
            int newrecord = readnumber("please enter the newrecord : ");
            c.balance = newrecord;
            found = true;
        }
    }
    if (found) pushtofileafterdeltion(vuser, filename, delim);
    else cout << "Not Found User " << endl;
}

void searchclient(string filename, string delim) {
    string searchkey = readsearchkey("please enter id to search ");
    vector<stuser> vuser = readfile(filename, delim);
    bool found = false;
    for (stuser& c : vuser) if (c.acc_number == searchkey) found = true;
    if (found) cout << "The client found successfully" << endl;
    else cout << "Not Found User " << endl;
}

// =======================
// MEMBERS & PERMISSIONS
// =======================
struct stmember {
    string id;
    string password;
    int permation = 0;
};

void readthepermations(stmember& member) {
    cout << "do you want to give him fullaccess ?" << endl;
    string choose = "";
    cin >> choose;
    if (choose == "y" || choose == "Y") member.permation = 128;

    cout << "want to access on show client list ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 1;

    cout << "want to access on add new client ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 2;

    cout << "want to access on delete client ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 4;

    cout << "want to access on update client ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 8;

    cout << "want to access on search client ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 16;

    cout << "want to access on transactions ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 32;

    cout << "want to access on manage users ?" << endl;
    cin >> choose; if (choose == "y" || choose == "Y") member.permation += 64;
}

stmember readnewmember() {
    stmember member;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "please enter your id ?" << endl;
    getline(cin >> ws, member.id);
    cout << "please enter your password ?" << endl;
    getline(cin >> ws, member.password);
    readthepermations(member);
    return member;
}

string convertmembertoline(stmember member, string delim) {
    string line = "";
    line += member.id + delim;
    line += member.password + delim;
    line += to_string(member.permation);
    return line;
}

stmember convertlinetostmemeber(string line, string delim) {
    stmember member;
    vector<string> vstring = split(line, delim);
    if (vstring.size() == 3) {
        member.id = vstring[0];
        member.password = vstring[1];
        member.permation = stoi(vstring[2]);
    }
    return member;
}

vector<stmember> readfileofmember(string filenameofmember, string delim) {
    vector<stmember> vmember;
    stmember member;
    string line;
    fstream myfile;
    myfile.open(filenameofmember, ios::in);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            member = convertlinetostmemeber(line, delim);
            vmember.push_back(member);
        }
        myfile.close();
    }
    return vmember;
}

// PRINT MEMBERS
void screanofprinting() {
    cout << "================================================================================================" << endl;
    cout << setw(15) << " | User Name" << setw(15) << " | password" << setw(15) << " | Permissions" << endl;
    cout << "================================================================================================\n" << endl;
}

void printmember(stmember member) {
    cout << " | " << setw(10) << member.id << " | " << setw(10) << member.password << " | " << setw(10) << member.permation << endl;
}

void deletmember(string filename, string delim) {
    string username;
    vector<stmember>vmember;
    string line = "";
    bool found = false;
    string tryagain = "y";
    vmember = readfileofmember(filename, delim);
    do { 
        cout << "enter your username" << endl;
        cin >> username;
        for (stmember& m : vmember) {
            if (m.id == username) {
                found = true;
            } else {
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
                cout << "User name sucessfully" << endl;
            } 
        } 
        if (found == false) {
            cout << "Invaild Username ";
        } 
        cout << " to try again press y||n" << endl;
        cin >> tryagain;
    } while (tryagain == "y" || tryagain == "Y");
}

void updatemember(string filename, string delim) {

    string username;
    vector<stmember>vmember; 
    string line = "";
    bool found = false;
    string tryagain = "y";
    vmember = readfileofmember(filename, delim);
    do {
        cout << "enter your username" << endl;
        cin >> username;
        for (stmember& m : vmember) {
            if (m.id == username) {
                found = true;
                string newpassword = readsearchkey("please enter the new password");
                m.password = newpassword;
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
            }
            else {
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
            }
            if (found == false) {
                cout << "Invaild Username ";
            }
            else
            {
                cout << "Password updated sucessfully" << endl;
            }
            cout << " to try again press y||n" << endl;
            cin >> tryagain;
        }
    } while (tryagain == "y" || tryagain == "Y");
}


void searchaboutmember(string filename, string delim) {
    string username;
    vector<stmember>vmember;
    string line = "";
    bool found = false;
    string tryagain = "y";
    vmember = readfileofmember(filename, delim);
    do {
        cout << "enter your username" << endl;
        cin >> username;
        for (stmember& m : vmember) 
        { 
            if (m.id == username) {
                screanofprinting();
                printmember(m);
                found = true;
            } 
        } 
        if (found == false) { 
            cout << "Invaild Username ";
        } 
        cout << " to try again press y||n" << endl;
        cin >> tryagain;
    } while (tryagain == "y" || tryagain == "Y");
}
// MANAGE SCREEN
void mangescreen() {
    cout << "\n==================================" << endl;
    cout << "      mange users menue screen         " << endl;
    cout << "==================================\n" << endl;
    cout << "[1] List Users." << endl;
    cout << "[2] Add New user." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client INFO." << endl;
    cout << "[5] Find User." << endl;
    cout << "[6] main menue." << endl;
    cout << "==================================" << endl;
}

// ADD, UPDATE, DELETE MEMBERS
void showlistmember(string filename, string delim) {
    vector<stmember>vmember = readfileofmember(filename, delim);
    screanofprinting();
    for (stmember& m : vmember) printmember(m);
}

void addnewuser(string filename, string delim) {
    stmember member = readnewmember();
    string line = convertmembertoline(member, delim);
    pushtofile(line, filename);
    cout << " user added sucessfully " << endl;
}

void processofmanagment() {
    int number = 0;
    string filename = "member.txt";
    mangescreen();
    number = readnumber("choose: ");
    do {   
        if (number == 1) {
            showlistmember(filename, delim);
        }
        else if (number == 2) {
            addnewuser(filename, delim);
        }
        else if (number == 3) {
            deletmember(filename, delim);  // delete member
        }
        else if (number == 4) {
            updatemember(filename, delim);  // update member
        }
        else if (number == 5) {
            searchaboutmember(filename, delim);  // search member
        }
        mangescreen();
        number = readnumber("choose: ");
    } while (number != 6);  // 6 = return to main menu
}
bool Checkisallowed(stmember member, int allowedpermation) {

  return ((member.permation & allowedpermation) == allowedpermation);
}
void program(stmember member) {
    int number = 0;
    bool addmore = false;
    string filename = "myfile.txt";
    do {
        list();
        number = readnumber("please enter your choose ? ");
        if (number == 1)
        {
            if (Checkisallowed(member, 1))
            {
                showclient(filename, delim);
            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
        else if (number == 2) {

            if (Checkisallowed(member, 2))
            {
                do {
                    adduser(filename, delim);
                    cout << "do you want to add more client y(1) or no(0) " << endl;
                    cin >> addmore;
                } while (addmore);
            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
        else if (number == 3) {

            if (Checkisallowed(member, 4))
            {
                do {
                    deleteuser(filename, delim);
                    cout << "do you want to delet more client y(1) or no(0) " << endl;
                    cin >> addmore;
                } while (addmore);
            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
        else if (number == 4)
        {
            if (Checkisallowed(member, 8))
            {
                do
                {
                    updateclient(filename, delim);
                    cout << "do you want to update more client y(1) or no(0) " << endl;
                    cin >> addmore;
                } while (addmore);
            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
        else if (number == 5) {
            if (Checkisallowed(member, 16))
            {
                do
                {
                    searchclient(filename, delim);
                    cout << "do you want to search about any client y(1) or no(0) " << endl;
                    cin >> addmore;
                } while (addmore);
            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }
        }
        else if (number == 6) {
            if (Checkisallowed(member, 32))
            {
                
                    cout << "this service is coming soon " << endl;

            }
            else
            {
                cout << "\nYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
        else if (number == 7) {
            if (Checkisallowed(member, 64))
            {
                processofmanagment();
            }
            else
            {
                cout << "\nxYou do not have access to this service." << endl;
                cout << "please contact to your manger" << endl;
            }

        }
    } while (number != 8);
}

// LOGIN
void login(string filenameofmember, string delim) {
    vector<stmember> vmember = readfileofmember(filenameofmember, delim);
    string username, password;
    bool found = false;
    do {
        cout << "\nUsername " << endl; cin >> username;
        cout << "Password " << endl; cin >> password;
        found = false;
        for (stmember& m : vmember) {
            if (username == m.id && password == m.password) {
                
                program(m);
                found = true;
                break;
            }
        }
        if (!found) cout << "\nInvaild Username and Password ,try again" << endl;
    } while (true);
}

// PROGRAM MAIN MENU

// MAIN
int main() {

    login("member.txt", delim);
}
