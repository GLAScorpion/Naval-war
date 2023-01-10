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

    constexpr char CORAZZATA = 'C';
    constexpr char SUPPORTO = 'S';
    constexpr char ESPLORAZIONE = 'E';

    class boat;
    class coordinates;

    class defense_grid : public grid{
    public:
    //CONSTRUCTOR
        //deleted no arguments constructor (there are none default properties)
        defense_grid() = delete;
        //constructor accepting vector of coordinates for begin and end of boats
        defense_grid(const std::vector<coordinates>& c);
        //deleted copy 
        defense_grid(const defense_grid& ag) = delete;

    //FUNCTION MEMBERS
        //allow boat operations in the grid, throw exception if it is not possible 
        void set_boat(boat* b, const coordinates& begin);
        //return a vector with all the boats that have a distance from the given coordinates smaller than radius 
        std::vector<boat*> boats_in_radius(const coordinates& c, int radius)  override;
        //return boat pointer to allow operations on the boat 
        boat* get_boat(const coordinates& c) const override;
        //check if coordinates match the dimension of the grid
        bool check_coordinates(const coordinates& c) const;
        //print the grid
        std::ostream& write(std::ostream& os) const;
        //set map cell, throw exception if coord is invalid
        void set_cell(const coordinates& coord, char boat_symbol);
        //return the value of the cell in the given coordinates, throw exception if coord is invalid
        char get_cell(const coordinates& coord);
        //return true if the move is possible
        bool check_move(boat* b, const coordinates& begin);
        //return all boats
        std::vector<boat*> get_boats() const override;

    //OPERATORS
        //deleted copy assignment
        defense_grid& operator=(const defense_grid& ag) = delete;
        
    private:
    //DATA MEMBERS
        char map_[COLUMNS][ROWS]; 
        std::vector<boat*> boats_ = std::vector<boat*> (8); 
    };
    //OPERATORS
        //insertion operator
        std::ostream& operator<<(std::ostream& os, const defense_grid& dg);
    
}

#endif 