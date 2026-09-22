#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#pragma warning(disable : 4996)

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

    int a = ((14 - month) / 14);
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
            if (date1.day > date2.day)
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

    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
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

    for (int i = 1; i <= months;i++) {

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

int main()
{
    stdate date;
    date =  getorderofdate(250, 2009);
    cout << date.day << endl;
        cout << date.month << endl;
        cout << date.year << endl;


    return 0;
}
