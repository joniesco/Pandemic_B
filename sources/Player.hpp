#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic
{

    class Player
    {
    protected:
        Board &board;
        std::set<City> cards;
        City current_city;
        std::string player_role;

    public:
        Player(Board &b, City c, std::string r) : board(b), current_city(c), player_role(r) {}

        virtual Player &take_card(City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        std::string role() const;
        void remove_cards();
        Player &throw_card(City c);
    };

}