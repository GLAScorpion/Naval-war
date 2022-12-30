/*
@author 
SHORT DEFINITION:
    derived class (from boat) which define all the operation that a "supporto" boat is capable of doing and 
    receiving (heal, being attacked, move,...etc)
*/


#ifndef SUPPORTO_H
#define SUPPORTO_H

#include <iostream>

#include "boat.h"

namespace game_elements{

    class supporto : public boat{
    public:
    //CONSTRUCTORS
        //deleted no argument constructor (there are none default properties for a esplorazione boat)
        supporto() = delete;
        //call the base class constructor with coordinates vector
        supporto(const coordinates& begin, const coordinates& end) : boat(begin,end){}
    //FUNCTION MEMBERS
        //move the boat to the given coordinates and heals all the boats in a radius of 5 
        void move_and_heal(defense_grid& dg, const coordinates& coord);
    };

}

#endif 