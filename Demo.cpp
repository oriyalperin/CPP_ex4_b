#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <iostream>
using namespace pandemic;
using namespace std;



int main() {
	Board board;
    OperationsExpert oe{board,City::Atlanta};
    oe.show_curr_city();
    Dispatcher d{board,City::Baghdad};
    d.show_curr_city();
    Researcher r{board,City::HongKong};
    r.show_curr_city();
    Virologist v{board,City::London};
    v.show_curr_city();
    Medic m{board,City::Madrid};
    m.show_curr_city();
    Scientist s{board,City::Sydney,2};
    s.show_curr_city();
    GeneSplicer gs{board,City::Tehran};
    gs.show_curr_city();
    FieldDoctor fd{board,City::Washington};
    fd.show_curr_city();
    board[City::Tehran]=3; 
    board[City::Sydney]=4; 
    board[City::Baghdad]=4; 
    board[City::London]=5; 
    board[City::Atlanta]=7; 
    board[City::Madrid]=3; 
    board[City::HongKong]=5; 
    board[City::MexicoCity]=4; 
    board[City::Miami]=4; 
    board[City::SanFrancisco]=5;
    board[City::Chicago]=6;
    board[City::Montreal]=3; 
    board[City::NewYork]=2;  
    board[City::Johannesburg]=1;
    cout<<"*************************"<<endl;
    cout<<"        the board       "<<endl;
    cout<<"*************************"<<endl;
    cout<<board<<endl;
    oe.take_card(City::Chicago).
    take_card(City::MexicoCity).
    take_card(City::SanFrancisco).
    take_card(City::Montreal).
    take_card(City::NewYork). 
    take_card(City::Miami);//4 blue, 2 yellow
    oe.show_cards();
    cout<<"***Operations Expert - drive to Miami***"<<endl;
    oe.drive(City::Miami); //curr_city= miami
    cout<<"***Operations Expert - build in Miami***"<<endl;
    oe.build(); //miami - V
    cout<<"***Operations Expert -  try to discover cure for yellow disease***"<<endl;
    try
    {(oe.discover_cure(Color::Yellow));
    }
    catch(exception &e)
    {
        cerr<<e.what()<<endl;
    }
    cout<<"***Field Doctor - treat Miami***"<<endl;
    fd.treat(City::Miami); // miami=3
    cout<<"***Gene Splicer -  try to build in Tehran***"<<endl;
    try
    {
        (gs.build()); //doesnt have curr_city=Tehran card
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    gs.take_card(City::Tehran);//in order to build a research station
    gs.build(); //Tehran - V
    gs.take_card(City::Milan).
    take_card(City::Osaka).
    take_card(City::Riyadh).
    take_card(City::Jakarta); //1 black, 2 red, 1 blue
    gs.show_cards();
    cout<<"***Gene Splicer -  try to discover cure for yellow disease***"<<endl;
    try
    {
        (gs.discover_cure(Color::Yellow));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    gs.take_card(City::Algiers); //2 black, 2 red, 1 blue
    gs.show_cards();
    cout<<"***Gene Splicer - discover cure for yellow disease***"<<endl;
    gs.discover_cure(Color::Yellow); // Yellow - V , gs - 0 cards
    board.show_diseases();
    cout<<"***Gene Splicer - discover cure for yellow disease again***"<<endl;
    oe.discover_cure(Color::Yellow); //nothing happen
    cout<<"***Operations Expert - treat Miami***"<<endl;
    oe.treat(City::Miami); //miami = 0
    cout<<"---Miami: "<<board[City::Miami]<<"---"<<endl;
    cout<<"***Virologist - try to treat san Francisco***"<<endl;
    try
    {
        (v.treat(City::SanFrancisco));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    v.take_card(City::SanFrancisco); // 1 blue 
    v.show_cards();
    cout<<"***Virologist - try to treat san Montreal***"<<endl;
    try
    {
        (v.treat(City::Montreal)); //have just SanFransisco card, but no Montreal
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    cout<<"***Virologist - treat san Francisco***"<<endl;
    v.treat(City::SanFrancisco);  //SanFransisco =4
    cout<<"---San Fransisco: "<<board[City::SanFrancisco]<<"---"<<endl;
    r.take_card(City::StPetersburg).
    take_card(City::Paris).
    take_card(City::Essen).
    take_card(City::Madrid).
    take_card(City::Atlanta); // 5 blue cards
    r.show_cards();
    cout<<"***Researcher - discover cure for blue disease***"<<endl;
    r.discover_cure(Color::Blue); // Blue - V
    cout<<"***Medic - treat Madrid***"<<endl;
    m.treat(City::Madrid); // Madrid = 0
    cout<<"***Medic - drive to New York***"<<endl;
    m.drive(City::NewYork); // the medic reset cubes automatically
    cout<<"---New York: "<<board[City::NewYork]<<"---"<<endl;
    cout<<"***Dispatcher - drive to Tehran***"<<endl;
    d.drive(City::Tehran); 
    cout<<"***Dispatcher - fly direct to Tehran***"<<endl;
    d.fly_direct(City::Sydney); //can fly to any city if he is at rsrch st
    d.take_card(City::Sydney);
    d.show_cards();
    cout<<"***Dispatcher - build in Sydney***"<<endl;
    d.build(); //Sydney - V
    cout<<"***Scientist - try to discover cure for red disease***"<<endl;
    try
    {
        (s.discover_cure(Color::Red)); //have no cards
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    s.take_card(City::Osaka).take_card(City::Chennai);
    s.show_cards();
    cout<<"***Scientist - try to discover cure for red disease***"<<endl;
    try
    {
        (s.discover_cure(Color::Red)); //have no cards
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    } //need one more red card(2 red cards to discover)
    s.take_card(City::HoChiMinhCity);
    s.show_cards();
    cout<<"***Scientist - discover cure for red disease***"<<endl;
    s.discover_cure(Color::Red); //Red - V
    board.show_diseases();
    cout<<"***Dispatcher - treat Sydney***"<<endl;
    d.treat(City::Sydney); //Sydney = 0
    cout<<"---Sydney: "<<board[City::Sydney]<<"---"<<endl;
    cout<<"***Medic - drive to Montreal***"<<endl;
    m.drive(City::Montreal); //curr_city= Montreal Montreal = 0
    cout<<"---Montreal: "<<board[City::Montreal]<<"---"<<endl;
    r.take_card(City::Delhi).
    take_card(City::Mumbai).
    take_card(City::Kolkata).
    take_card(City::Cairo).
    take_card(City::Mumbai); // 4 black
    r.show_cards();
    cout<<"***Researcher - try to discover cure for black disease***"<<endl;
    try
    {
        (r.discover_cure(Color::Black)); // 2 duplicate cards of mumbai
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    r.take_card(City::Istanbul);// 5 Black 
    r.show_cards();
    cout<<"***Researcher - discover cure for black disease***"<<endl;
    r.discover_cure(Color::Black); //Black - V
    board.show_diseases();
    cout<<"***Operations Expert - fly shuttle to Tehran and treat there***"<<endl;
    oe.fly_shuttle(City::Tehran).treat(City::Tehran);//treat tehran. Tehran = 0
    cout<<"***Operations Expert - drive to Baghdad and treat there***"<<endl;
    oe.drive(City::Baghdad).treat(City::Baghdad); //Baghdad = 0
    cout<<"***Operations Expert - try to treat Washington***"<<endl;
    try
    {
       (fd.treat(City::Washington));//Washington is free 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    cout<<"***Field Doctor - treat Atlanta***"<<endl;
    fd.treat(City::Atlanta); //Atlanta = 0
    fd.take_card(City::Washington);
    fd.show_cards();
    cout<<"***Field Doctor - fly charter to London and treat there***"<<endl;
    fd.fly_charter(City::London).treat(City::London); //London = 0
    cout<<"***Field Doctor - try to treat SanFrancisco***"<<endl;
    try
    {
        (fd.treat(City::SanFrancisco));//inaccessible
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cout<<"---San Francisco: "<<board[City::SanFrancisco]<<"---"<<endl;
    cout<<"***Field Doctor - try to fly direct to SanFrancisco***"<<endl;
    try
    {
        (fd.fly_direct(City::SanFrancisco));//no card of SanFrancisco
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    fd.take_card(City::SanFrancisco);
    fd.show_cards();
    cout<<"***Field Doctor - fly direct to SanFrancisco* and treat there**"<<endl;
    fd.fly_direct(City::SanFrancisco).treat(City::SanFrancisco); //SanFrancisco=0

    cout<<"---San Francisco: "<<board[City::SanFrancisco]<<"---"<<endl;
    cout<<"***Researcher - treat Hong Kong*"<<endl;
    r.treat(City::HongKong); //HongKong=0
    cout<<"***Operations Expert - drive to Tehran, fly direct to Miami, drive to MexicoCity and treat there***"<<endl;
    oe.drive(City::Tehran).
    fly_direct(City::Miami).
    drive(City::MexicoCity).treat(City::MexicoCity); //Mexico = 0
    v.take_card(City::Khartoum);
    v.show_cards();
    cout<<"***Virologist - try to treat Johannesburg***"<<endl;
    try
    {
        (v.treat(City::Johannesburg));//need Johannesburg card
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    v.take_card(City::Johannesburg);
    v.show_cards();
    cout<<"***Virologist - treat Johannesburg***"<<endl;
    v.treat(City::Johannesburg); // Johannesburg = 0
    cout<<"***Medic - drive to Chicago***"<<endl;
    m.drive(City::Chicago); //Chicago = 0
    cout<<"*************************"<<endl;
    cout<<"        the board        "<<endl;
    cout<<"*************************"<<endl;
    cout<<board<<endl;
    string clean={board.is_clean()==1? "board is clean" : "board is not clean"};
    cout<<clean<<endl;
}