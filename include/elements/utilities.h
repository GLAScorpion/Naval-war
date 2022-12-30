/*
@author

SHORT DEFINITION:
    header conataining the declaration of elements that represent simple concepts of the game 
    (example: coordinates)
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>

//#include "" 

namespace game_elements{

class coordinates{
    public:
    //CONSTRUCTORS
        //constructor accepting two integers
        coordinates(int x, int y): x_{x}, y_{y}{}
        //return x coordinate
        int get_x() const {return x_;}
        //return y coordinate
        int get_y() const {return y_;}
    private:
        int x_;
        int y_;
};
    //return distance from 2 boats
    int boat_size(const coordinates& coord1, const coordinates& coord2);
}

#endif 