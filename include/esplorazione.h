/*
@author: ALBERTO PASINATO

SHORT DEFINITION:
    derived class (from boat) which define all the operation that a "esplorazione" boat is capable of doing and 
    receiving (explore, being attacked, move,...etc)
*/

#ifndef SOTTOMARINO_H
#define SOTTOMARINO_H

#include <iostream>

#include "../include/boat.h"

namespace game_elements{

    constexpr int ESPLORAZIONE_SIZE = 1;
    constexpr int ESPLORAZIONE_RADIUS =2;
    constexpr char ESPLORAZIONE_SYM = 'E';

    class attack_grid;

    class esplorazione : public boat{
        public:
            //CONSTRUCTORS

                //deleted no argument constructor (there are none default properties for a esplorazione boat)
                esplorazione() = delete;

                //callS the base class constructor with coordinates vector
                esplorazione(const coordinates& begin, const coordinates& end) : boat(begin,end){if(dimension_ != get_dimension()) throw std::logic_error("Size mismatch");}

            //MEMBER FUNCTIONS

                //moves the boat to the given coordinates and finds all the boats in a radius of 2 (5x5 square) 
                bool action(defense_grid* dg, attack_grid* ag, const coordinates& coord) override;

                //returns the symbol of esplorazione boat
                char get_symbol() const override {  return ESPLORAZIONE_SYM;}
                
                //returns the size of esplorazione boat
                int get_dimension() const override {return ESPLORAZIONE_SIZE;}
    };
}

#endif 