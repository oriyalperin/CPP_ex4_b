
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

Player& OperationsExpert::build()
{
    research_station(curr_city)=true;
    return *this;
}


string OperationsExpert::role ()  
{
    return "OperationsExpert";
}
