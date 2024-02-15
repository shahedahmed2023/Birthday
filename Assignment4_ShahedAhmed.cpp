/*Lecture 14: Friend Functions
Code taken from: "Problem-Solving with C++", by W. Savitch
Instructor: Sareh Taebi, PhD
Date: 03/023/2023
*/

//Edit by  Shahed Ahmed
//Date: 3/29/2023
//Assignment 4


#include <iostream>

using namespace std;

//Purpose of this class: store a date (whether it's a birthday or an event)
class DayOfYear
{
    public:
        DayOfYear();    //initializes day and month to 01/01
        DayOfYear(int the_month, int the_day);
        void input( );
        void output( );
        void set_date(int new_month, int new_day);  //setter function or mutator function
        //Precondition: new_month and new_day form a possible date.
        //Postcondition: The date is reset according to the arguments.
        int get_month( );   //getter function or accessor function
        //Returns the month, 1 for January, 2 for February, etc.
        int get_day( );
        //Returns the day of the month.
        friend bool equal(DayOfYear date1,DayOfYear date2);
        //checks for equality of two dates
        friend bool after(DayOfYear date1, DayOfYear date2);
    private:
        void check_date( );
        int month;
        int day;
};
//Derived class
class DateYear : public DayOfYear
{
public:
DateYear(); //initializes day and month to 01/01 and year to current year
DateYear(int the_month, int the_day, int the_year); // constructor
void input( ); // input function
void set_year(int new_year); //setter function or mutator
int get_year(); // getter function
void output(ostream& out); // output function
friend bool DateCompare(DateYear date1,DateYear date2); //checks for equality of two dates
int BDCountdown (int bd_month,int bd_day); // Birthday countdown function
private:
// check function
void check_date( );
// variable
int year;
};
//testing out classes
int main()
{

DayOfYear today, bach_birthday(3,21);
//today.check_date();
cout << "Enter today's date.\n";
today.input( );
cout << "Today's date is ";
today.output( );
cout << "J. S. Bach's birthday is ";
bach_birthday.output( );
if (equal(today,bach_birthday) )
 cout << "Happy Birthday Johann Sebastian!\n";
else
cout << "Happy Unbirthday Johann Sebastian!\n";


today = bach_birthday;           //assignment operator would set values of bach_birthday to today's values
cout << "\nNow again! I have set today's date to that of Bach's birthday\n";
if (equal(today,bach_birthday) )
 cout << "Happy Birthday Johann Sebastian!\n";
else
cout << "Happy Unbirthday Johann Sebastian!\n";

// generating test case for after
DayOfYear date1 (02,07), date2(03,23);
cout <<"Prints true if date1 is after date2: "<<after(date1,date2) <<endl;


// My test
//default constructor
DateYear Current, birthday;
// Constructor ins value
Current = DateYear (4,1,2023);
cout << "Enter Birth Date \n";
birthday.input();
// compare
cout << "Prints true if current year and birthday year is same: " <<DateCompare(Current,birthday) <<endl;
// calculate how dayss left until birthday
int dayleft = Current.BDCountdown(birthday.get_month(),birthday.get_day());
// show how many left until birthday
cout << dayleft <<" days left until your birthday" <<endl;



return 0;
}
// define default DayOfYear constractor
DayOfYear::DayOfYear()
{
    month = 1;
    day = 1;
}
// define DayOfYear constractor
DayOfYear::DayOfYear(int the_month, int the_day)
{
    month = the_month;
    day = the_day;
}
// define DayOfYear input
void DayOfYear::input( )
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date( );
}

// define DayOfYear output
void DayOfYear::output( )
{
    cout << "month = " << month << ", day = " << day << endl;
}

 // define DayOfYear set function
void DayOfYear::set_date(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
    check_date();
}
 // define DayOfYear check function
