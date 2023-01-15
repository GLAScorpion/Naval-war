/*
@author: MATTIA SCANTAMBURLO

SHORT DEFINITION:
--> This is a derived class(and some elements related to it) which inherit from the base class grid and 
    gives a representation of the attacking side of the naval battle grid.

*/

#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include <iostream>

#include "../include/grid.h" 
#include "../include/defensegrid.h"

namespace game_elements{

    constexpr char HIT = 'X';
    constexpr char ABSENT = 'O';
    constexpr char SONAR = 'Y';

    class coordinates;
    class boat;

    class attack_grid : public grid{
        public:
            //CONSTRUCTORS

                //deleted no arguments constructor (there are none default properties)
                attack_grid() = delete;

                //constructor accepting a defense grid 
                attack_grid(defense_grid* dg);

                //deleted copy constructor
                attack_grid(const attack_grid& ag) = delete;

            //MEMBER FUNCTIONS

                //returns a vector with all the boats that have a distance from the given coordinates smaller than radius 
                std::vector<boat*> boats_in_radius(const coordinates& coord, int radius) override;

                //returns boat pointer to allow operations on the boat 
                boat* get_boat(const coordinates& coord) const override;

                //sets map cell, throws exception if coord is invalid
                void set_cell(const coordinates& coord, char symbol);

                //returns the value of the cell in the given coordinates, throws exception if coord is invalid
                char get_cell(const coordinates& coord);

                //checks if the given coordinates match the dimension of the grid
                bool check_coordinates(const coordinates& c) const;

                //prints the grid
                const std::string write() const;

                //returns all boats in a vector
                std::vector<boat*> get_boats() const override;

                //removes all symbols ==symbol from grid
                void clear_symbol(char symbol);

                //removes a boat
                void del_boat(boat* b) override {  others_grid_->del_boat(b);}

                //returns the defense grid of the opponent
                defense_grid* get_other_grid() {  return others_grid_;}

            //OPERATORS

                //deleted copy assignment
                attack_grid& operator=(const attack_grid& ag) = delete;

        private:
            //DATA MEMBERS

                game_elements::defense_grid* others_grid_ = nullptr;
                char map_[ROWS][COLUMNS]; 
    };

    //OPERATORS

        //insertion operator overloading
        std::ostream& operator<<(std::ostream& os, const attack_grid& ag);

}

#endif 