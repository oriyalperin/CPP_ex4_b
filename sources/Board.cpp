
#include <iostream>

#include <string>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <array>
#include <list>
#include "Board.hpp"
#include <sstream>

using namespace std;
using namespace pandemic;


Board::Board()
{
    
    ifstream cities_file{"cities_map.txt"};
    read_cities(cities_file);
    diseases[Color::Black]=false;
    diseases[Color::Blue]=false;
    diseases[Color::Red]=false;
    diseases[Color::Yellow]=false;

}
string& Board::get_city_name(City city)
{
    return cities.at(city).name;
}

void Board::read_cities(ifstream& cities_file)
{
    int color=1;
    int city=2;
    int city_other=3;
    string name;
    string line{};
    while(getline(cities_file,line))
    {
        istringstream s{line};
        s>>city;
        s>>name;
        s>>skipws>>color;
        unordered_set <City> others{};
        while((s>>skipws>>city_other) )
        {
            others.insert(static_cast<City>(city_other));
        }
        cities.insert(pair<City,city_dtls>(static_cast<City>(city),city_dtls(name,(Color)color,others)));
        //cout<<cities.at((City)city).name<<endl;
    }
    

}

int& Board::operator[](City city) 
{
    try
    {
        return cities.at(city).cubes;
    }
    catch(const exception& e)
    {
        throw out_of_range("Array City out of bounds");
    }
    
}

string convert_disease(Color color)
{
    int x=(int)color;
    switch (x)
    {
    case 0:
        return "Blue";
    case 1:
        return "Yellow";
    case 2:
        return "Black";
    case 3:
        return "Red";    
    
    default:
        throw invalid_argument("illegal color");
    }
}
ostream& pandemic::operator<< (ostream& os, const Board& board)
{
    for(const auto& city: board.cities)
    {
        char rs=(city.second.rsrch_st)?  'V': 'X';
        cout<<"|-------------------------|"<<endl;
        cout<<"|";
        string name=city.second.name;
        const int middle=26;
        for(int i=0;i<(middle-name.size())/2;i++)
        {
            cout<<" ";
        }
        cout<<name;
        for(int i=0;i<name.size()/3;i++)
        {
            cout<<" ";
        }
        //cout<<"|"<<endl;
        cout<<endl;
        cout<<"| Color: "<<convert_disease(city.second.color)<<endl
        <<"| Disease: " <<city.second.cubes <<endl
        <<"| Reasrch Station: " << rs <<endl;
    }
    cout<<endl;
    for(const auto& color: board.diseases)
    {
        string c=convert_disease(color.first);
        char treat =(color.second)?  'V': 'X';
        cout<<c<<", cure: " <<treat<<endl;

    }
    return os;
}


bool Board::is_clean()
{
    for(auto& city: cities)
    {
        if(city.second.cubes!=0)
        {
            return false;
        }
    }
    return true;
}

void Board::remove_cures()
{
    for(auto& c : diseases)
    {
        c.second=false;
    }
}

void Board::remove_stations()
{
    for(auto& c : cities)
    {
        c.second.rsrch_st=false;
    }
}

