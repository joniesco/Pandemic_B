#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::drive(City c)
{
    Player::drive(c);
    if (board.get_discoverd_cures().count(colors_of_cities.at(current_city)) > 0)
    {
        board[current_city] = 0;
    }
    return *this;
}

Player &Medic::fly_direct(City c)
{
    Player::fly_direct(c);
    if (board.get_discoverd_cures().count(colors_of_cities.at(current_city)) > 0)
    {
        board[current_city] = 0;
    }
    return *this;
}

Player &Medic::fly_charter(City c)
{
    Player::fly_charter(c);
    if (board.get_discoverd_cures().count(colors_of_cities.at(current_city)) > 0)
    {
        board[current_city] = 0;
    }
    return *this;
}

Player &Medic::fly_shuttle(City c)
{
    Player::fly_shuttle(c);
    if (board.get_discoverd_cures().count(colors_of_cities.at(current_city)) > 0)
    {
        board[current_city] = 0;
    }
    return *this;
}
Player &Medic::treat(City c)
{
    if (current_city != c)
    {
        throw std::invalid_argument{"you are not in the city!"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"no cubes in the city!!"};
    }
    if (board.get_discoverd_cures().count(colors_of_cities.at(c)) > 0)
    {
        board[c] = 0;
    }
    board[c] = 0;
    return *this;
};