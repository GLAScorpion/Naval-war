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
    
    constexpr int SUPPORTO_SIZE = 3;
    constexpr int SUPPORTO_RADIUS = 1;
    constexpr char SUPPORTO_SYM = 'S';

    class defense_grid;

    class supporto : public boat{
    public:

    //CONSTRUCTORS

        //deleted no argument constructor (there are none default properties for a esplorazione boat)
        supporto() = delete;

        //calls the base class constructor with coordinates vector
        supporto(const coordinates& begin, const coordinates& end) : boat(begin,end){   if(dimension_ != get_dimension()) throw std::logic_error("Size mismatch");}

    //MEMBER FUNCTIONS
    
        //moves the boat to the given coordinates and heals all the boats in a radius of 1 (3x3 square) 
        bool action(defense_grid* dg, attack_grid* ag, const coordinates& coord) override;

        char get_symbol() override {  return SUPPORTO_SYM;}

        int get_dimension() const override {return SUPPORTO_SIZE;}

    };

}

#endif 