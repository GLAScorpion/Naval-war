#include "../../include/elements/esplorazione.h"
#include "../../include/elements/attackgrid.h"
#include "../../include/elements/defensegrid.h"

bool game_elements::esplorazione::action(defense_grid* dg, attack_grid* ag, const coordinates& coord){
    
    if(!dg->move(this, coord)) return false;

    std::vector<boat*> boats = ag->boats_in_radius(coord, ESPLORAZIONE_RADIUS); 
    return true;
}