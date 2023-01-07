#include "../../include/elements/supporto.h"
#include "../../include/elements/defensegrid.h"

void game_elements::supporto::move_and_heal(defense_grid& dg, const coordinates& coord){
    std::vector<boat*> boats = dg.boats_in_radius(coord,SUPPORTO_RADIUS);
    for(int i = 0; i < boats.size(); i++){
        (boats[i])->restore_corazza();
    }
}