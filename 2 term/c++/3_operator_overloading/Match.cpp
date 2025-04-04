#include "Match.hpp"

Match& Match::operator=(const Match& rhs)
{
    Teams[0] = rhs.Teams[0];
    Teams[1] = rhs.Teams[1];

    Date = rhs.Date;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Match& match)
{
    os << "Date = " << match.Date << std::endl;

    os << "Team 1 = " << match.Teams[0] << std::endl;
    os << "Team 2 = " << match.Teams[1];

    return os;
}

std::istream& operator>>(std::istream& is, Match& match)
{
    for (int j = 0; j < 2; j++)
        GetVar(match.Teams[j], "Enter team name", false, is);

    GetVar(match.Date.Year, "Enter a year", match.Date.Year <= 0, is);
    GetVar(match.Date.Month, "Enter a month", match.Date.Month <= 0 || match.Date.Month > 12, is);

    bool isLeap = IsLeapYear(match.Date.Year);

    GetVar(match.Date.Day, "Enter a day",
           match.Date.Day <= 0 ||
           match.Date.Day > 31 ||
           match.Date.Month == 2 && match.Date.Day > (isLeap ? 29 : 28), is);

    return is;
}
