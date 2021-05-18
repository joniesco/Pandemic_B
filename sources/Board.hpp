#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>


namespace pandemic
{

    class Board
    {
    private:
        std::map<City, int> mapOfDiseases;//represnt the board of the game 
        set<City> research_stations; // marking all the cities that have research_stations
        set<Color> discoverd_cures;  //marking all the cures which were discoverd

    public:
        int operator[](City c) const; //get
        int &operator[](City c);      //set
        bool is_clean() const;
        friend ostream &operator<<(std::ostream &out, Board &b);
        void remove_cures();
        void remove_stations();
        std::map<City, int> get_board() const { return mapOfDiseases; }
        set<City> get_stations() const { return research_stations; }
        set<Color> get_discoverd_cures() const { return discoverd_cures; }
        void add_discovered_cure(Color c)
        {
            discoverd_cures.insert(c);
        }
        void add_research_stations(City c)
        {
            research_stations.insert(c);
        }
    };
}