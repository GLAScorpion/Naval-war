/*
@author:

SHORT DEFINITION:
--> This is a derived class which inherit from the base class grid, it also as members to describe 
    the defense side of the naval battle.
*/

#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <iostream>

#include "grid.h" 

namespace game_elements{

    class defense_grid : public grid{
    public:
        defense_grid() = delete;
    private:
    
    };

}

#endif 