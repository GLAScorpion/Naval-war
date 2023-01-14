/*
@author:
*/

#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/boats.h"

//MEMBER FUNCTIONS

    void game_elements::player::link(player* other){
        ag = new attack_grid(other->dg);
        other->ag = new attack_grid(dg);
    }

    bool game_elements::player::command_exec(const std::string& cmd){
        std::vector<coordinates> coord_cmd = str_to_coord(cmd);
        boat* tmp = dg->get_boat(coord_cmd[0]);
        if(!(coord_cmd[0] == tmp->get_centre())) return false;
        return tmp->action(dg,ag,coord_cmd[1]);
    }

    bool game_elements::player::place_boat(boat* b){
        coordinates coord = b->get_begin();
        bool res = false;
        try{
            res = dg->move(b,coord);
            if(res) dg->push_boat(b);
        }
        catch(std::logic_error& e){}
        return res;
    }

    const std::string game_elements::player::print_grid() const{
        if(print_dg_) return dg->write();
        return ag->write();
    }