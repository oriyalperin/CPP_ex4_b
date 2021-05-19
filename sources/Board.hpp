#pragma once
#include <ostream>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>


 namespace pandemic
 {
    class Board
    {        
        private:
            void read_cities_diseases(std::ifstream& cities_file);
            std::unordered_map<City,city_dtls> cities;
            std::unordered_map<Color,bool> diseases;
        public:
            Board();
            int& operator[](City city);
            friend std::ostream& operator<< (std::ostream& os, const Board& board);
            bool is_clean();
            void remove_cures();
            void remove_stations();
            std::string get_city_name(City city);
            void show_diseases(); //only for main
            friend class Player;
           
    };
    
 }