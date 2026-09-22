#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

int randomnumber(int from,int to ) {
    int number = rand()%(to-from+1)+from;
    return number;
}

enum enchoice {
    stone=1, paper=2, scissor=3
};

int readusernumber() {
    int number;
    do {
        cout << "please choose stone[1], paper[2], scissors[3] :" << endl;
        cin >> number;
    } while(number < 1 || number > 3);
    return number;
}

int readmanyround() {
    int number;
    do {
        cout << "how many rounds do you want to play (1 to 10): " << endl;
        cin >> number;
    } while(number < 1 || number > 10);
    return number;
}

enchoice castingnumber(int number) {
    return (enchoice)number;
}

string choice(enchoice c){
    switch(c)
    {
    case enchoice::paper:
        return "paper";
    case enchoice::stone:
        return "stone";
    case enchoice::scissor:
        return "scissor";
    }
    return "";
}

string battel(enchoice person,enchoice computer,int &countperson,int &countcomputer ,int &countdraws) {

    if(person==enchoice::stone && computer==enchoice::paper) {
        countcomputer++;
        return "computer";
    } else if (person==enchoice::paper && computer==enchoice::stone) {
        countperson++;
        return "person1";
    } else if (person==enchoice::scissor && computer==enchoice::stone) {
        countcomputer++;
        return "computer";
    } else if (person==enchoice::stone && computer==enchoice::scissor) {
        countperson++;
        return "person1";
    } else if (person==enchoice::paper && computer==enchoice::scissor) {
        countcomputer++;
        return "computer";
    } else if (person==enchoice::scissor && computer==enchoice::paper) {
        countperson++;
        return "person1";
    } else if (person==computer){
        countdraws++;
        return "[no winner]";
    }
    return "";
}


void rounds(int roundsCount,int &countperson,int &countcomputer, int &countdraws) {
    for(int i =0;i<roundsCount;i++){
        cout << "\n\n-----------" << endl;
        cout << "Round [" << i+1 << "] begins: " << endl;
        cout << "-----------" << endl;

        int userchoice = readusernumber();
        enchoice person = castingnumber(userchoice);
        enchoice computer = castingnumber(randomnumber(1,3));

        cout << "Player1 choice : " << choice(person) << endl;
        cout << "Computer choice: " << choice(computer) << endl;

        cout << "Round winner   : " 
             << battel(person,computer,countperson,countcomputer,countdraws) 
             << endl;
    }
}

void gameoverhadder(){
    cout << "-------------------------" << endl;
    cout << "    *** Game Over *** " << endl;
    cout << "-------------------------" << endl;
    cout << "---------------"  ;
    cout << " [Game Result] " ;
    cout << "---------------"  << endl;
}

void gameover(int round,int countperson,int countcomputer, int countdraws){
    
   gameoverhadder();
   cout << "Game rounds   : " <<round<< endl;
   cout << "person1 wins  : " <<countperson<< endl;
   cout << "computer wins : " <<countcomputer<< endl;
   cout << "Draw times    : " <<countdraws<< endl;
   string winner;
   if(countperson>countcomputer){
       winner = "person1";
   }else if(countperson<countcomputer){
       winner = "computer";
   }else {
       winner = "[no winner]";
   }
   cout << "final winner   : " <<winner<<endl;
}

void startgame(){
    srand((unsigned)time(NULL));
    int personwins=0, computerwins=0, drawtimes=0;
    bool playmore = true;
    do{
    int round = readmanyround();
    rounds(round,personwins,computerwins,drawtimes);
    gameover(round,personwins, computerwins, drawtimes);
    cout << "\n\ndo you play again yes[1],no[0] ?" << endl;
    cin >> playmore;
        } while (playmore);
    }
    
int main()
{
    startgame();
    return 0;
}