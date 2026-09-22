
#include <iostream>
using namespace std;
#include <string>
#include <cmath>

int main()
{
    int num1 = 15 ;
    double num2 =16.5;
    num2 = num1;
   // num1 = (int)num2;
    num2 = double(num1);
    cout << num2 << endl;

    string str = "1415.1415";
    int num_int = stoi(str);
    cout << num_int << endl;
    double num_double = stod(str);
    cout << num_double << endl;
    float num_float = stof(str);
    cout << num_float << endl;
    

    string num_string = to_string(num2);
    cout << num_string << endl;



    string st1 = "43.22";
    double double_num = stod(st1);
    float float_num = stof(st1);
    int int_num = stoi(st1);
    cout << double_num << endl;
    cout << float_num << endl;
    cout << int_num << endl;


    int n1 = 20;
    string sring_n1 = to_string(n1);
    double n2 = 33.5;
    string string_n2 = to_string(n2);
    float n3 = 55.23;
    string string_n3 = to_string(n3);
    int int_n3 = stoi(string_n3);


    cout << sring_n1 << endl;
    cout << string_n2 << endl;
    cout << string_n3 << endl;
    cout << int_n3 << endl;


    // string function is agroup of charachters such array  
    // example               
    string myname = "belalsayedisatamame";
    cout << myname.length() << endl;
    cout << myname[7] << endl;
    string s1 = "16" , s2= "14";

    string s3 = s1 + s2;
    cout << s3 << endl;
    int sum = stoi(s1) + stoi(s2);
    cout << sum  << endl;
    cout << stoi(s3) << endl;

    //other example
    
    string string1 , string2, string3;
    cout << "please enter your string1 " << endl;
    getline(cin, string1);
    cout << "please enter your string2 " << endl;
    cin >> string2;
    cout << "please enter your string3 " << endl;
    cin >> string3;
    cout << "the length of string1 is :" << string1.length() << endl;
    cout << "characters at 0,2,4,7 are :" << string1[0] << " " << string1[2] << " " << string1[4] << " " << string1[7] << endl;
    cout << "the concatinating string2 and string3 =" << string2 + string3 << endl;
    cout << " 5 * 10 = " << stoi(string2) * stoi(string3) << endl;

    
}