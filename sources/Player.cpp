#include <iostream>
#include "Board.hpp"
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
using namespace std;
using namespace pandemic;

    void Player::throw_card(City city)
    {
        cards.erase(city);
        colors.at((unsigned)board.cities.at(city).color)--;
    }

    Player& Player::remove_cards()
    {
        cards.clear();
        return *this;
    }

    bool Player::is_nbr(City city)
    {
        return (board.cities.at(curr_city).nbrs.find(city)!=board.cities.at(curr_city).nbrs.end());
    }
    Player& Player::drive(City city)
    {
        if(city==curr_city)
        {
            throw invalid_argument("You are already at  " +board.get_city_name(curr_city)+" city");
        }
        if(!is_nbr(city))
        {
            throw invalid_argument("Your current city " +board.get_city_name(curr_city)+
            "is not connected to " +board.get_city_name(city));
        }
        curr_city=city;
        return *this;
        
    }

    Player& Player::fly_direct(City city)
    {
        if(city==curr_city)
        {
            throw invalid_argument("You are already at  " +board.get_city_name(curr_city)+" city");
        }
        if( cards.find(city)== cards.end())
        {
            throw invalid_argument("The card of " +board.get_city_name(city)+ " is missing");
        }

        throw_card(city);
        curr_city=city;
        return *this;
    }
    Player& Player::fly_charter(City city)
    {
        if(city==curr_city)
        {
            throw invalid_argument("You are already at  " +board.get_city_name(curr_city)+" city");
        }
        if( cards.find(curr_city)== cards.end())
        {
            throw invalid_argument("The card of your current city " +
            board.get_city_name(curr_city)+ " is missing");
        }
        throw_card(curr_city);
        curr_city=city;

        return *this;

    }
    Player& Player:: fly_shuttle(City city)
    {
        if(city==curr_city)
        {
            throw invalid_argument("You are already at  " +board.get_city_name(curr_city)+" city");
        }
        if(!board.cities.at(curr_city).rsrch_st)
        {
            throw invalid_argument("There is no research station in your current city "+
            board.get_city_name(curr_city));
        }
        if(!board.cities.at(city).rsrch_st)
        {
            throw invalid_argument("There is no research station in "+board.get_city_name(city));
        }
        curr_city=city;
        return *this;

    }


    Player& Player::build()
    {
        if(cards.find(curr_city)==cards.end())
        {
            throw invalid_argument("The card of your current city " 
            +board.get_city_name(curr_city)+ " is missing");
        }
        throw_card(curr_city);
        board.cities.at(curr_city).rsrch_st=true;
        return *this;
    }

    Player& Player::discover_cure(Color color)
    {
        if(!(board.cities.at(curr_city).rsrch_st))
        {
            throw invalid_argument("There is no research station in "+board.get_city_name(curr_city));
        }
        
        if(!board.diseases.at(color))
        {   
            int count=0;
            const int droped_cards=5;
            const int cards_in_color=amnt_by_clr(color);
            if(cards_in_color<droped_cards)
            {
                throw invalid_argument("There are only " +to_string(cards_in_color) +
                ", you need " + to_string(droped_cards-cards_in_color) + " more");
            }
                unordered_set<City>::iterator it = cards.begin();
                while(it!=cards.end() && count<droped_cards)
                {
                    if(board.cities.at(*it).color==color)
                    {
                        City city=*it;
                        it++;
                        throw_card(city);
                        count++;
                    }
                    else 
                    {
                        it++;
                    }
                }
                    board.diseases.at(color)=true;
        }
        return *this;
    }

    Player& Player::treat(City city)
    {
        if(curr_city!=city)
        {
           throw invalid_argument("Can't treat in "  
            +board.get_city_name(city)+ " city, because your current city is "
            +board.get_city_name(curr_city));
        }
        
        if(board.cities.at(city).cubes==0)
        {
            throw out_of_range("Your current city "+ board.get_city_name(city)+
            " is free of contamination");
        }
        if(board.diseases.at(board.cities.at(city).color))
        {
            //board.size_cubes()-= board.cities.at(city).cubes;
            board.cities.at(city).cubes=0;
        }
        else
        {
            board[city]-=1;
           // cout<<board.cities.at(city).cubes<<endl;
            //board.size_cubes()-=1;
        }
        return *this;
    }

    int Player::amnt_by_clr(Color color)
    {
        return colors.at(static_cast<unsigned>(color));
    }


    Player& Player::take_card(City city)
    { 
        if(cards.find(city)==cards.end())
        {
            cards.insert(city);
            
            colors.at(static_cast<unsigned>(board.cities.at(city).color))++;
        }
        return *this;
        
    }

    string Player::role()
    {
        return "Player";
    }

