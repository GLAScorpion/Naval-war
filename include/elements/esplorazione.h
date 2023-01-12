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

        //call the base class constructor with coordinates vector
        esplorazione(const coordinates& begin, const coordinates& end) : boat(begin,end){if(dimension_ != get_dimension()) throw std::logic_error("Size mismatch");}

    //FUNCTION MEMBERS

        //move the boat to the given coordinates and find all the boats in a radius of 5 
        bool action(defense_grid* dg, attack_grid* ag, const coordinates& coord) override;

        char get_symbol() override {  return ESPLORAZIONE_SYM;}

        int get_dimension() const override {return ESPLORAZIONE_SIZE;}

    };
}

#endif 