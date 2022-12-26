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
#include <memory>

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
        grid() = delete;
        grid(const grid& g) = delete;
        grid& operator=(const grid& g) = delete;  
                
    //FUNCTION MEMBERS

    //OPERATORS

    protected:
    //CONSTRUCTORS
        //constructor accepting boats const reference
        grid(const std::vector<boat>& b);
        //constructor accepting coordinates for begin and end of boats
        grid(std::initializer_list<coordinates> lst);

    private:
    //DATA MEMBERS
        int map_[COLUMNS][ROWS]; // the number BOAT_NUMBER is equivalent to an empty position in the grid, 
                                 // everything lower than that is the index of the unique_ptr boat array
        std::unique_ptr<boat> boats_[BOAT_NUMBER];
    };

}
#endif 