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


string reversesrring(string s) {
    vector <string> vstring;
    string s2 = "";
    vstring = split(vstring,s," ");
    
    vector <string> ::iterator iter = vstring.end();
    
    while(iter != vstring.begin() )
    {
        --iter;
        s2 += *iter +" ";

    }
    s2 = s2.substr(0,s2.length()-1);
    
    return s2;
}

int main()
{
    string s = readstring();
     
   cout <<reversesrring(s)<< endl;
}