#pragma once

#include <ostream>
#include <istream>

struct Date
{
    int Year;
    int Month;
    int Day;

    Date& operator=(const Date&);

    int ToInt() const;

    bool operator<(const Date& rhs);
    bool operator>(const Date& rhs);

    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
};
