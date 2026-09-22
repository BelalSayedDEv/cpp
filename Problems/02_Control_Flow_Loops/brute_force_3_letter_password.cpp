#include <iostream>
using namespace std;
#include <string>

string readpin(string message)
{
    string pin;
    cout << message << endl;
    cin >> pin;
    return pin;
}

void makepattern(string oraginpin)
{
    string word = " ";
    int times = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                times++;
                word =  word + char(i) ;
                word =  word + char(j)  ;
                word =  word +  char(k) ;

                cout << "Taria. "
                     << "[" << times << "]  : " << word << endl;

                if (word == oraginpin)
                {
                    cout << "password is : " << oraginpin << endl;
                    cout << "that's found after " << times << "Time(s)" << endl;
                }
                word = " ";
            }
        }
    }
}

int main()
{
    makepattern(readpin("please enter pin number "));

    return 0;
}