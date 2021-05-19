#pragma once
#include <ostream>
using namespace std;
namespace pandemic
{
    enum class Color{

        Blue,
        Yellow,
        Black,
        Red

    };


std::string get_disease_name(Color color);
}

