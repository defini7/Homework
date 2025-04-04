#pragma once

#include <ostream>
#include <istream>

class Date
{
public:
    Date(int day = 0, int month = 0, int year = 0);

    Date& operator=(const Date&);

    int ToInt() const;

    bool operator<(const Date&);
    bool operator>(const Date&);

    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);

public:
    int Day;
    int Month;
    int Year;

};
