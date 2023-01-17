/*
@author: ALBERTO PASINATO
*/

#include "../include/player.h"
#include "../include/boats.h"

constexpr int kGridWidth = 52;
constexpr int kGridHeight = 26;
constexpr int kGridSpacing = 6;
//MEMBER FUNCTIONS

    void game_elements::player::link(player* other){
        ag = new attack_grid(other->dg);
        other->ag = new attack_grid(dg);
    }

    bool game_elements::player::command_exec(const std::string& cmd){
        std::vector<coordinates> coord_cmd = str_to_coord(cmd);
        if(coord_cmd[1].get_x() == -1) return false;
        
        boat* tmp = dg->get_boat(coord_cmd[0]);
        if(!tmp) return false;
        
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
        std::string tmp1 = dg->write();
        std::string tmp2 = ag->write();
        std::string out = "";
        if(print_grid_){
            out += "DEFENSE GRID";
            if(print_attackgrid_) out +="                                              ATTACK GRID\n";
            else out += "\n";
            for(int i = 0; i < kGridHeight;i++){
                for(int j = 0; j < kGridWidth; j++){
                    out += tmp1[i + j + i*kGridWidth];
                }
                if(print_attackgrid_){
                    for(int j = 0; j < kGridSpacing; j++){
                        out += " ";
                    }
                    for(int j = 0; j < kGridWidth; j++){
                        out += tmp2[i + j + i*kGridWidth];
                    }
                }
                out += "\n";
            }
        }   
        return out;
    }