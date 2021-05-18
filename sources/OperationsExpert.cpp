#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
    board.add_research_stations(current_city);

    return *this;
};