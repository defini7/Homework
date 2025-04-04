#include "Date.hpp"

#include <iomanip>

Date::Date(int day, int month, int year)
    : Day(day), Month(month), Year(year)
{

}

Date& Date::operator=(const Date& rhs)
{
    Year = rhs.Year;
    Month = rhs.Month;
    Day = rhs.Day;

    return *this;
}

int Date::ToInt() const
{
    return Year * 10000 + Month * 100 + Day;
}

bool Date::operator<(const Date& rhs)
{
    return ToInt() < rhs.ToInt();
}

bool Date::operator>(const Date& rhs)
{
    return ToInt() > rhs.ToInt();
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << std::setfill('0') <<
        std::setw(2) << date.Day << '.' <<
        std::setw(2) << date.Month << '.' <<
        std::setw(4) << date.Year;

    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    is >> date.Day >> date.Month >> date.Year;
    return is;
}
