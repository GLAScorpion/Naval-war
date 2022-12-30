#include "../../include/elements/utilities.h"

int game_elements::boat_size(const coordinates& coord1, const coordinates& coord2) {
    int dx = coord1.get_x() - coord2.get_x();
    int dy = coord1.get_y() - coord2.get_y();
    if((dx == 0 || dx == 2 || dx == 4) && dy == 0){
        return dx + 1;
    }else if((dy == 0 || dy == 2 || dy == 4) && dx == 0){
        return dy + 1;
    }
    throw std::logic_error("Invalid boat positions!");
    
}