#include "League.hpp"

int main()
{
    char c;

    do
    {
        League league;

        league.Create();
        league.QuickSort();

        std::cout << std::endl << league << std::endl;

        GetVar(c, "Would you like to start from the beginning? (y/n)",
               c != 'y' && c != 'n' && c != 'Y' && c != 'N', std::cin);
    }
    while (c == 'y' || c == 'Y');
}
