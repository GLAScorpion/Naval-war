#include "../../include/elements/boat.h"

//CONSTRUCTORS
    game_elements::boat::boat(const coordinates& begin, const coordinates& end){
        if(!check_coordinates(begin, end))
            throw std::logic_error("Invalid boat positions!");
        coord_begin_ = begin;
        coord_end_ = end;
        dimension_ = boat_size(coord_begin_, coord_end_);
        corazza_ = dimension_; 
    }

//FUNCTION MEMBER
    bool game_elements::boat::is_vertical(){
        return   ((coord_begin_.get_x() - coord_end_.get_x()) == 0);
        return false;
    }

//HELPER FUNCTIONS
    int game_elements::boat_size(const coordinates& coord1, const coordinates& coord2) {
        if(!check_coordinates)
            throw std::logic_error("Invalid boat positions!");
        int dx = horizontal_distance(coord1,coord2);
        int dy = vertical_distance(coord1,coord2);
        return dx+dy;
    }
    bool game_elements::check_coordinates(const coordinates& coord1, const coordinates& coord2){
        int dx = horizontal_distance(coord1,coord2);
        int dy = vertical_distance(coord1,coord2);
        if((dx == 0 || dx == 2 || dx == 4) && dy == 0){
            return true;
        }else if((dy == 0 || dy == 2 || dy == 4) && dx == 0){
            return true;
        }
        return false;
    }