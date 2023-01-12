#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/person.h"
#include "../../include/elements/boats.h"
#include "../../include/elements/utilities.h"

std::string game_elements::person::command_picker(){
    std::string cmd;
    std::string second_half;
    //std::cout<<"Waiting for orders, captain!\n";
    while(true){
        std::cin>>cmd;
        std::cin>>second_half;
        cmd += ' ';
        cmd += second_half;

        if(cmd == CMD_CLEAR_HIT or cmd == CMD_CLEAR_MISS or cmd == CMD_CLEAR_SONAR or cmd == CMD_GRID){
            return cmd;
        }

        if(str_to_coord(cmd)[1].get_x() != -1) return cmd;
        std::cout << "Can't understand the order! Retry\n";
    }
}
bool game_elements::person::command_exec(const std::string& cmd){
    if(cmd == CMD_CLEAR_HIT){
        ag->clear_symbol(HIT);
        return false;
    }
    if(cmd == CMD_CLEAR_MISS){
        ag->clear_symbol(ABSENT);
        return false;
    }
    if(cmd == CMD_CLEAR_SONAR){
        ag->clear_symbol(SONAR);
        return false;
    }
    if(cmd == CMD_GRID){
        switch_grid();
        return false;
    }
    std::vector<coordinates> coord_cmd = str_to_coord(cmd);
    return dg->get_boat(coord_cmd[0])->action(dg,ag,coord_cmd[1]);
}
bool game_elements::person::boat_choice(const coordinates& coord){
    boat* tmp_boat = dg->get_boat(coord);
    if(!(coord == tmp_boat->get_centre())) return false;
    if(tmp_boat->get_corazza() == 0) return false;
    return true;
}