void DayOfYear::check_date( )
{
if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
{   //input();
cout << "Illegal date. Aborting program.\n";
exit(1);

}
}
// Define get month function
int DayOfYear::get_month( )
{
    return month;
}
// Define get day function
int DayOfYear::get_day( )
{
    return day;
}
// define DayOfYear equal freinds function Compare date
bool equal(DayOfYear date1,DayOfYear date2)
{
    return (date1.day == date2.day && date1.month == date2.month);
}
// define DayOfYear after friends function Compare date
 bool after(DayOfYear date1, DayOfYear date2)
{
    return (date1.month > date2.month) || (date1.month == date2.month && date1.day > date2.day);

}
//invokes the default Dayofyear constructor
// define default DateYear constructor
DateYear :: DateYear() : DayOfYear()
{
    year = 2023;
}
//invokes the Dayofyear constructor
// define DateYear constructor
DateYear:: DateYear(int the_month, int the_day, int the_year):
DayOfYear( the_month, the_day)
{
    year = the_year;
}
// DateYear Define input function member
void DateYear :: input()
{
    int _day;
    int _month;
    cout << "Enter day of the month: ";
    cin >> _day;
    cout <<"Enter month as a number: ";
    cin >> _month;
    cout <<"Enter correct year: ";
    cin >> year ;
    set_date(_month, _day);
    check_date( );

}
// Define DateYear set function for year
void DateYear :: set_year(int new_year)
{
    year = new_year;
}
// Define DateYear get Function for year
int DateYear :: get_year()
{
    return year;
}
// define DateYear output function
void DateYear :: output(ostream& out)
{
   out << get_month() <<"/"<<get_day()<<"/"<<year <<endl;
}
// Define DateYear compare friends DateCompare function
bool DateCompare(DateYear date1,DateYear date2)
{
    return (date1.year == date2.year);
}
// Define Check year function
void DateYear :: check_date( )
{
    // checking correct days for leap year and common year
    if ( year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (!(year % 400 == 0))
            {
                if ((get_month() == 2) && (get_day() > 28))
                {
                     cout << "Illegal date. Aborting program.\n";
                        exit(1);
                }
            }

        }
        if ( year % 400 == 0 ||  year % 4 == 0 )
        {
            if ((get_month() == 2) && (get_day() > 29))
                {
                     cout << "Illegal date. Aborting program.\n";
                        exit(1);
                }


        }
    }

// Checking year for 4 digits
if  (year < 999 || year > 10000)
    {   //input();
    cout << "Illegal date. Aborting program.\n";
    exit(1);

    }

}
// Define DateYear Birthday countdown function
int DateYear :: BDCountdown (int bd_month,int bd_day)
{
    // set how many days in month
    int month_array [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int t = bd_month;
    int total = 0;

    // set February Correct day
    if (year % 4 == 0)
    {
         month_array[2] = 29;
        if ( year % 100 == 0)
         month_array[2] = 28;
        if (year % 400 == 0)
        month_array[2] = 29;

    }

        // calculate how many day left
        // if your birthday did not pass yet
        if ( get_month() < bd_month)
        {

            // set birthday month to day
        month_array[bd_month] = bd_day;
            // set current month to how many days left
        month_array[get_month()] = month_array[get_month()] - get_day();
        // adding how days left + add after ... + birthday day
        for(int i = get_month(); i <= t; i++)
        {
            total += month_array [i];
        }
            return total;
        }
          // calculate how many day left
        // if your birthday pass
        // count backward
        // and subtract total days leap or common year
        else if ( get_month() > bd_month)
        {      // birthday day subtract total day from birthday month
                month_array[bd_month] = month_array[bd_month] - bd_day;
                // set current money day to days
                month_array[get_month()] = get_day();
                // count backward
                for(int i = get_month(); i >= t; i--)
                {
                    total += month_array [i];
                }
                    //check if next year is leap year
                    // if leap year current day add birthday day then subtract
                    // that from 366 if leap year or 365 if common year
                    year++;
                    if (year % 4 == 0)
                    {
                        return 366 -total;
                        if ( year % 100 == 0)
                         return 365 -total;
                        if (year % 400 == 0)
                        return 366 -total;

                    }

        }

        // calculate how many day left
        // if your birthday same month or pass but in same month
        else if ( get_month()== bd_month)
        {
           // current date subtract by birthday date
            if (get_day() < bd_day)
                return  bd_day - get_day();
            // increase year
            else
                    year++;
                    //check if next year is leap year
                    // if leap year current day add birthday day then subtract
                    // that from 366 if leap year or 365 if common year
                    if (year % 4 == 0)
                    {
                        return 366 - (get_day() - bd_day);
                        if ( year % 100 == 0)
                         return 365 - (get_day() - bd_day);
                        if (year % 400 == 0)
                       return 366 - (get_day() - bd_day);

                    }


        }
}
















