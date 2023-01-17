/*
@author: ALBERTO PASINATO
*/

#include "../include/corazzata.h"

//MEMBER FUNCTIONS

    bool game_elements::corazzata::action(defense_grid* dg, attack_grid* ag, const coordinates& coord){

        if(coord.get_x()<0 || coord.get_y()<0 || coord.get_x()>11 || coord.get_y()>11) return false;
        boat* boat = ag->get_boat(coord);
        if(boat == nullptr) {
            ag->set_cell(coord,kAbsent);
            return true;
        }
        boat->got_hit(coord);
        ag->get_other_grid()->set_cell(coord, tolower(boat->get_symbol()));
        ag->set_cell(coord,kHit); 
        if(boat->get_corazza()==0)ag->del_boat(boat);
        return true;
    }
