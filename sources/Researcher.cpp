
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;



Player& Researcher::discover_cure(Color color)
{
        if(!cure_for_disease(color))
        {   
            unordered_set<City>::iterator it = cards.begin();
            int count=0;
            const int cards_to_throw=5;
            if(Player::amnt_by_clr(color)>=cards_to_throw)
            {
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
            else
            {
                throw invalid_argument("There are no enough cards to discover a cure");
            }
        }
    return *this;
}

string Researcher::role()
{
    return "Researcher";
}

