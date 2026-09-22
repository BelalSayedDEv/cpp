#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

struct stuser {

    string acoountnumber;
    string pincode;
    string name;
    string phone;
    double balance;

};

stuser readuser() {

    stuser user;
    cout << "Enter your Account number" << endl;
    getline( cin,user.acoountnumber);
    cout << "Enter your pincode number" << endl;
    getline( cin,user.pincode);
    cout << "Enter your name " << endl;
    getline( cin,user.name);
    cout << "Enter your phone number" << endl;
    getline( cin,user.phone);
    cout << "Enter your balance" << endl;
    cin >> user.balance;
    return user;

}

string convertstructtooneline(stuser user,string delim) {

    string line ="";
    line += user.acoountnumber + delim;
    line += user.pincode + delim;
    line += user.name + delim;
    line += user.phone + delim;
    line += to_string(user.balance);
    return line;

}

void pushclintintofile(string namefile,string delim) {
    bool addmore = true;
    fstream file;
    
    while (addmore) {
        stuser user = readuser();
        string  line = convertstructtooneline(user,delim);
        
        
        file.open(namefile, ios::out | ios::app);
        
        if(file.is_open()) {
        
            file <<line<<endl;
            cout << "Clinet add successfully" << endl;
            file.close();

        } else {
        
            cout << "thier are something wronge " << endl;
            
        }
        cout << "Do you want add more clinet yes(1) or no(0)" << endl;
        cin >> addmore;
        cin.ignore();
    }
}

vector<string> split(string s, string delim) {

    vector<string> vstring;
    string word = "";
    size_t pos = s.find(delim);

    while (pos != string::npos) {
        word = s.substr(0, pos);
        if (word != "") {
            vstring.push_back(word);
        }
        s.erase(0, pos + delim.length());
        pos = s.find(delim);
    }

    if (s != "")
        vstring.push_back(s);

    return vstring;

}


int main() {

    pushclintintofile("client.txt","#\\#");

}