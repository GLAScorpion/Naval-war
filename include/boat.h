/*
@author: ALBERTO PASINATO

SHORT DEFINITION:
-->An abstract class that describes the basic features of a boat
*/

#ifndef BOAT_H
#define BOAT_H

#include "../include/utilities.h"
#include "../include/defensegrid.h"
#include "../include/attackgrid.h"

namespace game_elements{

    class boat{
        public:
            //PUBLIC CONSTRUCTORS

                //deleted copy constructor 
                boat(const boat& b) = delete;

                //deleted no argument constructor (there are none default properties for a boat)
                boat() = delete; 

            //MEMBER FUNCTIONS

                //returns the dimension of the boat
                virtual int get_dimension() const = 0;

                //returns the value of corazza
                int get_corazza() const {return corazza_;}

                //returns boat begin coordinates
                const coordinates& get_begin() const {return coord_begin_;}

                //returns boat end coordinates
                const coordinates& get_end() const {return coord_end_;}

                //returns tracker vector
                const std::vector<bool>& get_tracker() { return corazza_tracker_;}

                //returns boat centre coordinates
                const coordinates get_centre() const;

                //returns boat simbol in grid
                virtual char get_symbol() const = 0;

                //returns true if the boat is vertical, else it returns false 
                bool is_vertical() const;

                //sets corazza value to max
                void restore_corazza();

                //returns true if that piece of the boat has already been hit
                bool is_broken(const coordinates& coord) const;

                //reduces boat corazza of one unit if possible, throws exception if it's not
                void got_hit(const coordinates& coord);

                //sets the new coordinates of the boat , returns true in standard version
                bool set_coordinates(const coordinates& begin);

                //returns true if the given coordinates match the coordinates of the boat
                bool valid_coordinates(const coordinates& coord) const;

                //operate
                virtual bool action(defense_grid* dg,attack_grid* ag, const coordinates& coord) = 0; 

            //OPERATORS

                //deleted copy assignment
                boat& operator=(const boat& b) = delete;

        protected:
            //PROTECTED CONSTRUCTORS

                //constructor accepting coordinates for begin and end of boat
                boat(const coordinates& begin, const coordinates& end);
            
            //DATA MEMBERS
            
                //allows the user to understand what kind of boat they're using 
                int dimension_;

        private:
            //DATA MEMBERS

                coordinates coord_begin_;
                coordinates coord_end_;
                std::vector<bool> corazza_tracker_;
                int corazza_;
                bool vertical_;
    };
    
    //HELPER FUNCTIONS

        //returns the size of the boat given the coordinates for its begin and end if they are valid, else throws exception
        int boat_size(const coordinates& begin, const coordinates& end);

        //checks if coordinates are compatible with begin and end of a boat
        bool check_coordinates(const coordinates& begin, const coordinates& end);
}

#endif 