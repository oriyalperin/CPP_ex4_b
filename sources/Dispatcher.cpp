
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Dispatcher::Dispatcher (Board &b, City c) : Player(b,c)
{}

Player& Dispatcher::fly_direct(City city)
{
    if(city==curr_city)
    {
        throw invalid_argument("You are already at " +board.get_city_name(curr_city)+" city");
    }
    if(board.cities.at(curr_city).rsrch_st)
    {
        curr_city=city;
    }
    else
    {
        Player::fly_direct(city);
    }
    
    return *this;
}

string Dispatcher::role()
{
    return "Dispatcher";
}
