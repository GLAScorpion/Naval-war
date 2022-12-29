/*
@author:

SHORT DEFINITION:
--> Contain a derived class(and some elements related to it) which inherit from the base class grid and 
    gives a representatin the defense side of the naval battle.
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