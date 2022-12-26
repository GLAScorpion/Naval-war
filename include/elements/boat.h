/*
@author: Mattia Scantamburlo


SHORT DEFINITION:
-->An abstract class that describes the basic features of a boat
*/

#ifndef BOAT_H
#define BOAT_H

#include <iostream>

#include <utilities.h>

namespace game_elements{
    constexpr  int BOAT_NUMBER = 8;
    class boat{
    public:
        //deleted copy assignment, copy constructor and no argument constructor
        boat(const boat& b) = delete;
        boat& operator=(const boat& b) = delete;
        boat() = delete; //it doesn't makes sense to create a boat with default properties 
        
    protected:

    private:
        std::vector<boat> boats_; 
    };

}

#endif 