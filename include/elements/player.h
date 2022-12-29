/*
@author

SHORT DEFINITION:
    Abstract class that defines all the operation possible for a general player (robot or person)  
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

//#include "" 

namespace game_elements{
    
    class player{

    public:
    //CONSTRUCTORS
        //copy constructor (deleted)
        player(const player& p) = delete;
        //no argument constructor
        //player() = delete;
    //OPERATORS
        //copy assignment (deleted)
        player& operator=(const player& p) = delete;
    protected:

    private:

    };

}
#endif 