#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

string readstring() {
    string s;
    cout << "enter your string" << endl;
    getline(cin,s);
    return s;
}

vector<string> split(vector<string> vstring,string s,string delim)
{
    short pos=0;
    string sword;
    while((pos =s.find(delim)) != std::string::npos)
    {
        sword = s.substr(0,pos);
        if(sword!=" ")
        {
            vstring.push_back(sword);
        }
        
        s.erase(0, pos + delim.length());
    }
    if(s!=" ") {
        vstring.push_back(s);
    }
    return vstring;
}
string joinstring(vector<string> vstring,string delim){
    string word;
    for(string &s : vstring){
    word += s;
    word.append(delim);
    }
    return word.substr(0,word.length()-delim.length());
}

int main()
{
    vector <string> vstring;
    string s = readstring();
    string word;
    vstring =split(vstring,s," ");
    for(string &s : vstring){
      cout << s << endl;
    }
    
   word = joinstring(vstring,readstring());
    cout << word << endl;
    return 0;
}