#include<iostream>

#include<vector>
using namespace std;

void readelemnts(vector <int> &vNumbers ){
   
    int number;
    bool addmore = 1;
    do{
    cout << "please enter a number" << endl;
    cin >> number;
    vNumbers.push_back(number);
    cout << "to add more number 1(yes),0(no) " << endl;
    cin >> addmore;
    }while(addmore);

}

void printnumbers(vector<int> &vNumbers,float &avarege){
cout << "Vector Numbers : ";
int sum = 0;
int counter = 0;
for(int number : vNumbers){
sum = sum + number;
counter++;
cout << number << " " ;
}
cout << endl;
avarege = (float)sum / counter;
cout << "the avarege : " << avarege << endl;

}

int main()
{
    vector <int>Belal;
    float avarege=0;
    readelemnts(Belal);
    printnumbers(Belal, avarege);
    return 0;
}