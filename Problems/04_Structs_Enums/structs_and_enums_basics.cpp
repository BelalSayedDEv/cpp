
#include <iostream>
#include <cmath>

using namespace std;


struct owner {

    string name, adress;
    int phone;
    string email;

};
struct Producer
{
    string name;
    int whole_number;

};
    struct Car
    {
        
        string brand;
        int model;
        string speed;
        owner main_owner;
        Producer name;

    };


    enum Player { messi, ronaldo, salah, emam };
    enum gender
    {
        male =100,
        female =50
    };
    enum statues
    {
        single =50,
        married = 100
    };
   

    int main()
    {
        //std::cout << "math function!\n";
        //cout << sqrt(64) << endl; // >>> 8*8 = 64    ----------------------SQRT------------------
        //cout << round(2.5) << endl; // >>>> 3
        //cout << round(3.2) << endl;
        //cout << round(2.20) << endl; //       -----------------------round---------------------
        //cout << round(sqrt(50)) << endl;    
        //cout << pow(2, 4);//    2^4 = 16 -----------------------pow--------------------------------

        //cout << floor(2.5) << endl;  // >> 2.5 >> 2     -------------- floor --------------------

        //cout << ceil(2.5) << endl;  // >> 2.5 >> 3 ----------------- ceil ------------------------

        //cout << abs(-10) << endl;  //    >>> 10  >>>>>>>> abslut function >>>>>>>>>>>>>>
        //cout << abs(10) << endl;  // >>> 10      >>>>>>>>> abslut funtion >>>>>>>>>

        //int a, d , c;
        //cout << "please enter your a " << endl;
        //cin >> a;
        //cout << "please enter your d " << endl;
        //cin >> d;
        //cout << "please enter your c " << endl;
        //cin >> c;


        ///*cout << "the area is " << a * sqrt(pow(d, 2) - pow(a, 2)) << endl;*/
      /*  cout << "the area is : " << 3.14 * pow(a, 2) << endl;
        cout << "the area is : " << 3.14 * 0.25 * pow(a, 2) << endl;
        cout << "the area is : " << pow(a, 2) / (4 * 3.14) << endl;*/
        /* cout << "the area is : " << ((pow(d, 2) * 3.14 * 0.25)) * ((2 * a - d) / (2 * a + d)) << endl;*/
         /*float p = (a + d + c) / 2;
         float area = 3.14 * pow((a * d * c) / (4 * sqrt(p * (p - a) * (p - d) * (p - c))), 2) ;

         cout << "the area is :" << area << endl;*/
         /*  cout << "the number ^2 is :" << round( pow(a, 2) ) << endl;
           cout << "the number ^3 is :" <<  round (pow(a, 3) ) << endl;
           cout << "the number ^4 is :" <<  round (pow(a, 4)) << endl;*/



        Car car_1, car_2;
        /* car_1.brand = "miitsubashi";
         car_1.model = 512;
         car_1.speed = 450;
         car_1.main_owner.name = "mohamed abu-hadhoud";
         car_2.main_owner.name = "belal sayed isa tamame.";
         car_2.brand = "nissan";
         car_2.speed = 350;*/



         /* cout << "please enter the next information  your name " << endl;
          cin >> car_1.main_owner.name;
          cout << "please enter the next information  your phone " << endl;
          cin >> car_1.main_owner.phone;
          cout << "please enter the next information  your adress " << endl;
          cin >> car_1.main_owner.adress;
          cout << "please enter the next information  car\'s brand " << endl;
          cin >> car_1.brand;
          cout << "please enter the next information  car\'s model " << endl;
          cin >> car_1.model;
          cout << "hello thank you for your registration your information is : " << endl << car_1.main_owner.name << endl << car_1.main_owner.phone << endl << car_1.main_owner.adress << endl << car_1.brand << endl << car_1.model << endl;
      */


      /*  cout << "please enter the producer of your car" << endl;
        cin >> car_1.name.name;*/


       /* Player main_player;
        main_player = Player::emam;
        cout << "my player who i suggest it for you is : " << main_player << endl;

        gender mygender;
        statues mystatues;
        mygender = gender::male;
        mystatues = statues::married;
        cout << "my gender is : " << mygender << endl;
        cout << "my statues is : " << mystatues << endl;*/

    };
 