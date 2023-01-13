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

namespace game_elements{

    class coordinates{
    public:

        //CONSTRUCTORS

            //constructor accepting two integers
            coordinates(int x = 0, int y = 0): x_{x}, y_{y}{}

        //FUNCTION MEMEBERS

            //returns x coordinate
            int get_x() const {return x_;}

            //returns y coordinate
            int get_y() const {return y_;}

            //sets value of x
            void set_x(int x) {x_ = x;}

            //sets value of y
            void set_y(int y) {y_ = y;}

        //OPERATORS

            //equality operator
            bool operator==(const coordinates& coord) const;

            //assignment operator
            coordinates& operator=(const coordinates& coord);

    private:

        //DATA MEMBERS

            int x_;
            int y_;
    };

    //HELPER FUNCTIONS

        //returns vertical distance
        int vertical_distance(const coordinates& coord1, const coordinates& coord2);
        
        //returns horizontal distance
        int horizontal_distance(const coordinates& coord1, const coordinates& coord2);

        //converts to valid a valid string
        std::string coord_to_str(int c);

        //converts to valid a valid string
        char coord_to_char(int c);

        //converts to valid coord
        int char_to_coord(char c);

        //returns array of 2 coord and x = -1 of 2nd coord if invalid
        std::vector<coordinates> str_to_coord(const std::string& str);
}

#endif 