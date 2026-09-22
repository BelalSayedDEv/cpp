#include<iostream>
using namespace std;
#include<cstdlib>

int RrandomNumber(int from,int to ){
  
   int random = rand() % (to - from + 1) + from ;
   return random ;
}

int main()
{
  srand((unsigned)time(NULL));
    
    cout << RrandomNumber(20, 50) <<endl;
    cout << RrandomNumber(20, 50) <<endl;
    cout << RrandomNumber(20, 50) <<endl;
    
    return 0;
}