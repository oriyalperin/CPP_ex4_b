
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;



Player& Virologist::treat(City city)
{
        
        if(board[city]==0)
        {
            throw out_of_range("The city is free of contamination");
        }
        bool in_cards =cards.find(city)!=cards.end();
        if(curr_city!=city && !in_cards)
        {
            throw out_of_range("The city card is missing");
        }

        if(cure_for_disease(city_color(city)))
        {
            board[city]=0;
        }
        else
        {
            board[city]-=1;
        }
        if(curr_city!=city && in_cards)
        {
            throw_card(city);
        }
    return *this;
}

string Virologist::role()
{
    return "Virologist";
}
