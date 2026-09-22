#include<iostream>
#include<vector>
using namespace std;


struct stemployee {
    string firstname;
    string lastname;
    float salary;
};


int main()
{
    vector <stemployee> vemployee;
    
    stemployee tempemployee;
    tempemployee.firstname="Belal";
    tempemployee.lastname="Sayed";
    tempemployee.salary =5000;
    vemployee.push_back(tempemployee);
    
    tempemployee.firstname ="mustafa";
    tempemployee.lastname ="tharwat";
    tempemployee.salary =7000;
    vemployee.push_back(tempemployee);
    
    
    tempemployee.firstname ="ahmed";
    tempemployee.lastname ="gamal";
    tempemployee.salary = 6000;
    vemployee.push_back(tempemployee);
    
    cout <<"\nvector structure elemnts :\n";
    
    for (stemployee &employee : vemployee)
    {
    
    cout << employee.firstname<< endl;
    cout << employee.lastname<< endl;
    cout << employee.salary<< endl;
    cout << "\n" << endl;
    }
    
    
    return 0;
}