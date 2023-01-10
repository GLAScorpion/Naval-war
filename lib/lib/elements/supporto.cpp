#include "../../include/elements/supporto.h"
#include "../../include/elements/defensegrid.h"
#include "../../include/elements/attackgrid.h"

//FUNCTION MEMBER 
    bool game_elements::supporto::action(grid* g, const coordinates& coord){
        game_elements::defense_grid* dg = dynamic_cast<game_elements::defense_grid*> (g);
        if(!dg){
            return false;
        }
        set_coordinates(coord);
        std::vector<boat*> boats = dg->boats_in_radius(coord,SUPPORTO_RADIUS);
        for(int i = 0; i < boats.size(); i++){
            (boats[i])->restore_corazza();
        }
        return true;
    }
