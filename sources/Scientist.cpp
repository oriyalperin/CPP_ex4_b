
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Scientist.hpp"
using namespace std;
using namespace pandemic;



Player& Scientist::discover_cure(Color color)
{
        if(!(research_station(curr_city)))
        {
            throw invalid_argument("There is no a research station in this city");
        }
        
        if(!cure_for_disease(color))
        {   
            unordered_set<City>::iterator it = cards.begin();
            int count=0;
            if(Player::amnt_by_clr(color)<cards_to_throw)
            {
                throw invalid_argument("There are no enough cards to discover a cure");
            }
            while(it!=cards.end() && count<cards_to_throw)
            {
                if(city_color(*it)==color)
                {
                    City city=*it;
                    it++;
                    throw_card(city);
                    count++;
                }
                else
                {
                    it++;
                }
            }
            cure_for_disease(color)=true;
        }
    return *this;
}


string Scientist::role()
{
    return "Scientist";
}
