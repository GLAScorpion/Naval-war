#include "../../include/elements/corazzata.h"

//FUNCTION MEMBER
    bool game_elements::corazzata::attack(attack_grid& ag, const coordinates& coord){
        boat* boat = ag.get_boat(coord);
        if(!boat) return false;
        boat->hit();
        ag.set_cell(coord,ABSENT); // also need to set map_ in defense_grid
        return true;
    }