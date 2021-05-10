
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

FieldDoctor::FieldDoctor (Board &b, City c) : Player(b,c)
{}


Player& FieldDoctor::treat(City city)
{
       
       if(curr_city!=city && !is_nbr(city))
        {
             throw invalid_argument("Your current city " +board.get_city_name(curr_city)+
            "is not connected to " +board.get_city_name(city));
        }
        
        if(board.cities.at(city).cubes==0)
        {
            throw out_of_range("The city "+ board.get_city_name(city)+
            " is free of contamination");
        }
        if(board.diseases.at(board.cities.at(city).color))
        {
            board.cities.at(city).cubes=0;
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
