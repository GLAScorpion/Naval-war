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
        coordinates(int x = 0, int y = 0): x_{x}, y_{y}{}

    //FUNCTION MEMEBERS
        //return x coordinate
        int get_x() const {return x_;}
        //return y coordinate
        int get_y() const {return y_;}

    private:
    //DATA MEMBERS
        int x_;
        int y_;
};
    //HELPER FUNCTIONS
        //return vertical distance
        int vertical_distance(const coordinates& coord1, const coordinates& coord2);
        //return horizontal distance
        int horizontal_distance(const coordinates& coord1, const coordinates& coord2);
}

#endif 