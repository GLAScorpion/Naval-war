#include "../../include/elements/defensegrid.h"



//CONSTRUCTORS
    game_elements::defense_grid::defense_grid(const std::vector<coordinates>& c){
        if(c.size() != 16)
            throw std::invalid_argument("The number of boats for a defense grid is 8!");
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                map_[i][j] = ' ';
            }
        }
        int size = 0;
        for(int i = 0; i < c.size() ; i+=2){
            check_coordinates(c[i]);
            check_coordinates(c[i+1]);
            size = boat_size(c[i],c[i+1]);
            if(size == ESPLORAZIONE_SIZE){
                boats_[i/2] = new esplorazione(c[i],c[i+1]);
                /* // in via di sviluppo
                for(int k = 0; k < size; i++){
                    map[][] = ESPLORAZIONE;
                }
                */
            }else if(size == SUPPORTO_SIZE){
                boats_[i/2] = new supporto(c[i],c[i+1]);
            }else{
                boats_[i/2] = new corazzata(c[i],c[i+1]);
            }
        }
    }

//FUNCTION MEMBER
    void game_elements::defense_grid::set_boat(boat* b, const coordinates& c){

    }
    std::vector<game_elements::boat*> game_elements::defense_grid::boat_in_radius(const coordinates& c, int radius) const{

    } 
    game_elements::boat* game_elements::defense_grid::get_boat(const coordinates& c) const{

    }
    bool game_elements::defense_grid::check_coordinates(const coordinates& c) const{

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
