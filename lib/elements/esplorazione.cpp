#include "../../include/elements/esplorazione.h"
#include "../../include/elements/attackgrid.h"
#include "../../include/elements/defensegrid.h"

bool game_elements::esplorazione::action(grid* g, const coordinates& coord){
    game_elements::attack_grid* ag = dynamic_cast<game_elements::attack_grid*> (g);
    if(!ag){
        return false;
    }
    set_coordinates(coord);
    std::vector<boat*> boats = ag->boats_in_radius(coord, ESPLORAZIONE_RADIUS); 
    return true;
}