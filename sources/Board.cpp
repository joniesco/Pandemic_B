#include "Board.hpp"
#include "Medic.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

int Board::operator[](City c) const
{
    return mapOfDiseases.at(c);
}

int& Board::operator[](City c)
{
    return mapOfDiseases[c];
}

bool Board::is_clean() const
{
    for (const auto &it : mapOfDiseases)
    {
        if (it.second > 0) {
            return false;
        }
    }
    return true;
}

ostream& pandemic::operator<<(ostream& out, Board& b)
{
    if (b.is_clean())
    {
        out << "There are no diseases!! " << endl;
    }
    else
    {
        for (const auto &it : b.get_board())
        {
            out << "[" << Cities.at(it.first) << ", " << it.second << "]" << endl;
        }
        cout << "\nDiscovered cures for: " << endl;
        for (Color c: b.discoverd_cures)
        {
            out << colors.at(c) << endl;
        }
        for (const auto &station : b.get_stations())
        {
            out << "\nThere are reaserch station in : " << Cities.at(station)   << endl;
        }
    }
    return out;
}
void Board::remove_cures() { discoverd_cures.clear(); }
void Board::remove_stations() { research_stations.clear(); };


// int main(){
// Board board;
//     board[City::MexicoCity] = 4;      
// 	board[City::MexicoCity] = 1;      
// 	board[City::London] = 2;   
// 	board[City::Madrid] = 0;
// 	board[City::BuenosAires] = 1;
//     board[City::HongKong] = 2;
//     cout << board<< endl;
//     board[City::HongKong] = 0;
//     cout << board<< endl;
//     board.add_discovered_cure(Black);
//         board.add_discovered_cure(Black);
//         board.add_discovered_cure(Red);

//         cout << board<< endl;
//         board.add_research_stations(Madrid);
//         board.add_research_stations(Madrid);
//         board.add_research_stations(SanFrancisco);



//                 cout << board<< endl;
//                 board.remove_cures();
//                 board.remove_stations();
//                                 cout << board<< endl;






//     return 0;
// }

