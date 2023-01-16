/*
@author: ALBERTO PASINATO
*/

#include "../include/boat.h"

//CONSTRUCTORS

    game_elements::boat::boat(const coordinates& begin, const coordinates& end){
        if(!check_coordinates(begin, end))
            throw std::logic_error("Invalid boat positions!");

        vertical_ = ((begin.get_x() - end.get_x()) == 0);

        //set the smaller coordinate as the begin, the bigger one as the end
        if(vertical_){
            if(begin.get_y()<end.get_y()){
                coord_begin_ = begin;
                coord_end_ = end;
            }else{
                coord_begin_ = end;
                coord_end_ = begin;
            }
        }else{
            if(begin.get_x()<end.get_x()){
                coord_begin_ = begin;
                coord_end_ = end;
            }else{
                coord_begin_ = end;
                coord_end_ = begin;
            }
        }
        
        dimension_ = boat_size(coord_begin_, coord_end_);
        corazza_ = dimension_;
        for(int i=0; i<dimension_;i++){
            corazza_tracker_.push_back(true);
        } 
    }

//MEMBER FUNCTIONS

    const game_elements::coordinates game_elements::boat::get_centre() const{
        game_elements::coordinates temp(0,0);
        if(is_vertical()){
            temp.set_x(get_begin().get_x());
            temp.set_y((get_begin().get_y()+get_end().get_y())/2);
        }else{
            temp.set_y(get_begin().get_y());
            temp.set_x((get_begin().get_x()+get_end().get_x())/2);
        }
        return temp;
    }

    bool game_elements::boat::is_vertical() const{
        return vertical_;
    }

    void game_elements::boat::restore_corazza(){
        corazza_ = dimension_;
        for(int i=0; i<corazza_tracker_.size();i++){
            corazza_tracker_[i]=true;
        }
    }

    bool game_elements::boat::is_broken(const coordinates& coord) const{
        if(is_vertical()){
            int temp = coord.get_y() - coord_begin_.get_y();
            return !corazza_tracker_[temp];
        }
        int temp = coord.get_x() - coord_begin_.get_x();
        return !corazza_tracker_[temp];
    }

    void game_elements::boat::got_hit(const coordinates& coord){
        if(corazza_ <= 0)
            throw std::logic_error("The boat has already sunk.");

        if(is_vertical()){
            int temp = coord.get_y() - coord_begin_.get_y();
            if(corazza_tracker_[temp]){
                corazza_tracker_[temp]=false;
                
                corazza_--;
            }
        }else{
            int temp = coord.get_x() - coord_begin_.get_x();
            if(corazza_tracker_[temp]){
                corazza_tracker_[temp]=false;
                corazza_--;
            }
        }
    }

    bool game_elements::boat::set_coordinates(const game_elements::coordinates& begin){
        coord_begin_ = begin;
        if(vertical_){
            coord_end_.set_x(begin.get_x());    
            coord_end_.set_y(begin.get_y() + dimension_ - 1);
        }else{
            coord_end_.set_y(begin.get_y());    
            coord_end_.set_x(begin.get_x() + dimension_ - 1);
        }
        return true;
    }

    bool game_elements::boat::valid_coordinates(const coordinates& coord) const {
        if(vertical_){
            if(coord.get_x() == coord_begin_.get_x()){
                if(coord.get_y()>=coord_begin_.get_y() && coord.get_y()<=coord_end_.get_y()){
                    return true;
                }
            }
        }else{
            if(coord.get_y() == coord_begin_.get_y()){
                if(coord.get_x()>=coord_begin_.get_x() && coord.get_x()<=coord_end_.get_x()){
                    return true;
                }
            }
        }   
        return false;
    }   

//HELPER FUNCTIONS

    int game_elements::boat_size(const coordinates& begin, const coordinates& end) {
        if(!check_coordinates(begin,end)){
            throw std::logic_error("Invalid boat positions!");
        }
        int dx = horizontal_distance(begin,end);
        int dy = vertical_distance(begin,end);
        return dx+dy+1;
    }

    bool game_elements::check_coordinates(const coordinates& begin, const coordinates& end){

        int dx = horizontal_distance(begin,end);
        int dy = vertical_distance(begin,end);
        if((dx == 0 || dx == 2 || dx == 4) && dy == 0){
            return true;
        }else if((dy == 0 || dy == 2 || dy == 4) && dx == 0){
            return true;
        }
        return false;
    }