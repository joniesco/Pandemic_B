#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    if (current_city != c && connected_cities.at(current_city).count(c) == 0)
    {
        throw invalid_argument("you are not in the city or in a connected city");
    }

    if (board[c] == 0)
    {
        throw std::invalid_argument{"no cubes in the city!!"};
    }
    if (board.get_discoverd_cures().count(colors_of_cities.at(c)) > 0)
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }
    return *this;
};
