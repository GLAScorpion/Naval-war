/*
@author: ALBERTO PASINATO

SHORT DEFINITION:
    derived class (from boat) which define all the operation that a "corazzata" boat is capable of doing and 
    receiving (attack, being attacked,...etc)
*/

#ifndef CORAZZATA_H
#define CORAZZATA_H

#include <iostream>

#include "../include/boat.h"

namespace game_elements{

    constexpr int CORAZZATA_SIZE = 5;
    constexpr char CORAZZATA_SYM = 'C';

    class attack_grid;

    class corazzata : public boat{
        public:
            //CONSTRUCTORS

                //deleted no argument constructor (there are none default properties for a corazzata)
                corazzata() = delete;

                //calls the base class constructor with coordinates vector
                corazzata(const coordinates& begin, const coordinates& end) : boat(begin,end){  if(dimension_ != get_dimension()) throw std::logic_error("Size mismatch");}
            
            //MEMBER FUNCTIONS
                    
                //returns true if it shot
                bool action(defense_grid* dg, attack_grid* ag, const coordinates& coord) override;

                //returns the symbol of corazzata boat
                char get_symbol() override {  return CORAZZATA_SYM;}

                //returns the size of corazzata boat
                int get_dimension() const override {return CORAZZATA_SIZE;}
    };
}

#endif 