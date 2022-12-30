/*
@author 
SHORT DEFINITION:
    derived class (from boat) which define all the operation that a "corazzata" boat is capable of doing and 
    receiving (attack, being attacked,...etc)
*/

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include <iostream>

#include "boat.h"
#include "attackgrid.h"

namespace game_elements{
    class corazzata : public boat{
    public:
    //CONSTRUCTORS
        //deleted no argument constructor (there are none default properties for a corazzata)
        corazzata() = delete;
        //call the base class constructor with coordinates vector
        corazzata(const coordinates& begin, const coordinates& end) : boat(begin,end){}
    //FUNCTION MEMBERS
        //return true if it attacked a boat
        bool attack(attack_grid& ag, const coordinates& coord);
    };
}

#endif 