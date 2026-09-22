#include<iostream>
#include<cmath>
using namespace std;

float readnumber(){
    float number;
    cout << "please enter your number" << endl;
    cin >> number ;
    return number;
}
float getfractionpart(float number){
    return number - (int)number;
}

int myround(float number){
int intpart = (int)number;
    
    if(abs(getfractionpart(number)) >= 0.5)
    {
    if(number >0){
        return ++intpart;
    }  else{
        return --intpart;
    }  
    }
    else if( abs(getfractionpart(number)) <  0.5 )
    {
    if(number>0){
        return intpart;
    }else{
        return intpart;
    }
    }
                
}

int main()
{
    float number = readnumber();
    cout << "my round is : "<< myround(number)<<endl;
    return 0;
}