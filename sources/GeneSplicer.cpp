#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int CARDS_TO_THROW = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    if (board.get_stations().count(current_city) == 0)
    {
        throw std::invalid_argument{"The city has no research station!"};
    }
    // int i = 1;
    if (cards.size() < CARDS_TO_THROW)
    {
        throw std::invalid_argument{"not enough cards"};
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
        it_start = cards.erase(it_start);
    }

    board.add_discovered_cure(c);
    return *this;
};