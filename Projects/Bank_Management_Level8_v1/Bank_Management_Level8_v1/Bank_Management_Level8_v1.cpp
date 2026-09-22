
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;
const string delim = "#||#";

int readnumber(string message) {

    int number =0 ;
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
struct stuser
{
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
    getline(cin, user.name);\
    cout << "please enter your Account_number " << endl;
    getline(cin, user.acc_number);
    cout << "please enter your phone " << endl;
    getline(cin, user.phone);
    cout << "please enter your pin_number " << endl;
    getline(cin, user.pin_code);
    cout << "please enter your balance " << endl;
    cin.clear();
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
    if (myfile.is_open())
    {
        myfile << line << endl;
        myfile.close();
        cout << "the cleints added successfully" << endl;
    }
    else {
        cout << "the program is not responding , error 404 " << endl;
    }
}

vector<string>split(string line, string delim) {

    vector<string>vuser;
    size_t pos = 0;
    string word = "";
    pos = line.find(delim);
    while (pos !=string::npos)
    {
        word = line.substr(0, pos);

        if (!word.empty()) {
            vuser.push_back(word);
        }
        line.erase(0, pos + delim.length());
        pos = line.find(delim);
        
    }
    if (!line.empty()) {
        vuser.push_back(line);
    }

    return vuser;
}

stuser convertverctoretostruct(string line,string delim) {

    stuser user;
    vector<string> vstring = split(line, delim);

    if (vstring.size() == 5 )
    {
        user.acc_number = vstring[0];
        user.pin_code = vstring[1];
        user.name = vstring[2];
        user.phone = vstring[3];
        user.balance = stoi(vstring[4]);
    }
    return user;
}

void printusers(stuser user) {

    cout << "-----------------------------------" << endl;
    cout << "Account_number : " << user.acc_number << endl; 
    cout << "pincode : " << user.pin_code << endl;
    cout << "name_user : " << user.name << endl;
    cout << "phone_user : " << user.phone << endl; 
    cout << "balance_user : " << user.balance << endl; 
    cout << "-----------------------------------\n\n" << endl;
}

vector<stuser>readfile(string filename, string delim) {
    vector<stuser>vuser;
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
void adduser(string filename,string delim) {
    stuser user;
    user = readfulluser();
    string line;
    line = convertusertoline(user, delim);
    pushtofile(line, filename);

}

void showclient(string filename,string delim) {

    vector<stuser>vuser;
    vuser = readfile(filename, delim);
    for (stuser &c : vuser)
    {
        printusers(c);
    }
}


string readsearchkey(string message) {

    string searchkey;
    cout << message << endl;
    getline(cin, searchkey);
    return searchkey;
}
void pushtofileafterdeltion(vector <stuser> vuser,string filename,string delim) {

    fstream myfile;
    string line ="";
    myfile.open(filename, ios::out | ios::app);
    if (myfile.is_open()) {

        for (stuser &c : vuser)
        {
            if (c.softdelet != true) {
                line = convertusertoline(c, delim);
            }
        }
    }

    myfile.close();
}
void deleteuser(string filename, string delim) {
    string searchkey;
    bool found = false;
    searchkey = readsearchkey("please enter id to search ");
    vector <stuser> vuser;
    vuser = readfile(filename, delim);
    for (stuser &c : vuser )
    {
        if (c.acc_number == searchkey) {
            found = true;
            c.softdelet = true;
        }
    }
    if (found == true)
        pushtofileafterdeltion(vuser, filename, delim);
    else
        cout << "Not Found User " << endl;
}

void updateclient(string filename, string delim) {

    string line = "";
    string searchkey;
    bool found = false;
    searchkey = readsearchkey("please enter id to search ");
    vector <stuser> vuser;
    vuser = readfile(filename, delim);
    for (stuser& c : vuser)
    {
        if (c.acc_number == searchkey) {
            found = true;
            int newrecord = readnumber("please enter the newrecord : ");
            c.balance = newrecord;
        }
    }
    if (found == true) {

        for (stuser &c : vuser )
        {
            line = convertusertoline(c, delim);
            pushtofile(line, filename);
        }
        cout << "The client updated successfully " << endl;
    }
    else
        cout << "Not Found User " << endl;
}

void searchclient(string filename, string delim) {

    string line = "";
    string searchkey;
    bool found = false;
    searchkey = readsearchkey("please enter id to search ");
    vector <stuser> vuser;
    vuser = readfile(filename, delim);
    for (stuser& c : vuser)
    {
        if (c.acc_number == searchkey) {
            found = true;
        }
    }
    if (found) 
        cout << "The client updated successfully " << endl;
    else
        cout << "Not Found User " << endl;
}


struct stmember
{
    string id;
    string password;
    int permation = 0 ;
};

void readthepermations(stmember &member) {
    cout << "do you want to give him fullaccess ?" << endl;
    string choose = "";
    cin >> choose;
    if (choose == "y" || choose == "Y") {
        member.permation = 128;
    }
    cout << "want to access on show client list ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 1;
    cout << "want to access on add new client ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 2;
    cout << "want to access on add delete client ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 4;
    cout << "want to access on add update client ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 8;
    cout << "want to access on add sreach client ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 16;
    cout << "want to access on add transaction client ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 32;
    cout << "want to access on add mange users ?" << endl;
    cin >> choose;
    if (choose == "y" || choose == "Y")
        member.permation += 64;
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
void screanofprinting() {
        cout << "================================================================================================" << endl;
    cout << setw(15) << " | User Name" << setw(15) << " | password" << setw(15) << " | Permissions" << endl;
    cout << "================================================================================================\n" << endl;
}
void printmember(stmember member) {

    cout << " | " << setw(10) << member.id << " | " << setw(10) << member.password << " | " << setw(10) << member.permation;

}

void showlistmember(string filename,string delim) {
    vector<stmember>vmember;
    vmember = readfileofmember(filename, delim);
    screanofprinting();
    for (stmember &m : vmember)
    {
        printmember(m);
    }
}

void addnewuser(string filename,string delim) {
    string line = "";
    stmember member;
    member = readnewmember();
    line = convertmembertoline(member, delim);
    pushtofile(line, filename);
    cout << " user added sucessfully " << endl;
   
}
void deletmember(string filename, string delim) {
    string username;
    vector<stmember>vmember;
    string line="";
    bool found = false;
    string tryagain="y";
    vmember = readfileofmember(filename, delim);
    do
    {
        cout << "enter your username" << endl;
        cin >> username;
        for (stmember& m : vmember)
        {
            if (m.id == username) {
                found = true;

            }
            else
            {
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
                cout << "User name sucessfully" << endl;
            }
        }
        if (found == false)
        {
            cout << "Invaild Username ";
            
        }
        cout << " to try again press y||n" << endl;
        cin >> tryagain;
    } while (tryagain=="y" || tryagain == "Y");

}
void updatemember(string filename, string delim) {
    string username;
    vector<stmember>vmember;
    string line = "";
    bool found = false;
    string tryagain = "y";
    vmember = readfileofmember(filename, delim);
    do
    {
        cout << "enter your username" << endl;
        cin >> username;
        for (stmember& m : vmember)
        {
            if (m.id == username) {
                found = true;
                string newpassword = readsearchkey("please enter the new password") ;
                m.password = newpassword;
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
                cout << "User name sucessfully" << endl;
            }
            else
            {
                line = convertmembertoline(m, delim);
                pushtofile(filename, delim);
                cout << "User name sucessfully" << endl;
            }
        }
        if (found == false)
        {
            cout << "Invaild Username ";

        }
        cout << " to try again press y||n" << endl;
        cin >> tryagain;
    } while (tryagain == "y" || tryagain == "Y");

}
void searchaboutmember(string filename, string delim) {
    string username;
    vector<stmember>vmember;
    string line = "";
    bool found = false;
    string tryagain = "y";
    vmember = readfileofmember(filename, delim);
    do
    {
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
        if (found == false)
        {
            cout << "Invaild Username ";

        }
        cout << " to try again press y||n" << endl;
        cin >> tryagain;
    } while (tryagain == "y" || tryagain == "Y");

}
void processofmanagment() {

    int number = 0;
    bool addmore = false;
    string filename = "member.txt";
    mangescreen();
    number = readnumber("choose: ");
    do
    {
        if (number == 1) {
            showlistmember(filename,delim);
        }
        else if (number == 2)
        {
            addnewuser(filename,delim);
        }
        else if (number == 3)
        {
            deletmember(filename, delim);
        }
        else if (number == 4)
        {
            updatemember(filename, delim);
        }
        else if (number == 5)
        {
            searchaboutmember(filename, delim);
        }
        mangescreen();
        number = readnumber("choose: ");
    } while (number!=6);



}
void program() {

    int number = 0;
    bool addmore = false;
    string filename = "myfile.txt";


    list();
    number = readnumber("please enter your choose ? ");
    do
    {
        if (number == 1)
        {
            showclient(filename, delim);
        }
        else if (number == 2) {
            do
            {
                adduser(filename, delim);
                cout << "do you want to add more client y(1) or no(0) " << endl;
                cin >> addmore;
            } while (addmore);

        }
        else if (number == 3) {
            do
            {
                deleteuser(filename, delim);
                cout << "do you want to delet more client y(1) or no(0) " << endl;
                cin >> addmore;
            } while (addmore);

        }
        else if (number == 4) {
            do
            {
                updateclient(filename, delim);
                cout << "do you want to update more client y(1) or no(0) " << endl;
                cin >> addmore;
            } while (addmore);

        }
        else if (number == 5) {
            do
            {
                searchclient(filename, delim);
                cout << "do you want to search about any client y(1) or no(0) " << endl;
                cin >> addmore;
            } while (addmore);

        }
        list();
        cout << "if you want onther service choose its number " << endl;
        cin >> number;

    } while (number != 8);

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

    if (vstring.size() == 3)
    {
        member.id = vstring[0];
        member.password = vstring[1];
        member.permation = stoi(vstring[2]);
    }
    return member;
}
vector<stmember>readfileofmember(string filenameofmember, string delim) {
    vector<stmember>vmember;
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

void login(string filenameofmember, string delim) {

    vector<stmember> vmember;
    vmember = readfileofmember(filenameofmember, delim);
    string username;
    string password;
    do
    {
        cout << "Username " << endl;
        cin >> username;
        cout << "Password " << endl;
        cin >> password;
        bool found = false;
        for ( stmember &m : vmember)
        {
            if (username == m.id && password == m.password) {
                program();
                found = true;
            }
            
        }
        if (found==false) {
            cout << "Invaild Username and Password ,try again" << endl;
        }

    } while (true);
    
}




int main()
{
    login("member.txt", delim);
    
}


