#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (current_city!=c && cards.count(c) == 0)
    {
        throw std::invalid_argument{"You dont have the city card"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"no cubes in the city!!"};
    }
    if (board.get_discoverd_cures().count(colors_of_cities.at(c)) > 0)
    {
        board[c] = 0;
        throw_card(c);
    }
    else
    {
        board[c]--;
        throw_card(c);
    }

    return *this;
};