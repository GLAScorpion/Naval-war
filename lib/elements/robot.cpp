#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/robot.h"
#include "../../include/elements/boats.h"
#include "../../include/elements/utilities.h"
#include <random>

std::string game_elements::robot::command_picker(){
    std::string res;
    std::random_device rand;
    std::uniform_int_distribution<int> boat_dist(0,BOAT_NUMBER-1);
    std::uniform_int_distribution<int> coord_dist_x(0,COLUMNS-1);
    std::vector<boat*> tmp_boat = dg->get_boats();
    coordinates tmp_coord = tmp_boat[boat_dist(rand)]->get_centre();
    res+= coord_to_char(tmp_coord.get_y()) + tmp_coord.get_x() + " " ; 
    res+= coord_to_char(coord_dist_x(rand)) + coord_dist_x(rand);
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