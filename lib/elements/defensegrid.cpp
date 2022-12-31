#include "../../include/elements/defensegrid.h"

//CONSTRUCTORS
    game_elements::defense_grid::defense_grid(const std::vector<coordinates>& coords){
        if(coords.size() != 16)
            throw std::invalid_argument("The number of boats for a defense grid is 8!");

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                map_[i][j] = ' ';
            }
        }

        int size = 0;
        int tmp_x = 0;
        int tmp_y = 0;
        char boat_symbol;
        for(int i = 0; i < coords.size() ; i+=2){
            check_coordinates(coords[i]); // check begin 
            check_coordinates(coords[i+1]); // check end
            tmp_x = coords[i].get_y();
            tmp_y = coords[i].get_y();

            int size = boat_size(coords[i], coords[i+1]);
            if(size == ESPLORAZIONE_SIZE){
                boats_[i/2] = new esplorazione(coords[i],coords[i+1]);
                boat_symbol = ESPLORAZIONE;
            }else if(size == SUPPORTO_SIZE){
                boats_[i/2] = new supporto(coords[i],coords[i+1]);
                boat_symbol = SUPPORTO;
            }else{
                boats_[i/2] = new corazzata(coords[i],coords[i+1]);
                boat_symbol = CORAZZATA;
            }
            
            for(int k = 0; k < size; i++){
                map_[tmp_y][tmp_x] = boat_symbol;
                if((*boats_[i/2]).is_vertical()){
                    tmp_y++;
                }else{
                    tmp_x++;
                }
            }
        }
    }

//FUNCTION MEMBER
    void game_elements::defense_grid::set_boat(boat* b, const coordinates& coord){

    }
    std::vector<game_elements::boat*> game_elements::defense_grid::boat_in_radius(const coordinates& coord, int radius) const{

    } 
    game_elements::boat* game_elements::defense_grid::get_boat(const coordinates& coord) const{

    }
    bool game_elements::defense_grid::check_coordinates(const coordinates& coord) const{

    }
    std::ostream& game_elements::defense_grid::write(std::ostream& os) const {
        for(int i = 0; i < COLUMNS; i++){
            for(int j = 0; j < ROWS; j++){
                os << map_[i][j];
            }
            os << '\n';
        }
        return os;
    }

//OPERATORS
    std::ostream& game_elements::operator<<(std::ostream& os, const defense_grid& dg ){
        return dg.write(os);
    }

//HELPER FUNCTIONS
    bool game_elements::defense_grid::check_coordinates(const coordinates& coord) const {
        if(coord.get_x() > 11 || coord.get_x() < 0 || coord.get_y() > 11 || coord.get_y() < 0){
            return false;
        }
        return true;
    }
