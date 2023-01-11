#include "../../include/elements/utilities.h"

//OPERATORS

    bool game_elements::coordinates::operator==(const coordinates& coord){
        return (x_ == coord.get_x() && y_ == coord.get_y());
    }

    game_elements::coordinates& game_elements::coordinates::operator=(const coordinates& coord){
        x_ = coord.get_x();
        y_ = coord.get_y();
        return *this;
    }

//HELPER FUNCTIONS

    //return vertical distance
    int game_elements::vertical_distance(const coordinates& coord1, const coordinates& coord2){
        int dy = coord1.get_y() - coord2.get_y();
        if(dy > 0) return dy;
        return (dy)*(-1);
    }
    
    //return horizontal distance
    int game_elements::horizontal_distance(const coordinates& coord1, const coordinates& coord2){
        int dx = coord1.get_x() - coord2.get_x();
        if(dx > 0) return dx;
        return (dx)*(-1);
    }