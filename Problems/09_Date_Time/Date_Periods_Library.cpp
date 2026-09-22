#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;



int readnumber(string message) {
    int number;
    cout << message << endl;
    cin >> number;
    return number;

}

bool checkisleapyear(int year) {

    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}
int countdayinmonth(int month, int year) {

    if (month > 12 || month < 1) {
        return 0;
    }
    if (month == 2) {

        return (checkisleapyear(year) ? 29 : 28);
    }

    int month31arr[] = { 1,3,5,7,8,10,12 };
    for (int i = 0; i < 7; i++) {
        if (month31arr[i] == month) {
            return 31;
        }
    }

    return 30;
}

int getorderofday(int day, int month, int year) {

    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}
string dayshortname(int dayshortname) {

    string arr[7] = { "sun","mon","tue","wed","Thu", "Fri","sat" };
    return arr[dayshortname];
}

string monthshortname(int monthshortname) {

    string months[12] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };
    return months[monthshortname];
}

void makecalender(int month, int year)
{
    int current = getorderofday(1, month, year);
    int daysinmonth = countdayinmonth(month, year);

    cout << "\n-----------------------------\n";
    cout << "        " << monthshortname(month - 1) << " " << year << endl;
    cout << "-----------------------------\n";
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";

    int i = 0;

    for (i = 0; i < current; i++)
        cout << "    ";


    for (int day = 1; day <= daysinmonth; day++)
    {
        cout << setw(4) << day;

        if (++i == 7)
        {
            cout << endl;
            i = 0;
        }
    }

    cout << endl;
    cout << "\n-----------------------------\n";
}
void makeyearcalender(int year) {

    for (int i = 1; i <= 12; i++)
    {

        makecalender(i, year);

    }
}

int countdayindate(int day, int month, int year) {

    int counterdays = day;

    for (int i = month - 1; i >= 1; i--) {

        counterdays += countdayinmonth(i, year);
    }
    return counterdays;
}
struct stdate {
    int day;
    int month;
    int year;
};

stdate getorderofdate(int orderday, int year) {

    int dayofmonth = 0;
    stdate date;
    for (int i = 1; i <= 12; i++) {
        dayofmonth = countdayinmonth(i, year);
        if (dayofmonth < orderday) {
            orderday = orderday - dayofmonth;
        }
        else {
            date.month = i;
            date.day = orderday;
            return date;
        }
    }
}

stdate addmoredaytodate(int moredays, int totalofbegganing, int year) {

    int totalofalldays = moredays + totalofbegganing;
    stdate date;
    date.month = 1;
    date.year = year;

    while (true) {
        int getorderofday;
        getorderofday = countdayinmonth(date.month, date.year);
        if (getorderofday < totalofalldays)
        {
            totalofalldays -= getorderofday;
            date.month++;
            if (date.month > 12)
            {
                date.month = 1;
                date.year++;
            }
        }
        else {
            date.day = totalofalldays;
            break;
        }
    }
    return date;

}
stdate readfulldate() {

    stdate date;
    date.day = readnumber("please enter the day");
    date.month = readnumber("please enter the month");
    date.year = readnumber("please enter the year");
    return date;

}

bool checkdate1lessdate2(stdate date1, stdate date2) {

    if (date1.year < date2.year)
        return true;
    else if (date1.year == date2.year)
    {
        if (date1.month < date2.month)
            return true;
        else if (date1.month == date2.month) {
            if (date1.day < date2.day)
                return true;
            else
                return false;
        }
    }
    else {
        return false;
    }
}
bool checkdate1equaldate2(stdate date1, stdate date2) {

    return((date1.day == date2.day) ? ((date1.month == date2.month) ? (date1.year == date2.year) : false) : false);
}



bool islastdayinmonth(stdate date) {

    return (date.day == countdayinmonth(date.month, date.year) ? true : false);
}


bool islastmonthintheyear(stdate date) {

    return (date.month == 12 ? true : false);

}

