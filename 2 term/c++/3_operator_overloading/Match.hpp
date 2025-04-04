#pragma once

#include <iostream>
#include <string>

#include "Date.hpp"
#include "Utils.hpp"

struct Match
{
    std::string Teams[2];
    Date Date;

    Match& operator=(const Match&);

    friend std::ostream& operator<<(std::ostream&, const Match&);
    friend std::istream& operator>>(std::istream&, Match&);
};
