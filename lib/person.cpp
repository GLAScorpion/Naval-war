/*
@author: PIERPAOLO COLELLA
*/

#include "../include/person.h"
#include "../include/boats.h"

//MEMBER FUNCTIONS

    std::string game_elements::person::command_picker() const{
        std::string cmd;
        std::string second_half;
        while(true){
            std::cin>>cmd;
            std::cin>>second_half;
            cmd += ' ';
            cmd += second_half;
            if(cmd == kCmdClearHit or cmd == kCmdClearMiss or cmd == kCmdClearSonar or cmd == kCmdGrid){
                return cmd;
            }
            if(str_to_coord(cmd)[1].get_x() != -1) return cmd;
            std::cout << "Can't understand the order! Retry\n";
        }
    }

    bool game_elements::person::boat_choice(const coordinates& coord) const{
        boat* tmp_boat = dg->get_boat(coord);
        if(!(coord == tmp_boat->get_centre())) return false;
        if(tmp_boat->get_corazza() == 0) return false;
        return true;
    }

    std::string game_elements::person::coord_picker() const{
        std::string cmd;
        std::string second_half;
        while(true){
            std::cin>>cmd;
            std::cin>>second_half;
            cmd += ' ';
            cmd += second_half;
            if(str_to_coord(cmd)[1].get_x() != -1) return cmd;
            std::cout << "Can't understand the order! Retry\n";
        }
    }

    bool game_elements::person::exec_special(const std::string& cmd){
        if(cmd == kCmdClearHit){
            ag->clear_symbol(kHit);
            return true;
        }
        if(cmd == kCmdClearMiss){
            ag->clear_symbol(kAbsent);
            return true;
        }
        if(cmd == kCmdClearSonar){
            ag->clear_symbol(kSonar);
            return true;
        }
        if(cmd == kCmdGrid){
            switch_grid();
            return true;
        }
        return false;
    }