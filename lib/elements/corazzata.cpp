#include "../../include/elements/corazzata.h"
#include "../../include/elements/attackgrid.h"
#include "../../include/elements/defensegrid.h"

//FUNCTION MEMBER
    bool game_elements::corazzata::action(grid* g, const coordinates& coord){
        game_elements::attack_grid* ag = dynamic_cast<game_elements::attack_grid*> (g);
        if(!ag){
            return false;
        }
        boat* boat = ag->get_boat(coord);
        if(boat == nullptr) {
            ag->set_cell(coord,ABSENT);
            return false;
        }
        boat->hit();
        ag->set_cell(coord,HIT); 
        return true;
    }
