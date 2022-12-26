/*
@author: Mattia Scantamburlo

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
#include "cell.h"

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
    protected:
    //CONSTRUCTORS
        //constructor accepting boats const reference
        grid(const std::vector<boat>& b);
        //constructor accepting coordinates for begin and end of boats
        grid(std::initializer_list<coordinates> lst);
        
    //FUNCTION MEMBERS

    //OPERATORS

    private:
    //DATA MEMBERS
        std::unique_ptr<cell> map_[COLUMNS][ROWS];
        std::unique_ptr<boat> b [BOAT_NUMBER];
    };

}
#endif 