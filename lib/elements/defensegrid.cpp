#include "../../include/elements/defensegrid.h"
#include "../../include/elements/boat.h"
#include "../../include/elements/corazzata.h"
#include "../../include/elements/supporto.h"
#include "../../include/elements/esplorazione.h"
#include "../../include/elements/utilities.h"



//CONSTRUCTORS
    game_elements::defense_grid::defense_grid(const std::vector<coordinates>& coords){
        if(coords.size() != 16)
            throw std::invalid_argument("The number of boats for a defense grid is 8!");

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                map_[i][j] = ' ';
            }
        }

        int esplorazione_counter = 0;
        int supporto_counter = 0;
        int corazzata_counter = 0;
        int size = 0;
        int tmp_x = 0;
        int tmp_y = 0;
        char boat_symbol;
        for(int i = 0; i < coords.size() ; i+=2){
            check_coordinates(coords[i]); // check begin 
            check_coordinates(coords[i+1]); // check end
            tmp_x = coords[i].get_x();
            tmp_y = coords[i].get_y();
            //std::cout<<"BEGIN: x_coord: "<<tmp_x<<" y_coord: "<<tmp_y;
            //std::cout<<"  END: x_coord: "<<coords[i+1].get_x()<< " y_coord: "<<coords[i+1].get_y() <<std::endl;
            //set the vector boats_ and the boat_symbol
            int size = boat_size(coords[i], coords[i+1]);
            if(size == ESPLORAZIONE_SIZE){
                boats_[i/2] = new esplorazione(coords[i],coords[i+1]);
                boat_symbol = ESPLORAZIONE;
                esplorazione_counter++;
            }else if(size == SUPPORTO_SIZE){
                boats_[i/2] = new supporto(coords[i],coords[i+1]);
                boat_symbol = SUPPORTO;
                supporto_counter++;
            }else if(size == CORAZZATA_SIZE){
                boats_[i/2] = new corazzata(coords[i],coords[i+1]);
                boat_symbol = CORAZZATA;
                corazzata_counter++;
            }
            //sets the map_ symbols
            for(int k = 0; k < size; k++){
                //std::cout<<k<<std::endl;
                if(map_[tmp_y][tmp_x] == VOID){
                    map_[tmp_y][tmp_x] = boat_symbol;
                }else{
                    //std::cout<<*this;
                    std::cout<<std::endl<<"In coordinates x_coord: "<<tmp_x<<" y_coord: "<<tmp_y<<std::endl;
                    std::cout<<"With symbol: "<<map_[tmp_y][tmp_x]<<std::endl;
                    throw std::invalid_argument("Error some boat cross!");
                }
                if((*boats_[i/2]).is_vertical()){
                    //std::cout<<"yes"<<std::endl;
                    tmp_y++;
                }else{
                    //std::cout<<"no"<<std::endl;
                    tmp_x++;
                }
            }

        }
        //check if the boats types quantity are regular
        if(esplorazione_counter != 2 || corazzata_counter != 3 || supporto_counter != 3){
            //std::cout<<esplorazione_counter<<" "<<corazzata_counter<<" "<<supporto_counter<<std::endl;
            throw std::invalid_argument("Invalid begin and end coordinates for boats!");
        }
    }

//FUNCTION MEMBER
    void game_elements::defense_grid::set_boat(boat* b, const coordinates& begin){
        //controls if the moves is possible
        if(!check_move(b,begin)){
            throw std::invalid_argument("The move is not possible for the selected boat ad begin coordinate!");
        }
        int size = b->get_dimension();
        int tmp_x = b->get_begin().get_x();
        int tmp_y = b->get_begin().get_y();
        
        if(!b->move(begin)){
            throw std::invalid_argument("The selected boat cannot move!");
        } 
        int x_offset = b->get_begin().get_x() - tmp_x;
        int y_offset = b->get_begin().get_y() - tmp_y;
        
        char boat_symbol = map_[tmp_y][tmp_x];
        bool vertical = b->is_vertical();
        
        for(int i = 0; i < size; i++){
            map_[tmp_y][tmp_x] = VOID;
            map_[tmp_y + y_offset][tmp_x + x_offset] = boat_symbol;
            if(vertical){
                tmp_y++;
            }else{
                tmp_x++;
            }
        }

    }
    std::vector<game_elements::boat*> game_elements::defense_grid::boats_in_radius(const coordinates& coord, int radius) {
        std::vector<game_elements::boat*> boats;
        
        bool valid = false;
        for(int i = 0; i < BOAT_NUMBER; i++){
            //test for begin of the boat
            if(horizontal_distance(boats_[i]->get_begin(),coord) <= radius){
                if(vertical_distance(boats_[i]->get_begin(),coord) <= radius){
                    valid = true;
                }
            }
            //test for the end of the boat
            if(horizontal_distance(boats_[i]->get_end(),coord) <= radius){
                if(vertical_distance(boats_[i]->get_end(),coord) <= radius){
                    valid = true;
                }
            }
            if(valid){
                boats.push_back(boats_[i]);           
                valid = false;
            }
        }
        return boats;
    } 
    game_elements::boat* game_elements::defense_grid::get_boat(const coordinates& coord) const{
        for(int i = 0; i < BOAT_NUMBER; i++){
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

    std::ostream& game_elements::defense_grid::write(std::ostream& os) const {
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
    void game_elements::defense_grid::set_cell(const coordinates& coord, char boat_symbol){
        if(boat_symbol != VOID && boat_symbol != CORAZZATA && boat_symbol != ESPLORAZIONE && boat_symbol != SUPPORTO){
            throw std::invalid_argument("The symobol is not valid for this grid!");
        }
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
    std::vector<game_elements::boat*> game_elements::defense_grid::get_boats() const{
        return boats_;
    }

//OPERATORS
    std::ostream& game_elements::operator<<(std::ostream& os, const defense_grid& dg ){
        return dg.write(os);
    }
//HELPER FUNCTIONS
    bool game_elements::defense_grid::check_move(boat* b, const coordinates& begin){
        int size = b->get_dimension();
        int tmp_x = begin.get_x();
        int tmp_y = begin.get_y();
        for(int i = 0; i < size; i++){
            if(map_[tmp_y][tmp_x] != VOID){
                return false;
            }
            if(b->is_vertical()){
                tmp_y++;
            }else{
                tmp_x++;
            }
        }
        return true;
    }
