#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    if (board.get_stations().count(current_city) == 0)
    {
        throw std::invalid_argument{"No reasearch stations in this city"};
    }
    int count = 0;
    for (const auto &key : cards)
    {
        if (colors_of_cities.at(key) == c)
        {
            count++;
        }
    }
    if (count < n)
    {
        throw std::invalid_argument{"You dont have enough cards"};
    }
    int i = 1;
    auto it_start = cards.begin();
    auto it_end = cards.end();
    while (it_start != it_end)
    {
        i++;
        if (i == n)
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
};