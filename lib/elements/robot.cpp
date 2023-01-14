/*
@author:
*/

#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/robot.h"
#include "../../include/elements/boats.h"
#include "../../include/elements/utilities.h"
#include <random>

//MEMBER FUNCTIONS

    std::string game_elements::robot::command_picker(){
        std::string res;
        std::random_device rand;
        std::uniform_int_distribution<int> coord_dist(0,COLUMNS-1);
        std::vector<boat*> tmp_boat = dg->get_boats();   
        std::uniform_int_distribution<int> boat_dist(0,tmp_boat.size()-1);
        coordinates tmp_coord = tmp_boat[boat_dist(rand)]->get_centre();
        //std::cout<<tmp_coord.get_y()<<" "<<tmp_coord.get_x()<<std::endl;
        res+= coord_to_char(tmp_coord.get_y()); 
        res+= coord_to_str(tmp_coord.get_x()); 
        res+= ' ' ; 
        res+= coord_to_char(coord_dist(rand)); 
        res+= coord_to_str(coord_dist(rand));   
        return res;
    }

    bool game_elements::robot::boat_choice(const coordinates& coord){
        if(dg->get_boat(coord)->get_corazza() == 0) return false;
        return true;
    }

    std::string game_elements::robot::coord_picker(){
        std::string res;
        std::random_device rand;
        std::uniform_int_distribution<int> coord_dist(0,COLUMNS-1);
        std::vector<boat*> tmp_boat = dg->get_boats();
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
        return res;
    }