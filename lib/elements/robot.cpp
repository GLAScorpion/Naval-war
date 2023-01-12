#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/robot.h"
#include "../../include/elements/boats.h"
#include "../../include/elements/utilities.h"
#include <random>

std::string game_elements::robot::command_picker(){
    std::string res;
    std::random_device rand;
    std::uniform_int_distribution<int> coord_dist(0,COLUMNS-1);
    std::vector<boat*> tmp_boat = dg->get_boats();
    if(tmp_boat.size() == 8){
        std::uniform_int_distribution<int> boat_dist(0,BOAT_NUMBER-1);
        coordinates tmp_coord = tmp_boat[boat_dist(rand)]->get_centre();
        res+= coord_to_char(tmp_coord.get_y()); 
        res+= coord_to_str(tmp_coord.get_x()); 
        res+= ' ' ; 
        res+= coord_to_char(coord_dist(rand)); 
        res+= coord_to_str(coord_dist(rand));
    }else{
        std::uniform_int_distribution<int> vert(0,1);
        int size = ESPLORAZIONE_SIZE;
        int x = coord_dist(rand);
        int y = coord_dist(rand);
        res += coord_to_char(y);
        res += coord_to_str(x);
        res += ' ';
        if(tmp_boat.size() <= 2) size = CORAZZATA_SIZE;
        else if(tmp_boat.size() <=5) size = SUPPORTO_SIZE;
        if(vert(rand)){
            res += coord_to_char(y + size - 1);
            res += coord_to_str(x);
        }else{
            res += coord_to_char(y);
            res += coord_to_str(x + size - 1);
        }
    }
    return res;
}

bool game_elements::robot::command_exec(const std::string& cmd){
    std::vector<coordinates> coord_cmd = str_to_coord(cmd);
    return dg->get_boat(coord_cmd[0])->action(dg,ag,coord_cmd[1]);
}

bool game_elements::robot::boat_choice(const coordinates& coord){
    if(dg->get_boat(coord)->get_corazza() == 0) return false;
    return true;
}