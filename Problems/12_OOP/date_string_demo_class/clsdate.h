
#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <iomanip>

using namespace std;

class clsDate
{

private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:


    enum enDay { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6 };

    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsstring::Splite(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year)
	{

		_Day = Day;
		_Month = Month;
		_Year = Year;

	}

	clsDate(short DateOrderInYear, short Year)	
	{
		
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;
	}

	void SetDay(short Day) {
		_Day = Day;
	}

	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetYear(short Year) {
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	string DateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	void Print()
	{
		cout << DateToString(* this) << endl;
	}

    static short DayOfWeekOrder(short Year, short Month, short Day)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;

        short d = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;

        return d;
    }


    short DayOfWeekOrder(clsDate Date)
    {
        short a = (14 - Date.Month) / 12;
        short y = Date.Year - a;
        short m = Date.Month + (12 * a) - 2;

        short d = ((Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;

        return d;
    }


   static string DayShortName(short DayOfWeekOrder)
    {

        string DaysInWeek[8] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return DaysInWeek[DayOfWeekOrder];
    }

   static string MonthShortName(short Month)
    {
        string Months[12] = { "Jan","Feb","Mar","Apr","May","June","Jul","Aug","Sep","Oct","Nov","Dec" };

        return Months[Month - 1];
    }

    short NumberOfDays(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }


    static bool IsLeapYear(short Year)
    {
        return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400) == 0);
    }

    bool IsLeapYear() {
        return IsLeapYear(_Year);
    }

    /*----------------------------------------------------------------------------------------------------*/

