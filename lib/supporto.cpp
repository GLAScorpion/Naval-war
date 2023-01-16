/*
@author: ALBERTO PASINATO
*/

#include "../include/supporto.h"
#include "../include/defensegrid.h"
#include "../include/attackgrid.h"

//MEMBER FUNCTIONS

    bool game_elements::supporto::action(defense_grid* dg, attack_grid* ag, const coordinates& coord){

        if(!dg->move(this, coord)) return false;

        std::vector<boat*> boats = dg->boats_in_radius(coord,SUPPORTO_RADIUS);
        coordinates temp;
        std::cout << boats.size();
        //checks every cell in range and heals every boat in it, except itself
        for(int i = 0; i < boats.size(); i++){
            if(this!=boats[i]){
                boats[i]->restore_corazza();
                temp = boats[i]->get_begin();
                for(int j=0; j<boats[i]->get_dimension(); j++){
                    if(boats[i]->is_vertical()){
                        dg->set_cell(temp , boats[i]->get_symbol());
                        temp.set_y(temp.get_y()+1);
                    }else{
                        dg->set_cell(temp , boats[i]->get_symbol());
                        temp.set_x(temp.get_x()+1);
                    } 
                }
            }
        }
        
        return true;
    }
