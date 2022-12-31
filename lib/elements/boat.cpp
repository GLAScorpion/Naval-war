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
        return ((coord_begin_.get_x() - coord_end_.get_x()) == 0);
    }
    void game_elements::boat::restore_corazza(){
        corazza_ = dimension_;
    }
    void game_elements::boat::hit(){
        if(corazza_ < 0)
            throw std::logic_error("The boat does not exist anymore");
        corazza_--;
    }

//HELPER FUNCTIONS
    int game_elements::boat_size(const coordinates& begin, const coordinates& end) {
        if(!check_coordinates)
            throw std::logic_error("Invalid boat positions!");
        int dx = horizontal_distance(begin,end);
        int dy = vertical_distance(begin,end);
        return dx+dy;
    }
    bool game_elements::check_coordinates(const coordinates& begin, const coordinates& end){
        if(begin.get_x() < end.get_x() || begin.get_y() < end.get_y())
            return false;

        int dx = horizontal_distance(begin,end);
        int dy = vertical_distance(begin,end);
        if((dx == 0 || dx == 2 || dx == 4) && dy == 0){
            return true;
        }else if((dy == 0 || dy == 2 || dy == 4) && dx == 0){
            return true;
        }
        return false;
    }