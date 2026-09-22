

#include <iostream>
using namespace std;



int readnumber() {

    int limit_num;
    cout << "please enter the max number" << endl;
    cin >> limit_num;
    return limit_num;

}


void printyusingfor(int limit) {


    cout << "This Using For Loop" << endl;

    for (int i = 1; i <= limit; i++)
    {
        cout << i << endl;
    }
}

void printnumbersusingwhile(int limit) {
    int i = 0;
    cout << "This Using while Loop" << endl;
    while ( i < limit) {
        i++;
        cout << i << endl;

    }
}

void printnumbersusingdowhile(int limit) {
    int i = 0;
    cout << "This Using do while Loop" << endl;
    do
    {
        i++;
        cout << i << endl;
    } while (i < limit);
}

void printnumbersusingforinvers(int limit) {
    
    cout << "This Using For Loop for inverse" << endl;

        for (int i = limit; i <= limit; i--)
        {
            if (i > 0) {
                cout << i << endl;
            }
        }
  
}
void printnumberssusingwhileinvers(int limit) {
    int counter = limit + 1;
    cout << "This Using while Loop for inverse" << endl;
    
    while (counter  > 1) {
        counter --;
        cout << counter << endl;
    }
}

void printnumbersusingdowhileinvers(int limit) {
    int counter = limit + 1;
    cout << "This Using For Loop for inverse" << endl;
    do {
        counter--;
        cout << counter;
    } while (counter > 1);
}



int main()
{
    
    printyusingfor(readnumber());

    printnumbersusingwhile(readnumber());
   
    printnumbersusingdowhile(readnumber());

    printnumbersusingforinvers(readnumber());

    printnumberssusingwhileinvers(readnumber());

    printnumbersusingdowhileinvers(readnumber());



}


