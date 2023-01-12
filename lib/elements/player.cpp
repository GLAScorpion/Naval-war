#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/boats.h"
void game_elements::player::link(player* other){
    ag = new attack_grid(other->dg);
    other->ag = new attack_grid(dg);
}

bool game_elements::player::has_lost(){
    std::vector<boat*> boat_ar = dg->get_boats();
    for(int i = 0; i < boat_ar.size(); i++){
        if(boat_ar[i]->get_corazza() != 0) return false;
    }
    return true;
}

bool game_elements::player::place_boat(boat* b){
    coordinates coord = b->get_begin();
    return dg->move(b,coord);
}

const std::string game_elements::player::print() const{
    if(print_dg_) return dg->write();
    return ag->write();
}