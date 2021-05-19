
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::drive(City city)
{
    Player::drive(city);
    if(cure_for_disease(city_color(city)))
    {
        board[city]=0;
    }
    return *this;
}
Player& Medic::fly_direct(City city)
{
    Player::fly_direct(city);
    if(cure_for_disease(city_color(city)))
    {
        board[city]=0;
    }
    return *this;
}
Player& Medic::fly_charter(City city)
{
    Player::fly_charter(city);
    if(cure_for_disease(city_color(city)))
    {
        board[city]=0;
    }
    return *this;
}
Player& Medic::fly_shuttle(City city)
{
    Player::fly_shuttle(city);
    if(cure_for_disease(city_color(city)))
    {
        board[city]=0;
    }
    return *this;
}

Player& Medic::treat(City city)
{
    if(curr_city!=city)
    {
            throw invalid_argument("The current city is different");
    }
        
    if(board[city]==0)
    {
        throw out_of_range("The current city is free of contamination");
    }
    board[city]=0;
    return *this;
}

string Medic::role()
{
    return "Medic";
}
