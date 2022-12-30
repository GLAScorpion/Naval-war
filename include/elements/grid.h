/*
@author: 

SHORT DEFINITION:
--> This abstract class describes the general behavior of a grid
--> A grid constructor accept a initilizer_list of coordinates of begin and end of each boat
    adjacent in the vector 
*/
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

#include "boat.h"
#include "corazzata.h"
#include "supporto.h"
#include "esplorazione.h"
#include "utilities.h"

namespace game_elements{
    
    constexpr int COLUMNS = 12;
    constexpr int ROWS = 12; 
    constexpr int CORAZZATA_SIZE = 5;
    constexpr int SUPPORTO_SIZE = 3;
    constexpr int ESPLORAZIONE_SIZE = 1;
    constexpr int BOAT_NUMBER = 8;

    class grid{
    public:
    //PUBLIC CONSTRUCTORS
        //deletes copy constructors
        grid(const grid& g) = delete;
                
    //FUNCTION MEMBERS
        //return a vector with all the boat pointers that have a distance from the given coordinates smaller than radius 
        virtual std::vector<boat*> boat_in_radius(const coordinates& c, int radius) const = 0;
        //return boat pointer to allow operations on the boat 
        virtual boat* get_boat(const coordinates& c) const = 0;

    //OPERATORS
        //deleted copy assignment operator
        grid& operator=(const grid& g) = delete;  
        
    protected:
        //no arguments constructor
        grid() {};
    };



}
#endif 