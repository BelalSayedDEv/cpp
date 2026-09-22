#include<iostream>
using namespace std;

int main()
{
    /*  int a,*p;

      a = 10;
      p = &a;
      cout << "-------------------" << endl;
      cout << "value of a :  "<< a << endl;
      cout << "-------------------" << endl;
      cout << "adress of a : " << &a<< endl;
      cout << "-------------------" << endl;
      cout << "adress of pointer p : "<< p << endl;
      cout << "-------------------" << endl;
      cout << "value of pointer p : " << *p << endl;
      cout << "-------------------" << endl;

      *p = 20;

      cout << "the value of *p : " <<*p<< endl;
      cout << "-------------------" << endl;
      cout << "the value of a after Dereferencing and change value : " <<  a <<endl;
      cout << "-------------------" << endl;
      p = nullptr;

      if(p!= nullptr) {

          cout << "the pointer has already adress" << endl;
          cout << "-------------------" << endl;
      } else {
          cout << "the pointer is null " << endl;
          cout << "-------------------" << endl;
      }

      p = &a ;
      if(p != nullptr) {

          cout << "the pointer has already adress" << endl;
          cout << "-------------------" << endl;
      } else {
          cout << "the pointer is null " << endl;
          cout << "-------------------" << endl;
      }*/

    int arr[5]= {1,2,3,4,5};
    int * ptr ;
    ptr = arr;

    for(int i =0; i<5; i++) {

        cout <<"elemnt " <<i<<" : "<< *(ptr +i) << endl;

    }

    cout << "--------------------------------" << endl;
    cout << "       exercise one complete     " << endl;
    cout << "--------------------------------" << endl;

    for(int i =0; i<5; i++) {

        cout <<"elemnt " <<i<<" : "<< *(ptr +i)+10 << endl;

    }

    cout << "--------------------------------" << endl;
    cout << "       exercise two complete    " << endl;
    cout << "--------------------------------" << endl;
    int sum = 0;
    for (int i = 0; i <5; i++) {

        cout <<"elemnt " <<i<<" : "<< *(ptr +i)<< endl;
        sum = sum+ *(ptr + i);
    }
    cout << "sum of all elemnts : "<< sum << endl;
    cout << "--------------------------------" << endl;
    cout << "      exercise three complete   " << endl;
    cout << "--------------------------------" << endl;

}