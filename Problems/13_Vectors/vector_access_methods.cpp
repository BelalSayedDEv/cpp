#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> num= {1,2,3,4,5};
    cout << "Vector Elements Using [] : " ;
    cout << num[0]<< " " ;
    cout << num[1]<< " " ;
    cout << num[2]<< " " ;
    cout << num[3]<< " " ;
    cout << num[4]<< " " <<endl;
    cout << "-------------------------" << endl;


    cout << "Vector Elements Using.at(): " ;
    cout <<num.at(0) << " " ;
    cout <<num.at(1) << " " ;
    cout <<num.at(2) << " " ;
    cout <<num.at(3) << " " ;
    cout <<num.at(4) << " " <<endl;
    cout << "-------------------------" << endl;

    cout << "First Element: " << num.front()<< endl;
    cout << "last Element: " << num.back()<< endl;
    cout << "-------------------------" << endl;

    num.at(1)=30;
    num.at(2)= 40;
    cout << "Vector Elements : " ;

    for(const int &n : num) {
        cout << n << " " ;

    }
    cout << endl;
    cout << "-------------------------" << endl;
    
    vector<int>::iterator itr;
    cout << "Vector Elements using iterator : " ;
    for(itr = num.begin();itr!=num.end();itr++){
    
    cout<< *itr << " " ;
    }
    cout <<  endl;
    
    
    return 0;
}