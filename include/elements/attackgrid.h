/*
@author:

SHORT DEFINITION:
--> This is a derived class(and some elements related to it) which inherit from the base class grid and 
    gives a representation of the attacking side of the naval battle.
*/
#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include <iostream>

#include "grid.h" 

namespace game_elements{
    constexpr char HIT = 'X';
    constexpr char ABSENT = 'O';
    constexpr char SONAR = 'Y';

    class coordinates;
    class defense_grid;
    class boat;

    class attack_grid : public grid{

    public:

    //CONSTRUCTORS

        //deleted no argumentsa constructor (there are none default properties)
        attack_grid() = delete;

        //constructor accepting a defense grid 
        attack_grid(defense_grid* dg);

        //deleted copy 
        attack_grid(const attack_grid& ag) = delete;

    //FUNCTION MEMBERS

        //return a vector with all the boats that have a distance from the given coordinates smaller than radius 
        std::vector<boat*> boats_in_radius(const coordinates& coord, int radius) override;

        //return boat pointer to allow operations on the boat 
        boat* get_boat(const coordinates& coord) const override;

        //set map cell, throw exception if coord is invalid
        void set_cell(const coordinates& coord, char symbol);

        //return the value of the cell in the given coordinates, throw exception if coord is invalid
        char get_cell(const coordinates& coord);

        //check if coordinates match the dimension of the grid
        bool check_coordinates(const coordinates& c) const;

        //print the grid
        std::ostream& write(std::ostream& os) const;

        //return all boats
        std::vector<boat*> get_boats() const override;

    //OPERATORS

        //deleted copy assignment
        attack_grid& operator=(const attack_grid& ag) = delete;

    private:

    //DATA MEMBERS

        game_elements::defense_grid* others_grid_ = nullptr;
        
        char map_[ROWS][COLUMNS]; 
        //std::vector<boat*> boats_[BOAT_NUMBER]; 
    };

//OPERATORS

        //insertion operator overloading
        std::ostream& operator<<(std::ostream& os, const attack_grid& ag);

}

#endif 