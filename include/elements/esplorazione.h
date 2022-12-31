/*
@author 
SHORT DEFINITION:
    derived class (from boat) which define all the operation that a "esplorazione" boat is capable of doing and 
    receiving (explore, being attacked, move,...etc)
*/

#ifndef SOTTOMARINO_H
#define SOTTOMARINO_H

#include <iostream>

#include "boat.h"
#include "attackgrid.h"

namespace game_elements{

    constexpr int RADIUS = 5;

    class esplorazione : public boat{
    public:
    //CONSTRUCTORS
        //deleted no argument constructor (there are none default properties for a esplorazione boat)
        esplorazione() = delete;
        //call the base class constructor with coordinates vector
        esplorazione(const coordinates& begin, const coordinates& end) : boat(begin,end){}
    //FUNCTION MEMBERS
        //move the boat to the given coordinates and find all the boats in a radius of 5 
        void sonar(attack_grid& dg, const coordinates& coord);
    };
}

#endif 