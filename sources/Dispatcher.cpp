
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City city)
{
    if(city==curr_city)
    {
        throw invalid_argument("You are already at " +board.get_city_name(curr_city)+" city");
    }
    if(research_station(curr_city))
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
