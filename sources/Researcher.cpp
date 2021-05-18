#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int CARDS_TO_THROW = 5;

Player &Researcher::discover_cure(Color c)
{
    int count = 0;
    for (const auto &key : cards)
    {
        if (colors_of_cities.at(key) == c)
        {
            count++;
        }
    }
    if (count < CARDS_TO_THROW)
    {
        throw std::invalid_argument{"Yoy dont have enough cards"};
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
    };
