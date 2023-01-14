/*
@author:
*/

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

    game_elements::defense_grid::defense_grid(){
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                map_[i][j] = VOID;
            }
        }

    }

//MEMBER FUNCTIONS

    bool game_elements::defense_grid::move(boat* b, const coordinates& coord){
        //controls if the moves is possible
        if(!check_move(b,coord)){
            return false;
        }
        int size = b->get_dimension();
        int tmp_x = b->get_begin().get_x();
        int tmp_y = b->get_begin().get_y();
        
        b->set_coordinates(coord);

        int x_offset = coord.get_x() - tmp_x;
        int y_offset = coord.get_y() - tmp_y;
        std::vector<bool> tracker=b->get_tracker();

        for(int i = 0; i < size; i++){
            map_[tmp_y][tmp_x] = VOID;
            if(tracker[i]){
                map_[tmp_y + y_offset][tmp_x + x_offset] = b->get_symbol();
            }else{
                map_[tmp_y + y_offset][tmp_x + x_offset] = tolower(b->get_symbol());
            }

            if(b->is_vertical()){
                tmp_y++;
            }else{
                tmp_x++;
            }
        }
        return true;

    }

    //this function will be used only by supporto boat
    std::vector<game_elements::boat*> game_elements::defense_grid::boats_in_radius(const coordinates& coord, int radius) {
        std::vector<game_elements::boat*> in_range_boats;
        boat* temp=nullptr;
        int i=coord.get_y()-radius;
        int j=coord.get_x()-radius;
        if(i<0) i=0;
        if(j<0) j=0;

        for(;  i<=coord.get_y()+radius && i<ROWS; i++){
            for(; j<=coord.get_x()+radius && j<COLUMNS; j++){
                temp= get_boat(coordinates(i,j));
                if(temp && find(in_range_boats.begin(), in_range_boats.end(), temp)==in_range_boats.end()){
                    in_range_boats.push_back(temp);
                }
            }
        }
            
        return in_range_boats;        
    } 

    game_elements::boat* game_elements::defense_grid::get_boat(const coordinates& coord) const{
        for(int i = 0; i < boats_.size(); i++){
            if(boats_[i]->valid_coordinates(coord)){
                return boats_[i];
            }
        }
        return nullptr;
    }

    bool game_elements::defense_grid::check_coordinates(const coordinates& coord) const{
        if(coord.get_x() >= COLUMNS || coord.get_x() < 0 || coord.get_y() >= ROWS || coord.get_y() < 0){
            return false;
        }
        return true;
    }

    const std::string game_elements::defense_grid::write() const {
        std::string os;
        os += "   +---+---+---+---+---+---+---+---+---+---+---+---+\n";
        for(int i = 0; i < ROWS; i++){
            os += ' ';
            os += coord_to_char(i) ;
            os+= " ";
            for(int j = 0; j < COLUMNS; j++){
                os += "| ";
                os += map_[i][j];
                os += " ";
            }
            os += "|\n";
            os += "---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
        }
        os += "   |";
        for(int j = 0; j < COLUMNS; j++){
            os += ' ';
            if((j+1)/10 != 1) {
                os += '0' + (j + 1)%10;
                os += " ";
            }else{
                os += '1';
                os += '0' + (j + 1)%10;
                }
            os += "|";
        }
        os+="\n";
        return os;
    }

    void game_elements::defense_grid::set_cell(const coordinates& coord, char boat_symbol){
        if(!check_coordinates(coord)){
            throw std::invalid_argument("The coordinates are not valid fir this grid");
        }
        map_[coord.get_y()][coord.get_x()] = boat_symbol;
    }

    char game_elements::defense_grid::get_cell(const game_elements::coordinates& coord){
        if(!check_coordinates(coord)){
            throw std::invalid_argument("Coordinates does not match the grid!");
        }
        return map_[coord.get_y()][coord.get_x()];
    }

    bool game_elements::defense_grid::check_move(boat* b, const coordinates& begin){
        int size = b->get_dimension();
        int tmp_x = begin.get_x();
        int tmp_y = begin.get_y();
        for(int i = 0; i < size; i++){
            if(map_[tmp_y][tmp_x] != VOID){
                return false;
            }
            if(b->is_vertical()){
                if(tmp_y>=ROWS) return false;
                tmp_y++;
            }else{
                if(tmp_x>=COLUMNS) return false;
                tmp_x++;
            }
        }
        return true;
    }

    std::vector<game_elements::boat*> game_elements::defense_grid::get_boats() const{
        return boats_;
    }

    void game_elements::defense_grid::del_boat(boat* b){
        int size = b->get_dimension();
        int tmp_x = b->get_begin().get_x();
        int tmp_y = b->get_begin().get_y();
        for(int i = 0; i < size; i++){
            map_[tmp_y][tmp_x] = VOID;
            if(b->is_vertical()){
                tmp_y++;
            }else{
                tmp_x++;
            }
        }
        std::vector<boat*> tmp;
        for(int i = 0; i < boats_.size();i++){
            if(!(boats_[i]->get_centre() == b->get_centre())) tmp.push_back(boats_[i]);
        }
        boats_ = tmp;
        delete b;
    }

//OPERATORS

    std::ostream& game_elements::operator<<(std::ostream& os, const defense_grid& dg ){
        return os << dg.write();
    }