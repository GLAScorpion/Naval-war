/*
@author

SHORT DEFINITION:
    Abstract class that defines all the operation possible for a general player (robot or person)  
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "defensegrid.h"
//#include "" 

namespace game_elements{
    class attack_grid;
    class player{

    public:
    //CONSTRUCTORS
        //copy constructor (deleted)
        player(const player& p) = delete;
        //no argument constructor
        player():dg{new defense_grid()}{}
    //MEMBER FUNCTIONS
        void link(const player* other);
    //OPERATORS
        //copy assignment (deleted)
        player& operator=(const player& p) = delete;
    protected:
        attack_grid* ag = nullptr;
        defense_grid* dg;
    private:

    };

}
#endif 