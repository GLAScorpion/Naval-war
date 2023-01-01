#include "../../include/elements/boat.h"

//CONSTRUCTORS
    game_elements::boat::boat(const coordinates& begin, const coordinates& end){
        if(!check_coordinates(begin, end))
            throw std::logic_error("Invalid boat positions!");
        coord_begin_ = begin;
        coord_end_ = end;
        dimension_ = boat_size(coord_begin_, coord_end_);
        corazza_ = dimension_; 
        vertical_ == ((coord_begin_.get_x() - coord_end_.get_x()) == 0);
    }

//FUNCTION MEMBER
    bool game_elements::boat::is_vertical() const{
        return vertical_;
    }
    void game_elements::boat::restore_corazza(){
        corazza_ = dimension_;
    }
    void game_elements::boat::hit(){
        if(corazza_ < 0)
            throw std::logic_error("The boat does not exist anymore");
        corazza_--;
    }
    void game_elements::boat::move(const game_elements::coordinates& begin){
        coord_begin_ = begin;
            if(vertical_){
                coord_end_.set_x(begin.get_x());    
                coord_end_.set_y(begin.get_y() + dimension_);
            }else{
                coord_end_.set_y(begin.get_y());    
                coord_end_.set_x(begin.get_x() + dimension_);
            }
    }
    bool game_elements::boat::valid_coordinates(const coordinates& coord) const {
        if(vertical_){
            if(coord.get_x() == coord_begin_.get_x()){
                if(vertical_distance(coord,coord_begin_) <= dimension_){
                    return true;
                }
            }
        }else{
            if(coord.get_y() == coord_begin_.get_y()){
                if(horizontal_distance(coord,coord_begin_) <= dimension_){
                    return true;
                }
            }
        }
        return false;
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