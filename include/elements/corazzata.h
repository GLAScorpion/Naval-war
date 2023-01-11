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

namespace game_elements{
    constexpr int CORAZZATA_SIZE = 5;
    constexpr char CORAZZATA_SYM = 'C';

    class attack_grid;

    class corazzata : public boat{
    public:

    //CONSTRUCTORS

        //deleted no argument constructor (there are none default properties for a corazzata)
        corazzata() = delete;

        //call the base class constructor with coordinates vector
        corazzata(const coordinates& begin, const coordinates& end) : boat(begin,end){}
    
    //FUNCTION MEMBERS
            
        //return true if it shoot
        bool action(defense_grid* dg, attack_grid* ag, const coordinates& coord) override;

        char get_symbol() override {  return CORAZZATA_SYM;}
    };
}

#endif 