stdate increasingbyoneday(stdate date) {

    if (islastdayinmonth(date))
    {
        if (islastmonthintheyear(date)) {

            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else
    {
        date.day += 1;
    }
    return date;
}

int clcdiffbetweentwodate(stdate date1, stdate date2) {

    int totalday1 = countdayindate(date1.day, date1.month, date1.year);
    int totalday2 = countdayindate(date2.day, date2.month, date2.year);
    int diff = 0;
    diff = totalday2 - totalday1;
    return diff;

}

int clcdiffbetweentwodateopatinadding(stdate date1, stdate date2, bool options = false) {

    int days = 0;
    while (checkdate1lessdate2(date1, date2)) {

        days++;
        date1 = increasingbyoneday(date1);
    }
    return(options) ? ++days : days;
}

stdate getnowdate(stdate date) {

    time_t t = time(nullptr);

    tm now{};
    localtime_s(&now, &t);   // safe in MSVC

    date.year = now.tm_year + 1900;
    date.month = now.tm_mon + 1;
    date.day = now.tm_mday;

    return date;
}

stdate increasedatebyxdays(int x, stdate date) {
    int remainingday = 1;
    while (remainingday <= x)
    {
        date = increasingbyoneday(date);
        remainingday++;
    }
    return date;
}

stdate increasedatebyoneweek(stdate date) {

    int remainingday = 1;
    while (remainingday <= 7)
    {
        date = increasingbyoneday(date);
        remainingday++;
    }
    return date;
}
stdate increasedatebyxweek(int x, stdate date) {
    x = x * 7;
    int remainingday = 1;
    while (remainingday <= x)
    {
        date = increasingbyoneday(date);
        remainingday++;
    }
    return date;
}
stdate increasedatebyonemonth(stdate date) {
    int reminnigmonth = 1;
    while (reminnigmonth <= 1) {
        if (islastmonthintheyear(date)) {
            date.month = 1;
            date.year++;
            reminnigmonth++;
        }
        else {
            date.month++;
            reminnigmonth++;
        }
    }
    return date;
}
stdate increasedatebyxmonth(int x, stdate date) {
    int reminnigmonth = 1;
    while (reminnigmonth <= x) {
        if (islastmonthintheyear(date)) {
            date.month = 1;
            date.year++;
            reminnigmonth++;
        }
        else {
            date.month++;
            reminnigmonth++;
        }
    }
    return date;
}
stdate increasedatebyoneyear(stdate date) {

    date.year = date.year + 1;
    return date;
}
stdate increasedatebyxyears(int x, stdate date) {
    date.year = date.year + x;
    return date;
}


stdate decreasedatebyoneday(stdate date) {

    if (date.day == 1) {
        if (date.month == 1) {
            date.year--;
            date.month = 12;
            date.day = countdayinmonth(date.month, date.year);
        }
        else {
            date.month--;
            date.day = countdayinmonth(date.month, date.year);
        }

    }
    else {
        date.day--;
    }
    return date;
}
stdate decreasedatebyxdays(int days, stdate date) {
    for (int i = 1; i <= days; i++) {
        date = decreasedatebyoneday(date);
    }
    return date;
}
stdate decreasedatebyoneweek(stdate date) {
    for (int i = 1; i <= 7; i++) {
        date = decreasedatebyoneday(date);
    }
    return date;
}
stdate decreasedatebyxweeks(int weeks, stdate date) {
    for (int i = 1; i <= weeks * 7; i++) {
        date = decreasedatebyoneday(date);
    }
    return date;
}
stdate decreasedatebyonemonth(stdate date) {

    if (date.month == 1) {
        date.month = 12;
        date.year--;
    }
    else {
        date.month--;
    }
    if (date.day > countdayinmonth(date.month, date.year)) {

        date.day = countdayinmonth(date.month, date.year);

    }
    return date;
}
stdate decreasedatebyxmonth(int months, stdate date) {

    for (int i = 1; i <= months; i++) {

        date = decreasedatebyonemonth(date);

    }
    return date;
}

stdate decreasedatebyoneyear(stdate date) {

    date.year--;
    return date;
}

stdate decreasedatebyxyear(int years, stdate date) {

    date.year -= years;
    return date;
}


bool isendofweek(stdate date) {
    
    if (getorderofday(date.day, date.month, date.year) == 6 ) {

        return true;

    }
        return false;
}

bool isweekend(stdate date) {

    if (getorderofday(date.day, date.month, date.year) == 5 || getorderofday(date.day, date.month, date.year) == 6) {

        return true;

    }
    return false;
}
bool isbusinessday(stdate date) {

    if (getorderofday(date.day, date.month, date.year) == 5 || getorderofday(date.day, date.month, date.year) == 6) {

        return false;

    }
    return true;
}

int dayuntiltheendofweek(stdate date) {

    int counter = 0;
    while (!isendofweek(date))
    {
        counter++;
        date = increasingbyoneday(date);
    }

    return counter;
}

int dayuntiltheendofmonth(stdate date) {

    int counter = 0;

    while (!islastdayinmonth(date))
    {
        counter++;
        date = increasingbyoneday(date);
    }
    return counter + 1;
}

int dayuntiltheendofyear(stdate date) {

    int counter = 0; 
    
    while(!islastmonthintheyear(date)){

        counter++;
        date = increasingbyoneday(date);
        
    }
    while (!islastdayinmonth(date))
    {
        counter++;
        date = increasingbyoneday(date);

    }
    return counter;
}



int clcvactiondaysver1(stdate date1, stdate date2) {

    int counterofvacation = 0;

    while (checkdate1lessdate2(date1,date2)) {
        if (isbusinessday(date1)) {
            counterofvacation++;
           
        }
        
        date1 = increasingbyoneday(date1);
    }
    return counterofvacation;
}


stdate clcvacationsreturndate(stdate date,int vactiondays) {
   
    while(vactiondays != 0) {

        if (isbusinessday(date)) {
            vactiondays--;
        }
        date = increasingbyoneday(date);
    }
    return date;
}


int clcvactiondays(stdate date1, stdate date2) {

    int remainingday = 1;
    int vacationcounter = 0;
    while (remainingday <= clcdiffbetweentwodateopatinadding(date1, date2, true)) {

        if (getorderofday(date1.day, date1.month, date1.year) != 5 && getorderofday(date1.day, date1.month, date1.year) != 6)
            vacationcounter++;
        if (islastdayinmonth(date1)) {
            date1.day = 1;
            if (islastmonthintheyear(date1)) {
                date1.month = 1;
            }
            else {
                date1.month++;
            }
        }
        else {
            date1.day++;
        }

    }
    return vacationcounter;
}

bool isdate1equaltodate2(stdate date1, stdate date2) {


    return (date1.year == date2.year) ? (date1.month == date2.month) ? (date1.day == date2.day) : false :false; 

}


bool checkdate1afterdate2(stdate date1, stdate date2) {

    /*if (date1.year > date2.year) {
        return true;
    }
    else if (date1.year==date2.year)
    {
        if (date1.month > date2.month)
        {
            return true;
        }
        else if(date1.month == date2.month)
        {
            if (date1.day > date2.day)
            {
                return true;
            }
        }
    }
    return false;*/

    /*""""""""""""""""this is onther solution to get more productivty"""""""""""""""""" */

    return (!checkdate1lessdate2(date1, date2) && !isdate1equaltodate2(date1, date2));
}
enum encompare { before = -1 ,equal = 0 , after = 1};

encompare comparedatesinenum(stdate date1, stdate date2) {

    if (checkdate1lessdate2(date1, date2)) {
        return encompare::before;
    }
    if (isdate1equaltodate2(date1, date2))
    {
        return  encompare::equal;
    }

    return encompare::after;
}

int comparedatesinint(stdate date1, stdate date2) {

    if (checkdate1lessdate2(date1, date2)) {
        return -1;
    }
    if (isdate1equaltodate2(date1, date2))
    {
        return 0;
    }
   
        return 1;
}
struct stperiod
{
    stdate startperiod;
    stdate endperiod;

};


bool overlapperiodgoodedition(stperiod firstperiod, stperiod secondperiod) {
    
    /* this is solution for this problem more efficiancy and productiveity */

    if (comparedatesinenum(firstperiod.endperiod, secondperiod.startperiod) == encompare::before || comparedatesinenum(secondperiod.startperiod, firstperiod.endperiod) == encompare::after)
        return false;
    else
        return true;
}


bool overlapperiod(stperiod firstperiod, stperiod secondperiod ) {
    
    while (!isdate1equaltodate2(firstperiod.startperiod, secondperiod.startperiod))
    {
        if (!isdate1equaltodate2(firstperiod.startperiod, firstperiod.endperiod))
        {
            firstperiod.startperiod = increasingbyoneday(firstperiod.startperiod);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int clcdaystoenddate(stperiod period,bool option = false) {

  return  clcdiffbetweentwodateopatinadding(period.startperiod, period.endperiod, option);
    
}

bool isdatewithinperiod(stperiod period, stdate date) {

    return comparedatesinenum(period.startperiod, date) == encompare::before && comparedatesinenum(period.endperiod,date) == encompare::after;
}

stperiod readfullperiod() {
    stperiod firstperiod;
    cout << "Enter period 1 :" << endl;
    cout << "Enter Start Date :\n" << endl;
    firstperiod.startperiod = readfulldate();
    cout << "\nEnter End Date :" << endl;
    firstperiod.endperiod = readfulldate();
    return firstperiod;
}

int clcoverlapeddays(stperiod firstperiod, stperiod secondperiod) {

    int counter = 0;
    while (!isdate1equaltodate2(firstperiod.startperiod, secondperiod.startperiod)) {
        firstperiod.startperiod = increasingbyoneday(firstperiod.startperiod);
    }
    while (isdate1equaltodate2(firstperiod.startperiod, secondperiod.startperiod)) {

        if (isdate1equaltodate2(firstperiod.startperiod, firstperiod.endperiod) || isdate1equaltodate2(secondperiod.startperiod, secondperiod.endperiod) )
        {
            return ++counter;
        }
        counter++;
        firstperiod.startperiod = increasingbyoneday(firstperiod.startperiod);
        secondperiod.endperiod = increasingbyoneday(secondperiod.endperiod);
    }
    return counter;
    }



int main()
{
   /* stdate date1;
    stdate date2;
    cout << "Enter Date1 : " << endl;
    date1 = readfulldate();
    cout << endl;
    cout << "Enter Date2 : " << endl;
    date2 = readfulldate();*/

    stperiod firstperiod;
    stperiod secondperiod;
   
    firstperiod = readfullperiod();
    secondperiod = readfullperiod();
 

 

    cout << "\n\noverlap days is : " << clcoverlapeddays(firstperiod, secondperiod) << endl;


  




    /*int vacationsdays = readnumber("please enter vacation day ? ");*/
    /*date1 = clcvacationsreturndate(date1, vacationsdays);*/

   /* if (checkdate1afterdate2(date1,date2))
    {
        cout << "\nYes, Date1 is After Date2." << endl;
    }
    else
    {
        cout << "\nNo, Date1 is Not After Date2." << endl;
    }*/

    
    /*if (comparedatesinenum(date1, date2) == encompare::before)
    {
        cout << "compare result is : -1" << endl;
    }
    else if (comparedatesinenum(date1, date2) == encompare::equal)
    {
        cout << "compare result is : 0" << endl;
    }
    else
    {
        cout << "compare result is : 1" << endl;
    }*/

    /*cout << "vacation from :" << dayshortname(getorderofday(date1.day, date1.month, date1.year)) << " . " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    cout << "vacation from :" << dayshortname(getorderofday(date2.day, date2.month, date2.year)) << " . " << date2.day << "/" << date2.month << "/" << date2.year << endl;
    cout << "Actual Vacation days is : " << clcvactiondaysver1(date1, date2) << endl;*/

    /*cout << "\n\nToday is " << dayshortname(getorderofday(date.day, date.month, date.year)) << " , ";
    cout << date.day << "/" << date.month << "/" << date.year << endl;

    cout << "Is it End of week ? " << endl;
    if (isendofweek(date))
    {
        cout << "yes it is a weel end" << endl;
    }
    else
    {
        cout << "no it is a weel end" << endl;

    }

    cout << endl;

    cout << "Is it weekend ? " << endl;
    if (isweekend(date))
    {
        cout << "yes it is weekend" << endl;
    }
    else
    {
        cout << "no  it is not  weekend" << endl;

    }

    cout << endl;

    cout << "Is it business day ? " << endl;
    if (isbusinessday(date))
    {
        cout << "yes it is business" << endl;
    }
    else
    {
        cout << "no  it is not business" << endl;

    }
    cout << "\nDay untill end of week : " << dayuntiltheendofweek(date) << endl;
    cout << "Day untill end of month : " << dayuntiltheendofmonth(date) << endl;
    cout << "Day untill end of year : " << dayuntiltheendofyear(date) << endl;*/






    /*date=increasingbyoneday(date);
    cout << "date after increasing one day is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyxdays(10,date);
    cout << "date after increasing 10 days is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyoneweek(date);
    cout << "date after increasing one week is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyxweek(10,date);
    cout << "date after increasing 10 weeks is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyonemonth(date);
    cout << "date after increasing one month is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyxmonth(5,date);
    cout << "date after increasing 5 month is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyoneyear(date);
    cout << "date after increasing one year is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date = increasedatebyxyears(10,date);
    cout << "date after increasing 10 years is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;*/
    /*date=decreasedatebyoneday(date);
    cout << "date after decreasing one day is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyxdays(10,date);
    cout << "date after decreasing 10 day is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyoneweek(date);
    cout << "date after decreasing week  is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyxweeks(10,date);
    cout << "date after decreasing 10 weeks is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyonemonth(date);
    cout << "date after decreasing one month is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyxmonth(5,date);
    cout << "date after decreasing 5 months is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyoneyear(date);
    cout << "date after decreasing one year is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;
    date=decreasedatebyxyear(10,date);
    cout << "date after decreasing 10 year is : "<<date.day<<"/"<<date.month<<"/"<<date.year<< endl;*/
    return 0;
}