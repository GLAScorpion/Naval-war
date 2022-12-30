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
        int get_dimension(){return dimension_;}
        int get_corazzata(){return corazza_;}

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

}

#endif 