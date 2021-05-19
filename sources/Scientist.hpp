#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace pandemic;

class Scientist:public Player{

    private:
        int cards_to_throw;
    public:
        Scientist (Board &b, City c,int n) : Player(b,c), cards_to_throw(n){}
        virtual Player& discover_cure(Color color); 
        virtual string role();
};
