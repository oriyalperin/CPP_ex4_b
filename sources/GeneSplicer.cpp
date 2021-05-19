
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;



Player& GeneSplicer::discover_cure(Color color)
{
        if(!(research_station(curr_city)))
        {
            throw invalid_argument("There is no research station in "+board.get_city_name(curr_city));
        }
        
        if(!cure_for_disease(color))
        {   
            unordered_set<City>::iterator it = cards.begin();
            int count=0;
            const int cards_to_throw=5;
            if(cards.size()>=cards_to_throw)
            {
                while(it!=cards.end() && count<cards_to_throw)
                {
                        City city=*it;
                        it++;
                        throw_card(city);
                        count++;
                }
                cure_for_disease(color)=true;
            }
            else
            {
                throw invalid_argument("There are only " +to_string(cards.size()) +
                ", you need " + to_string(cards_to_throw-cards.size()) + " more");
            }
        }
    return *this;
}

string GeneSplicer::role()
{
    return "GeneSplicer";
}
