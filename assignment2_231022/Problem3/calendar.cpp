/* P3:
 * File: calendar.cpp
 * ------------------
 * This file implements the p1calendar.h interface
 */

#include <string>
#include <iostream>
//#include "CSC3002OJActive/assignment2/lib.h" // for OJ test
//#include "CSC3002OJActive/assignment2/calendar.h" // for OJ test
//#include "lib.h" // For local test
//#include "calendar.h" // For local test
using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
   return JANUARY;
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month)
{
   // TODO
   switch (month)
    {
      case JANUARY: return "JANUARY";
      case FEBRUARY: return "FEBRUARY";
      case MARCH: return "MARCH";
      case APRIL: return "APRIL";
      case MAY: return "MAY";
      case JUNE: return "JUNE";
      case JULY: return "JULY";
      case AUGUST: return "AUGUST";
      case SEPTEMBER: return "SEPTEMBER";
      case OCTOBER: return "OCTOBER";
      case NOVEMBER: return "NOVEMBER";
      case DECEMBER: return "DECEMBER";
      default: return "???";
    }
   return NULL;
}

Month operator++(Month &month, int)
{
   // TODO
   Month oldMonth = month;
   month = static_cast<Month>((month + 1) % (DECEMBER + 1));
   return oldMonth;
}


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * 
 */

int Date::getDay()
{
   // TODO
   return this->day;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth()
{
   // TODO
   return this->month;
}

int Date::getYear()
{
   // TODO
   return this->year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   // TODO
   string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
   string dayString = (this->day < 10) ? to_string(this->day) : to_string(this->day);
   string monthString = months[this->month - 1];
   string yearString = to_string(this->year);
   return dayString + "-" + monthString + "-" + yearString;
}

void Date::initDate(int day, Month month, int yyyy)
{
   // TODO
   this->day = day;
   this->month = month;
   this->year = yyyy;

}

Date operator+(Date date, int delta)
{
   // TODO
   int day = date.getDay() + delta;
   Month month = date.getMonth();
   int year = date.getYear();
 
   while (day > daysInMonth(month, year))
   {
      day -= daysInMonth(month, year);
      if (month == DECEMBER)
      {
         month = JANUARY;
         year++;
      }
      else{month = Month(month + 1);}
   }
   return Date(day, month, year);
}

Date operator-(Date date, int delta)
{
   // TODO
   int day = date.getDay() - delta;
   Month month = date.getMonth();
   int year = date.getYear();

   while (day <= 0) {
      if (month == JANUARY) 
      {
         month = DECEMBER;
         year--;
      } 
      else 
      {
         month = Month(month - 1);
      }
      day += daysInMonth(month, year);
   }
   return Date(day, month, year);
}

int operator-(Date d1, Date d2)
{
   // TODO
   Date startDate = (d1 < d2) ? d1 : d2;
   Date endDate = (d1 < d2) ? d2 : d1;
   
   int days = 0;
   int startDay = startDate.getDay();
   int endDay = endDate.getDay();
   int startMonth = startDate.getMonth();
   int endMonth = endDate.getMonth();
   int startYear = startDate.getYear();
   int endYear = endDate.getYear();

   if (startYear == endYear) {
      if (startMonth == endMonth) {
            days = endDay - startDay;
      } else {
            for (int i = startMonth; i < endMonth; i++) {
               days += daysInMonth(Month(i), startYear);
            }
            days += endDay - startDay;
      }
   } else {
      for (int i = startYear + 1; i < endYear; i++) {
            if (isLeapYear(i)) {
               days += 366;
            } else {
               days += 365;
            }
      }

      for (int i = startMonth + 1; i <= 12; i++) {
            days += daysInMonth(Month(i), startYear);
      }
      days += daysInMonth(Month(startMonth), startYear) - startDay;

      for (int i = 1; i < endMonth; i++) {
            days += daysInMonth(Month(i), endYear);
      }
      days += endDay;
   }

   return days;
}

Date &operator+=(Date &date, int delta)
{
   // TODO
   date = date + delta;
   return date;
}

Date &operator-=(Date &date, int delta)
{
   // TODO
   date = date - delta;
   return date;
}

Date operator++(Date &date)
{
   // TODO
   date = date + 1; // Increment the date by one day
   return date;
}

Date operator++(Date &date, int)
{
   // TODO
   Date temp = date;
   date = date + 1; // Increment the date by one day
   return temp;
   
}

Date operator--(Date &date)
{
   // TODO
   date = date - 1; // Decrement the date by one day
   return date;
}

Date operator--(Date &date, int)
{
   // TODO
   Date temp = date;
   date = date - 1; // Decrement the date by one day
   return temp;
}

bool operator==(Date d1, Date d2)
{
   // TODO
   return (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() &&
         d1.getYear() == d2.getYear());

}

bool operator!=(Date d1, Date d2)
{
   // TODO
   return !(d1 == d2);

}

bool operator<(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() < d2.getYear()) return true;
   if (d1.getYear() > d2.getYear()) return false;
   if (d1.getMonth() < d2.getMonth()) return true;
   if (d1.getMonth() > d2.getMonth()) return false;
   return d1.getDay() < d2.getDay();

}

bool operator<=(Date d1, Date d2)
{
   // TODO
   return d1 < d2 || d1 == d2;
}

bool operator>(Date d1, Date d2)
{
   // TODO
   return !(d1 <= d2);
}

bool operator>=(Date d1, Date d2)
{
   // TODO
   return !(d1 < d2);
}

std::ostream &operator<<(std::ostream &os, Date date){
   // TODO
   os << date.toString();
   return os;
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   // TODO
   switch (month)
    {
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            if (isLeapYear(year))
            {
                return 29; // Leap year, February has 29 days
            }
            else
            {
                return 28; // Non-leap year, February has 28 days
            }
        default:
            return 31;
   return 0;}
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   // TODO
   return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/* DO NOT modify this main() part */
int main()
{
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
}