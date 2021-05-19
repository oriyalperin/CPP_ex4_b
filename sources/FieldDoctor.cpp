
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City city)
{
       
       if(curr_city!=city && !is_nbr(city))
        {
             throw invalid_argument("Your current city " +board.get_city_name(curr_city)+
            "is not connected to " +board.get_city_name(city));
        }
        
        if(board[city]==0)
        {
            throw out_of_range("The city "+ board.get_city_name(city)+
            " is free of contamination");
        }
        if(cure_for_disease(city_color(city)))
        {
            board[city]=0;
        }
        else
        {
            board[city]-=1;

        }
        return *this;
    return *this;
}

string FieldDoctor::role()
{
    return "FieldDoctor";
}
