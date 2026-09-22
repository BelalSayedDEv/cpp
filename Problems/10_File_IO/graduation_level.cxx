#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;
const string filename ="client.txt";
const string delim ="#\\#";


void list() {
    cout << "\n==================================" << endl;
    cout << "         main menue screen        " << endl;
    cout << "==================================\n" << endl;
    cout << "[1] Show CLient list" << endl;
    cout << "[2] Add New Client" << endl;
    cout << "[3] Delete Client" << endl;
    cout << "[4] Update Client INFO" << endl;
    cout << "[5] Find CLient" << endl;
    cout << "[6] Exit" << endl;
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
    cout << "enter Account_number : " ;
    getline(cin >> ws,user.accountnumber);
    cout << "enter pincode : " ;
    getline(cin >> ws,user.pincode);
    cout << "enter name_user : " ;
    getline(cin >> ws,user.name);
    cout << "enter phone_user : " ;
    getline(cin >> ws,user.phone);
    cout << "enter balance_user : " ;
    cin >>user.balance;
    cin.ignore();
    return user;
}

string converttoline(stuser user,string delim) {
    string line="";
    line+=user.accountnumber+delim;
    line+=user.pincode+delim;
    line+=user.name+delim;
    line+=user.phone+delim;
    line+= to_string(user.balance);
    return line;
}

void pushlinetofile(string line,string filename) {

    fstream file;
    file.open(filename,ios::out | ios::app);
    if(file.is_open()) {
        file <<line<<endl;
        file.close();
        cout << "clients is add successfully" << endl;
    } else {

        cout << "program is not responding ,error(404)" << endl;
    }
}
vector<string> split(string line,string delim) {

    vector<string> vusers;
    short pos=0;
    string word="";
    pos = line.find(delim);
    while(pos != string::npos ) {
        word = line.substr(0,pos);
        if(!word.empty())
        {
            vusers.push_back(word);
        }
        line.erase(0,pos+delim.length());
        pos = line.find(delim);
    }
    if(!line.empty()) {
        vusers.push_back(line);
    }
    return vusers;
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

vector<stuser> readdatafromfile(vector<stuser>vuser,string filename) {
    fstream file;
    stuser user;
    string line;
    file.open(filename,ios::in);
    if(file.is_open()) {
        while(getline(file,line)) {
            user = convertlinetostruct(line,"#\\#");
            vuser.push_back(user);
        }
        file.close();
    }
    return vuser;
}

void printusers(stuser user) {
    cout << "-----------------------------------" << endl;
    cout << "Account_number : " << user.accountnumber<<endl;
    cout << "pincode : "  <<user.pincode<<endl;
    cout << "name_user : "<<user.name<<endl;
    cout << "phone_user : " << user.phone<<endl;
    cout << "balance_user : "<< user.balance<<endl;
    cout << "-----------------------------------\n\n" << endl;
}
void showallusers(vector<stuser> &vuser,string filename) {

    vuser = readdatafromfile(vuser,filename);
    cout << "------ count of  client (" << vuser.size() <<")-------\n" << endl;
    for(stuser &user : vuser) {
        printusers(user);
    }
}

bool markeasdeleted(vector<stuser> &vuser,string accountnumber) {


    for (stuser &user : vuser)
    {
        if(user.accountnumber == accountnumber)
        {
            user.markeasdeleted = true;
            return true;
        }
    }
    return false;
}

bool finduser(vector<stuser>&vuser,string accountnumber,stuser &user) {
    for (stuser &c : vuser)
    {
        if(c.accountnumber == accountnumber)
        {   user = c;
            return true;
        }
    }
    return false;
}

void savevectortofile(string filename,vector<stuser>&vuser) {
    fstream file;
    stuser user;
    string line;
    file.open(filename,ios::out);
    if(file.is_open()) {
        for(stuser &use : vuser) {
            if(use.markeasdeleted==false) {
                line = converttoline(use,delim);
                file<<line<<endl;
            }
        }
        file.close();
    }
}




void deleteuser(vector<stuser>&vuser,string accountnumber,string filename) {

    cout << "Enter an Account Number : " ;
    cin >> accountnumber;
    cin.ignore();
    stuser user ;
    char delet='n';
    if(finduser(vuser,accountnumber,user)) {

        printusers(user);

        cout << "do you want to print this user ? y/n" << endl;
        cin >> delet;
        if(tolower(delet)=='y')
        {
            markeasdeleted(vuser,accountnumber);
            savevectortofile(filename,vuser);
            cout << "the user deleted successfully " << endl;
        }
    }
}

stuser readupateddata( string accountnumber) {
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
    string accountnumber;
    cout << "Enter an Account Number : ";
    cin >> accountnumber;
    cin.ignore();
    bool found = false;
    stuser user;
    for (stuser& use : vuser) {

        if (use.accountnumber == accountnumber) {
            use = readupateddata(accountnumber);
            cout << "the user deleted successfully " << endl;
            found = true;
        }
    }
    if (!found) {
        cout << " this user is not found try again onther id" << endl;
    }
    savevectortofile(filename, vuser);
}

void program() {

    vector<stuser> vuser;
    stuser user;
    string line = "";
    list();
    int choise = readnumber("please enter what you want (1 to 6)");


    while(choise != 6) {
        if(choise == 1) {
            showallusers(vuser,filename);
        } else if (choise == 2) {
            user = readuser();
            line =converttoline(user,delim);
            pushlinetofile(line,filename);
        }else if (choise == 3) {
            string accountnumber;
            deleteuser(vuser,accountnumber,filename);
        }
        else if (choise == 4) {
            string accountnumber;
            upadteuser(vuser, filename);
        }
        list();
        choise = readnumber("please enter what you want (1 to 6)");
    }
}


int main()
{

    program();
    return 0;
}