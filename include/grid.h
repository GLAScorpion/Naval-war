/*
@author: MATTIA SCANTAMBURLO

SHORT DEFINITION:
--> This abstract class describes the general behavior of a grid 
*/
#ifndef GRID_H
#define GRID_H

#include "../include/utilities.h"

namespace game_elements{
    
    constexpr int kColumns = 12;
    constexpr int kRows = 12; 
    constexpr int kBoatNumber = 8;
    constexpr char kVoid = ' ';

    class boat;
    class grid{
        public:
            //PUBLIC CONSTRUCTORS

                //deletes copy constructor
                grid(const grid& g) = delete;
                        
            //MEMBER FUNCTIONS

                //returns a vector with all the boat pointers that have a distance from the given coordinates smaller than radius 
                virtual std::vector<boat*> boats_in_radius(const coordinates& c, int radius) = 0;

                //returns boat pointer to allow operations on the boat 
                virtual boat* get_boat(const coordinates& c) = 0;
                virtual std::vector<boat*> get_boats() = 0;

                //deletes boat
                virtual void del_boat(boat* b) = 0;

            //OPERATORS

                //deleted copy assignment operator
                grid& operator=(const grid& g) = delete;  
                
        protected:
            //PROTECTED CONSTRUCTORS
            
                //no arguments constructor
                grid() {};

    };

}
#endif 