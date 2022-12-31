/*
@author: 


SHORT DEFINITION:
-->An abstract class that describes the basic features of a boat
*/

#ifndef BOAT_H
#define BOAT_H

#include <iostream>

#include <utilities.h>

namespace game_elements{

    class boat{
    public:
    //CONSTRUCTORS
        //deleted copy constructor 
        boat(const boat& b) = delete;
        //deleted no argument constructor (there are none default properties for a boat)
        boat() = delete; 

    //FUNCTION MEMBERS 
        //return the dimension of the boat
        int get_dimension(){return dimension_;}
        //return the value of corazzata
        int get_corazzata(){return corazza_;}
        //return true if the boat is vertical else it returln false 
        bool is_vertical();

    //OPERATORS
        //deleted copy assignment
        boat& operator=(const boat& b) = delete;

    protected:
    //CONSTRUTORS
        //construtor accepting coordinates for begin and end of boat
        boat(const coordinates& begin, const coordinates& end);

    private:
    //DATA MEMBERS
        coordinates coord_begin_;
        coordinates coord_end_;
        int dimension_; //this number allow user of this class to understand what kind of boat they're using 
        int corazza_;
    };
    //HELPER FUNCTIONS
        //return the size of the possible boat given the coordinates for its begin and end
        int boat_size(const coordinates& coord1, const coordinates& coord2);
        //check if coordinates are compatible with begin and end of a boat
        bool check_coordinates(const coordinates& coord1, const coordinates& coord2);
}

#endif 