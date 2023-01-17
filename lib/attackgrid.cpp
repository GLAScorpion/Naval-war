/*
@author: MATTIA SCANTAMBURLO
*/

#include "../include/attackgrid.h"
#include "../include/boat.h"

//CONSTRUCTORS

    game_elements::attack_grid::attack_grid(defense_grid* dg){
        if(dg) {
            others_grid_ = dg;
            for(int i = 0; i < kRows; i++){
                for(int j = 0; j < kColumns; j++){
                    map_[i][j] = kVoid;
                }
            }
        }else{
            throw std::invalid_argument("Argument of constructor cannot be a nullptr!");
        }
    }

//MEMBER FUNCTIONS

    std::vector<game_elements::boat*> game_elements::attack_grid::boats_in_radius(const coordinates& coord, int radius) {
        std::vector<game_elements::boat*> res;
        boat* temp=nullptr;
        coordinates coord_temp;
        int i=coord.get_y()-radius;
        if(i<0) i=0;

        for(; i<=coord.get_y()+radius && i<kRows; i++){
            int j=coord.get_x()-radius;
            if(j<0) j=0;
            for(; j<=coord.get_x()+radius && j<kColumns; j++){
                coord_temp = coordinates(j,i);
                temp= get_boat(coord_temp);
                if(temp){
                    if(temp->is_broken(coord_temp)){
                        map_[i][j]=kHit;
                    }else{
                        map_[i][j]=kSonar;
                    }
                }else{
                    map_[i][j]=kAbsent;
                }
            }
        }
        return res;  
    }

    game_elements::boat* game_elements::attack_grid::get_boat(const coordinates& coord){  
        return (others_grid_->get_boat(coord));
    }

    void game_elements::attack_grid::set_cell(const coordinates& coord, char boat_symbol){
        if(!check_coordinates(coord)){
            throw std::invalid_argument("The coordinates are not valid for this grid");
        }
        map_[coord.get_y()][coord.get_x()] = boat_symbol;
    }

    char game_elements::attack_grid::get_cell(const coordinates& coord) const{
        if(!check_coordinates(coord)){
            throw std::invalid_argument("The coordinates are not valid for this grid");
        }
        return map_[coord.get_y()][coord.get_x()];
    }
    
    bool game_elements::attack_grid::check_coordinates(const coordinates& coord) const{
        if(coord.get_x() >= kColumns || coord.get_x() < 0 || coord.get_y() >= kRows || coord.get_y() < 0){
            return false;
        }
        return true;
    }

    const std::string game_elements::attack_grid::write() const {
        std::string str;
        str += "   +---+---+---+---+---+---+---+---+---+---+---+---+\n";
        for(int i = 0; i < kRows; i++){
            str += ' ';
            str += coord_to_char(i) ;
            str += " ";
            for(int j = 0; j < kColumns; j++){
                str += "| ";
                str += map_[i][j];
                str += " ";
            }
            str += "|\n";
            str += "---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
        }
        str += "   |";
        for(int j = 0; j < kColumns; j++){
            str += ' ';
            if((j+1)/10 != 1) {
                str += '0' + (j + 1)%10;
                str += " ";
            }else{
                str += '1';
                str += '0' + (j + 1)%10;
                }
            str += "|";
        }
        str +="\n";
        return str;
    }
    
    std::vector<game_elements::boat*> game_elements::attack_grid::get_boats(){
        return others_grid_->get_boats();
    }

    void game_elements::attack_grid::clear_symbol(char symbol){
        for(int i = 0; i < kRows; i++){
            for(int j = 0; j < kColumns; j++){
                if(map_[i][j] == symbol) map_[i][j] = kVoid;
            }
        }
    }

//OPERATORS

    std::ostream& game_elements::operator<<(std::ostream& os, const game_elements::attack_grid& ag){
        return os << ag.write();
    }