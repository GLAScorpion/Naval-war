#include "../../include/elements/corazzata.h"
#include "../../include/elements/attackgrid.h"

//FUNCTION MEMBER
    bool game_elements::corazzata::attack(attack_grid& ag, const coordinates& coord){
        boat* boat = ag.get_boat(coord);
        if(!boat) ag.set_cell(coord,ABSENT);
        boat->hit();
        ag.set_cell(coord,HIT); 
        return true;
    }