    static short NumberOfDaysInMonth(short Year, short Month)
    {
        if (Month < 1 && Month>12)
        {
            return 0;
        }

        short ArrOfMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (ArrOfMonths[Month - 1]));
    }

    short NumberOfDaysInMonth() {

        return NumberOfDaysInMonth(_Year, _Month);

    }

    /*----------------------------------------------------------------------------------------------------*/

    static	bool IsValidDate(clsDate Date)
    {

        if (Date.Day < 1 || Date.Day>31)
            return false;

        if (Date.Month < 1 || Date.Month>12)
            return false;

        if (Date.Month == 2)
        {
            if (IsLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;

        return true;

    }


    bool IsValidDate() {
        return IsValidDate(*this);
    }

    /*----------------------------------------------------------------------------------------------------*/

    int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? ++Days : Days;
    } 

    /*----------------------------------------------------------------------------------------------------*/

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
    }

    bool IsLastDayInMonth() {
        return IsLastDayInMonth(*this);
    }

    /*----------------------------------------------------------------------------------------------------*/

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear() {
        return IsLastMonthInYear(_Month);
    }

    /*----------------------------------------------------------------------------------------------------*/

    static bool IsLastDayInYear(clsDate Date)
    {
        return (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month));
    }

    bool IsLastDayInYear() {
        return IsLastDayInYear(*this);
    }

    /*----------------------------------------------------------------------------------------------------*/

   static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

   clsDate IncreaseDateByOneDay() {
       return  IncreaseDateByOneDay(*this);
   }

   /*----------------------------------------------------------------------------------------------------*/

    bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day:false)) : false);
    }

    bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
    }

    /*----------------------------------------------------------------------------------------------------*/

   static short NumberOfDaysFromTheBeginningOfTheYear(short Year, short Month, short Day)
    {
        short Counter = 0;
        for (int i = 1; i < Month; i++)
        {
            Counter += NumberOfDaysInMonth(Year, i);
        }
        Counter += Day;

        return Counter;
    }

   short NumberOfDaysFromTheBeginningOfTheYear() {

       return NumberOfDaysFromTheBeginningOfTheYear(_Year, _Month, _Day);
   }

    /*----------------------------------------------------------------------------------------------------*/

  static  clsDate DateAddDays(short DaysAdding, clsDate Date)
    {
        short RemainderDays = DaysAdding + NumberOfDaysFromTheBeginningOfTheYear(Date.Year, Date.Month, Date.Day);
        short MonthDays = 0;

        Date.Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
            if (RemainderDays > MonthDays)
            {
                RemainderDays -= MonthDays;
                Date.Month++;
                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                Date.Day = RemainderDays;
                break;
            }
        }
        return Date;
    }

  clsDate DateAddDays(short DaysAdding) {

      return DateAddDays( DaysAdding, *this);

  }

    /*----------------------------------------------------------------------------------------------------*/
   

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainderDays = DateOrderInYear;
        short MonthDays = 0;

        Date.Month = 1;
        Date.Year = Year;

        while (true)
        {
            MonthDays =NumberOfDaysInMonth(Year, Date.Month);
            if (RemainderDays > MonthDays)
            {
                RemainderDays -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainderDays;
                break;
            }
        }
        return Date;
    }

    clsDate GetDateFromDayOrderInYear(short DateOrderInYear) {
        
        return GetDateFromDayOrderInYear(DateOrderInYear, _Year);
    }

    /*----------------------------------------------------------------------------------------------------*/

    static clsDate GetSystemDate()
    {
        clsDate Date;
        time_t t = time(0);
        tm* now = localtime(&t);

        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;

        return Date;
    }

    /*----------------------------------------------------------------------------------------------------*/


    static void PrintMonthCalendar(short Year, short Month)
    {
        cout << "\n________________" << MonthShortName(Month) << "________________\n\n";

        for (short i = 0; i < 7; i++)
            cout << DayShortName(i) << "  ";

        cout << endl;

        int Current = DayOfWeekOrder(Year, Month, 1);
        int NumberDaysMonth = NumberOfDaysInMonth(Year, Month);

        for (int i = 1; i <= Current; i++)
            cout << setw(5) << "  ";

        for (int i = 1; i <= NumberDaysMonth; i++)
        {
            cout << setw(3) << i << "  ";

            if (++Current == 7)
            {
                cout << endl;
                Current = 0;
            }
        }

        cout << "\n___________________________________\n";
    }

    void PrintMonthCalendar() {

        return PrintMonthCalendar(_Year, _Month);
    }

    /*----------------------------------------------------------------------------------------------------*/

    static void PrintYearCalendar(short Year)
    {
        cout << "\n________________________________\n\n";
        cout << setw(20) << "Calendar - " << Year << "\n\n";
        cout << "\n________________________________\n\n";

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(Year, i);
            cout << endl;
        }
    }

    void PrintYearCalendar() {

        return PrintYearCalendar(_Year);

    }

    /*----------------------------------------------------------------------------------------------------*/

    int NumberOfHours(short Year)
    {
        return NumberOfDays(Year) * 24;
    }

    int NumberOfMinutes(short Year)
    {
        return NumberOfHours(Year) * 60;
    }

    int NumberOfSeconds(short Year)
    {
        return NumberOfMinutes(Year) * 60;
    }

    clsDate IncreaseDateByXDays(clsDate Date, int Adding)
    {
        for (int i = 1; i <= Adding; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }

        return Date;
    }

    clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }

        return Date;
    }

    clsDate IncreaseDateXWeek(clsDate Date, int Adding)
    {
        for (int i = 1; i <= Adding; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Year++;
            Date.Month = 1;
        }
        else
        {
            Date.Month++;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    clsDate IncreaseDateByXMonth(clsDate Date, int Adding)
    {
        for (int i = 1; i <= Adding; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }

        return Date;
    }

    clsDate IncreaseDateByOneYear(clsDate Date)
    {
        for (int i = 1; i <= 12; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }

        return Date;
    }

    clsDate IncreaseDateByOneYearFaster(clsDate Date)
    {
        Date.Year++;
        return Date;
    }

    clsDate IncreaseDateByXYear(clsDate Date, int Adding)
    {
        Date.Year += Adding;
        return Date;
    }

    clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        return IncreaseDateByXYear(Date, 10);
    }

    clsDate IncreaseDateByOneDecadeFaster(clsDate Date)
    {
        Date.Year += 10;
        return Date;
    }

    clsDate IncreaseDateByXDecadesFaster(clsDate Date, int Adding)
    {
        Date.Year += Adding * 10;
        return Date;
    }

    clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        Date.Year += 100;
        return Date;
    }

    clsDate IncreaseDateByOneMillenneum(clsDate Date)
    {
        Date.Year += 100;
        return Date;
    }

    clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Year--;
                Date.Month = 12;
                Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
            }
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }

    clsDate DecraseDateByXDays(clsDate Date, int Days)
    {
        for (int i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    clsDate DecraseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    clsDate DecreaseDateByXWeek(clsDate Date, int Decrase)
    {
        for (int i = 1; i <= Decrase; i++)
        {
            Date = DecraseDateByOneWeek(Date);
        }

        return Date;
    }

    clsDate DecraseDateByOneMonth(clsDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Month = 12;
        }
        else
        {
            Date.Month--;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    clsDate DecraseDateByXMonth(clsDate Date, int Month)
    {
        for (int i = 1; i <= Month; i++)
        {
            Date = DecraseDateByOneMonth(Date);
        }

        return Date;
    }

    clsDate DecraseDateByOneYear(clsDate Date)
    {
        Date.Year--;
        return Date;
    }

    clsDate DecraseDateByXYear(clsDate Date, int Years)
    {
        for (int i = 1; i <= Years; i++)
        {
            Date = DecraseDateByOneYear(Date);
        }

        return Date;
    }

    clsDate DecraseDateByXYearsFaster(clsDate Date, int Years)
    {
        Date.Year -= Years;
        return Date;
    }

    clsDate DecraseDateByOneDecade(clsDate Date)
    {
        for (int i = 1; i <= 10; i++)
        {
            Date = DecraseDateByOneYear(Date);
        }

        return Date;
    }

    clsDate DecraseDateByOneDecadeFaster(clsDate Date)
    {
        Date.Year -= 10;
        return Date;
    }

    clsDate DecraseDateByXDecade(clsDate Date, int Decades)
    {
        for (int i = 1; i <= Decades; i++)
        {
            Date = DecraseDateByOneDecade(Date);
        }

        return Date;
    }

    clsDate DecraseDateByXDecadeFaster(clsDate Date, int Decades)
    {
        Date.Year -= Decades * 10;
        return Date;
    }

    clsDate DecraseDateByOneCentury(clsDate Date)
    {
        Date.Year -= 100;
        return Date;
    }

    clsDate DecraseDateByOneMillenneum(clsDate Date)
    {
        Date.Year -= 1000;
        return Date;
    }

    void PrintDateText(clsDate Date)
    {
        cout << Date.Year << "/" << Date.Month << "/" << Date.Day << endl;
    }

    

    bool IsItEndOfTheWeek(enDay Day)
    {
        return Day == enDay::Thu;
    }

    bool IsItWeekEnd(enDay Day)
    {
        return (Day == enDay::Fri || Day == enDay::Sat);

    }

    bool IsItWeekEnd(clsDate Date)
    {
        //Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date);
        return  (DayIndex == 5 || DayIndex == 6);
    }

    bool IsItBusinessDay(enDay Day)
    {
        return (!IsItWeekEnd(Day));
    }

    bool IsItBusinessDay(clsDate Date)
    {
        return (IsItWeekEnd(Date));
    }

    short DaysUntilEndOfTheWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
    }

    short DaysUntilEndOfTheWeek(enDay Day)
    {
        short DaysCount = 0;

        while (Day != enDay::Fri)
        {
            Day = (enDay)((Day + 1) % 7);
            ++DaysCount;
        }
    }

    short DaysUntilEndOfTheMonth(clsDate Date)
    {
        short DaysOfThisMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
        return DaysOfThisMonth - Date.Day;
    }

    short DaysUntilEndOfTheYear(clsDate Date)
    {
        clsDate DateEndYear;
        DateEndYear.Day = 31;
        DateEndYear.Month = 12;
        DateEndYear.Year = Date.Year;

        return GetDiffrenceInDays(Date, DateEndYear, true);
    }

    short ActualVacationDays(clsDate DateStart, clsDate DateEnd)
    {
        short Actual = 0;

        while (IsDate1BeforeDate2(DateStart, DateEnd))
        {
            if (!IsItWeekEnd(DateStart))
            {
                Actual++;
            }

            DateStart = IncreaseDateByOneDay(DateStart);
        }
        return Actual;
    }

    clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;


        //in case the data  is weekend keep adding one day util you reach business day
        //we get rid of all weekends before the first business day
        while (IsItWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //here we increase the vacation dates to add all weekends to it.

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (IsItWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //in case the return date is week end keep adding one day util you reach business day
        while (IsItWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }

    enum eCompareDate { Before = -1, Equal = 0, After = 1 };

    eCompareDate CompareDate(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
        {
            return eCompareDate::Before;
        }
        if (IsDate1EqualDate2(Date1, Date2));
        {
            return eCompareDate::Equal;
        }
        return eCompareDate::After;
    }

    

   /* bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
    {
        if (
            CompareDate(Period2.DateEnd, Period1.DateStart) == eCompareDate::Before
            ||
            CompareDate(Period2.DateStart, Period1.DateEnd) == eCompareDate::After
            )
        {
            return false;
        }

        return true;
    }*/

   /* int PeriodLengthInDays(sPeriod Period, bool IncludeEndDate = false)
    {
        return GetDiffrenceInDays(Period.DateStart, Period.DateEnd, IncludeEndDate);
    }

    bool IsDateInPeriod(sPeriod Period, clsDate Date)
    {
        return  !(CompareDate(Date, Period.DateStart) == eCompareDate::Before
            ||
            CompareDate(Date, Period.DateEnd) == eCompareDate::After);
    }

    int CountOverlapDaysWithMyWay(sPeriod Period1, sPeriod Period2)
    {
        clsDate StartOverlap, EndOverlap;
        if (!IsOverlapPeriods(Period1, Period2)) return 0;

        StartOverlap = (CompareDate(Period1.DateStart, Period2.DateStart) == eCompareDate::After) ? Period1.DateStart : Period2.DateStart;
        EndOverlap = (CompareDate(Period1.DateEnd, Period2.DateEnd) == eCompareDate::Before) ? Period1.DateEnd : Period2.DateEnd;

        return GetDiffrenceInDays(StartOverlap, EndOverlap);
    }

    int CountOverlapDays(sPeriod Period1, sPeriod Period2)
    {
        if (!IsOverlapPeriods(Period1, Period2)) return 0;

        int Period1Length = PeriodLengthInDays(Period1);
        int Period2Length = PeriodLengthInDays(Period2);
        int OverLapDays = 0;

        if (Period1Length < Period2Length)
        {
            while (IsDate1BeforeDate2(Period1.DateStart, Period1.DateEnd))
            {
                if (IsDateInPeriod(Period2, Period1.DateStart))
                    OverLapDays++;

                Period1.DateStart = IncreaseDateByOneDay(Period1.DateStart);
            }
        }
        else
        {
            while (IsDate1BeforeDate2(Period2.DateStart, Period2.DateEnd))
            {
                if (IsDateInPeriod(Period1, Period2.DateStart))
                    OverLapDays++;

                Period2.DateStart = IncreaseDateByOneDay(Period2.DateStart);
            }
        }
        return OverLapDays;
    }*/

   

    clsDate StringToDate(string StringDate)
    {
        vector<string>vDate = clsstring::Splite(StringDate, "/");

        clsDate Date;
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);

        return Date;
    }


    string ReplaceWordInStringUsingBuiltInFunction(string S1, string WordToReplace, string ReplaceTo)
    {
        short pos = S1.find(WordToReplace);

        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, WordToReplace.length(), ReplaceTo);
            pos = S1.find(WordToReplace);
        }
        return S1;
    }

    string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date.Day));
        FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormat, "mm", to_string(Date.Month));
        FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormat, "yyyy", to_string(Date.Year));

        return FormattedDateString;
    }


	






	

};

