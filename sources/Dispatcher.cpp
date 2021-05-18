#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
        if (current_city == c)
        {
                throw invalid_argument("You are already in this city");
        }
        if (board.get_stations().count(current_city) > 0)
        {
                current_city = c;
                return *this;
        }
        return Player::fly_direct(c);
}

;