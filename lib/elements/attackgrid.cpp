#include "../../include/elements/attackgrid.h"
#include "../../include/elements/defensegrid.h"
#include "../../include/elements/boat.h"
#include "../../include/elements/corazzata.h"
#include "../../include/elements/supporto.h"
#include "../../include/elements/esplorazione.h"
#include "../../include/elements/utilities.h"
#include <algorithm>
#include <vector>
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
        if(!check_coordinates(coord)){
            throw std::invalid_argument("The coordinates are not valid fir this grid");
        }
        map_[coord.get_y()][coord.get_x()] = boat_symbol;
    }

    std::vector<game_elements::boat*> game_elements::attack_grid::boats_in_radius(const coordinates& coord, int radius) {
        boat* temp=nullptr;
        coordinates coord_temp;
        int i=coord.get_y()-radius;
        int j=coord.get_x()-radius;
        if(i<0) i=0;
        if(j<0) j=0;

        for(; i<coord.get_y()+radius && i<ROWS; i++){
            for(; j<coord.get_x()+radius && j<COLUMNS; j++){
                coord_temp = coordinates(i,j);
                temp= get_boat(coord_temp);
                if(temp){
                    if(temp->is_broken(coord_temp)){
                        map_[i][j]=HIT;
                    }else{
                        map_[i][j]=SONAR;
                    }
                }else{
                    map_[i][j]=ABSENT;
                }
            }
        }
            
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

    const std::string game_elements::attack_grid::write() const {
        std::string os;
        os += "  +--+--+--+--+--+--+--+--+--+--+--+--+\n";
        for(int i = 0; i < ROWS; i++){
            os +=coord_to_char(i + 1) + " ";
            for(int j = 0; j < COLUMNS; j++){
                os += "|" + map_[i][j] + map_[i][j];
            }
            os += "|\n";
            os += "--+--+--+--+--+--+--+--+--+--+--+--+--+\n";
        }
        os += "  |";
        for(int j = 0; j < COLUMNS; j++){
            if(j/10 != 1) os += " ";
            os += j + 1 + "|";
        }
        os+="\n";
        return os;
    }
    
    char game_elements::attack_grid::get_cell(const coordinates& coord){
        check_coordinates(coord);
        return map_[coord.get_y()][coord.get_x()];
    }
    
    std::vector<game_elements::boat*> game_elements::attack_grid::get_boats() const{
        return others_grid_->get_boats();
    }

    void game_elements::attack_grid::clear_symbol(char symbol){
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                if(map_[i][j] == symbol) map_[i][j] = VOID;
            }
        }
    }

//OPERATORS

    std::ostream& game_elements::operator<<(std::ostream& os, const game_elements::attack_grid& ag){
        return os << ag.write();
    }