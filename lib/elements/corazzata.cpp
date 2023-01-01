#include "../../include/elements/corazzata.h"

//FUNCTION MEMBER
    bool game_elements::corazzata::attack(attack_grid& ag, const coordinates& coord){
        boat* boat = ag.get_boat(coord);
        if(!boat) ag.set_cell(coord,ABSENT);
        boat->hit();
        ag.set_cell(coord,HIT); // also need to set map_ in defense_grid
        return true;
    }