#include "../../include/elements/attackgrid.h"
#include "../../include/elements/defensegrid.h"
#include "../../include/elements/boat.h"
#include "../../include/elements/corazzata.h"
#include "../../include/elements/supporto.h"
#include "../../include/elements/esplorazione.h"
#include "../../include/elements/utilities.h"
#include <iostream>

//CONSTRUCTORS
    game_elements::attack_grid::attack_grid(defense_grid* dg){
        if(dg) {
            others_grid_ = dg;
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLUMNS; j++){
                    map_[i][j] = VOID;
                }
            }
        }else{
            throw std::invalid_argument("Argument of constructor cannot be a nullptr!");
        }
    }

//FUNCTION MEMBERS
    void game_elements::attack_grid::set_cell(const coordinates& coord, char boat_symbol){
        if(boat_symbol != VOID && boat_symbol != HIT && boat_symbol != ABSENT){
            throw std::invalid_argument("The symobol is not valid for this grid!");
        }
        if(!check_coordinates(coord)){
            throw std::invalid_argument("The coordinates are not valid fir this grid");
        }
        map_[coord.get_y()][coord.get_x()] = boat_symbol;
    }
    std::vector<game_elements::boat*> game_elements::attack_grid::boats_in_radius(const coordinates& coord, int radius) {
        int begin_x = (coord.get_x() - radius);
        int begin_y = (coord.get_y() - radius);
        int end_x = (coord.get_x() + radius);
        int end_y = (coord.get_y() + radius);
        if(begin_x < 0){
            begin_x = 0;
        }
        if(begin_y < 0){
            begin_y = 0;
        }
        if(end_x > ROWS){
            end_x = ROWS -1;
        }
        if(end_y > COLUMNS){
            end_y = COLUMNS - 1;
        }
        game_elements::coordinates tmp (begin_x,begin_y);
        char symbol;
        for(int i = begin_y; i < end_y; i++){
            for(int j = begin_x; j < end_x; j++){
                symbol = others_grid_->get_cell(tmp);
                if(symbol != VOID){
                    symbol = HIT;
                }else{
                    symbol = ABSENT;
                }
                set_cell(tmp,symbol);
                tmp.set_x(tmp.get_x()+1);
            }
            tmp.set_y(tmp.get_y()+1);
            tmp.set_x(begin_x);
        }
        return others_grid_->boats_in_radius(coord,radius);
    }
    game_elements::boat* game_elements::attack_grid::get_boat(const coordinates& coord) const{  
        return (others_grid_->get_boat(coord));
    }
    bool game_elements::attack_grid::check_coordinates(const coordinates& coord) const{
        if(coord.get_x() >= COLUMNS || coord.get_x() < 0 || coord.get_y() >= ROWS || coord.get_y() < 0){
            return false;
        }
        return true;
    }
    std::ostream& game_elements::attack_grid::write(std::ostream& os) const{
        os << "##############";
        os <<'\n';
        for(int i = 0; i < COLUMNS; i++){
            os << "#";
            for(int j = 0; j < ROWS; j++){
                os << map_[i][j];
            }
            os << "#";
            os <<'\n';
        }
        os << "##############";
        return os;
    }
    char game_elements::attack_grid::get_cell(const coordinates& coord){
        check_coordinates(coord);
        return map_[coord.get_y()][coord.get_x()];
    }
    
    std::vector<game_elements::boat*> game_elements::attack_grid::get_boats() const{
        return others_grid_->get_boats();
    }

//OPERATORS

    std::ostream& game_elements::operator<<(std::ostream& os, const game_elements::attack_grid& ag){
        return ag.write(os);
    }