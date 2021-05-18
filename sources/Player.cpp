
#include "Player.hpp"
#include <string>

using namespace std;
using namespace pandemic;
const int CARDS_TO_THROW = 5;

Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}

Player &Player::throw_card(City c)
{
    cards.erase(c);
    return *this;
}

void Player::remove_cards()
{
    cards.clear();
}

std::string Player::role() const { return this->player_role; }

Player &Player::drive(City c)
{
    if (current_city == c)
    {
        throw std::invalid_argument{"You can't drive to this city"};
    }
    if (connected_cities.at(c).count(current_city) == 0 /*&& connected_cities.at(current_cityity).count(c) == 0*/)
    {
        throw std::invalid_argument{"The cities arn't connected"};
    }
    current_city = c;
    return *this;
}

Player &Player::fly_direct(City c)
{
    if (current_city == c)
    {
        throw std::invalid_argument{"You can't fly to this city"};
    }
    if (cards.count(c) == 0)
    {
        throw std::invalid_argument{"Youre missimg the card: "};
    }
    throw_card(c);
    current_city = c;

    return *this;
}

Player &Player::fly_charter(City c)
{
    if (current_city == c)
    {
        throw std::invalid_argument{"You can't fly to this city"};
    }
    if (cards.count(current_city) == 0)
    {
        throw std::invalid_argument{"Youre missimg the card: "};
    }
    throw_card(current_city);
    current_city = c;

    return *this;
}

Player &Player::fly_shuttle(City c)
{
    if (current_city == c)
    {
        throw std::invalid_argument{"You can't fly to this city"};
    }
    if (board.get_stations().count(c) == 0)
    {
        throw std::invalid_argument{"both cities must have research station."};
    }
    if (board.get_stations().count(current_city) == 0)
    {
        throw std::invalid_argument{"both cities must have research station."};
    }
    current_city = c;
    return *this;
}

Player &Player::build()
{
    if (cards.count(current_city) == 0)
    {
        throw std::invalid_argument{"The city is already have a research station , you must have the card of this city"};
    }
    throw_card(current_city);
    board.add_research_stations(current_city);

    return *this;
}

Player &Player::discover_cure(Color c)
{
    if (board.get_stations().count(current_city) == 0)
    {
        throw std::invalid_argument{"The city has no research station!"};
    }
    int counter = 0;
    for (const auto &t : cards)
    {
        if (colors_of_cities.at(t) == c)
        {
            counter++;
        }
    }
    if (counter < CARDS_TO_THROW)
    {
        throw std::invalid_argument{"You dont have enough cards"};
    }
    int i = 1;
    auto it_start = cards.begin();
    auto it_end = cards.end();
    while (it_start != it_end)
    {
        i++;
        if (i == CARDS_TO_THROW)
        {
            break;
        }
        if (colors_of_cities.at(*it_start) == c)
        {
            it_start = cards.erase(it_start); //picking the first color we find and then throwing cards from the same color
        }
        else
        {
            it_start++;
        }
    }
    board.add_discovered_cure(c);
    return *this;
}

Player &Player::treat(City c)
{
    if (current_city != c)
    {
        throw std::invalid_argument{"you are not in the city!"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"no cubes in the city!!"};
    }
    if (board.get_discoverd_cures().count(colors_of_cities.at(c)) != 0)
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
        cout << board[c] << endl;
    }
    return *this;
};
