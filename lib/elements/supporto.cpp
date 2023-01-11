#include "../../include/elements/supporto.h"
#include "../../include/elements/defensegrid.h"
#include "../../include/elements/attackgrid.h"

//FUNCTION MEMBER 
    bool game_elements::supporto::action(defense_grid* dg, attack_grid* ag, const coordinates& coord){

        if(!dg->check_move(this, coord)) return false;

        set_coordinates(coord);
        std::vector<boat*> boats = dg->boats_in_radius(coord,SUPPORTO_RADIUS);
        for(int i = 0; i < boats.size(); i++){
            (boats[i])->restore_corazza();
        }
        return true;
    }
