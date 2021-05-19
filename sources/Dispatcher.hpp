#pragma once
#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
using namespace pandemic;

class Dispatcher:public Player{
    
    public:
        Dispatcher(Board &b, City c) : Player(b,c){}
        virtual Player& fly_direct(City city);
        virtual std::string role();
};
