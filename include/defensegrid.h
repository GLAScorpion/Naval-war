/*
@author: MATTIA SCANTAMBURLO

SHORT DEFINITION:
--> Contain a derived class(and some elements related to it) which inherit from the base class grid and 
    gives a representation of the defense side of the naval battle grid.
*/

#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <iostream>

#include "../include/grid.h"

namespace game_elements{

    constexpr char CORAZZATA = 'C';
    constexpr char SUPPORTO = 'S';
    constexpr char ESPLORAZIONE = 'E';

    class boat;
    class coordinates;

    class defense_grid : public grid{
        public:
            //CONSTRUCTORS

                //no arguments constructor
                defense_grid();

                //deleted copy constructor
                defense_grid(const defense_grid& ag) = delete;

            //MEMBER FUNCTIONS

                //allows boat operations in the grid, throws exception if it is not possible 
                bool move(boat* b, const coordinates& begin);

                //adds boat to boats_
                void push_boat(boat* b) {   boats_.push_back(b);}

                //returns a vector with all the boats that have a distance from the given coordinates smaller than radius 
                std::vector<boat*> boats_in_radius(const coordinates& c, int radius)  override;

                //returns boat pointer to allow operations on the boat 
                boat* get_boat(const coordinates& c) const override;

                //checks if coordinates match the dimension of the grid
                bool check_coordinates(const coordinates& c) const;

                //prints the grid
                const std::string write() const;

                //sets map cell, throws exception if coord is invalid
                void set_cell(const coordinates& coord, char boat_symbol);

                //returns the value of the cell in the given coordinates, throws exception if coord is invalid
                char get_cell(const coordinates& coord);

                //returns true if the move is possible
                bool check_move(boat* b, const coordinates& begin);

                //returns all boats
                std::vector<boat*> get_boats() const override;

                //deletes boat
                void del_boat(boat* b) override;

            //OPERATORS

                //deleted copy assignment
                defense_grid& operator=(const defense_grid& ag) = delete;
                
        private:
            //DATA MEMBERS

                char map_[ROWS][COLUMNS]; 
                std::vector<boat*> boats_; 
    };

    //OPERATORS

        //insertion operator
        std::ostream& operator<<(std::ostream& os, const defense_grid& dg);
    
}

#endif 