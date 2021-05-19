#pragma once
#include <ostream>
#include "Board.hpp"
#include <string>
#include "City.hpp"
#include <unordered_set>

using namespace pandemic;
namespace pandemic
{
 class Player
    {
    protected:
        City curr_city;
        unordered_set<City> cards;
        array<int,4> colors{0};
        Board& board;
        bool& research_station(City city);
        bool& cure_for_disease(Color color);
        Color city_color(City city);
        int amnt_by_clr(Color color);
        void throw_card(City city);
        bool is_nbr(City city);
    
    public:
        Player(Board &b,City c) : board(b), curr_city(c){};
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color); 
        virtual Player& treat(City city);
        virtual std::string role();
        Player& take_card(City city);
        Player& remove_cards();
        void show_cards();  //only for main
        void show_curr_city();  //only for main

    };
 }
    