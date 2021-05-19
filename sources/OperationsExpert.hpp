#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace pandemic;

class OperationsExpert:public Player{

    public:
        OperationsExpert (Board &b, City c) : Player(b,c){}
        virtual Player& build();
        virtual std::string role();

};

