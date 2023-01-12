#include <iostream>
#include <fstream>
#include <vector>
#include "../../include/elements/player.h"
#include "../../include/elements/grids.h"
#include "../../include/elements/robot.h"
#include "../../include/elements/boats.h"
#include "../../include/elements/person.h"
using std::cout;
using std::string;
using std::vector;
using std::endl;
using game_elements::player;
using game_elements::coordinates;
constexpr int CORAZZATA_NUM = 3;
constexpr int SUPPORTO_NUM = 3;
constexpr int ESPLORAZIONE_NUM = 2;
int main(int argc, char* argv[])
{
    if(argc < 2) throw std::invalid_argument("Not enough arguments");
    if(argc > 2) throw std::invalid_argument("Too many arguments");
    string arg{argv[1]};
    if(arg.length()!=2) throw std::invalid_argument("Invalid arguments");
    vector<player*> players{2};
    if(arg[0] == 'c'){
        players[0] = new game_elements::robot();
    }else if(arg[0] == 'p'){
        players[0] = new game_elements::person();
    }else{
        throw std::invalid_argument("Invalid arguments");
    }
    if(arg[1] == 'c'){
        players[1] = new game_elements::robot();
    }else if(arg[1] == 'p'){
        players[1] = new game_elements::person();
    }else{
        throw std::invalid_argument("Invalid arguments");
    }
    players[0]->link(players[1]);
    for(int i=0; i < game_elements::BOAT_NUMBER * 2; i++){
        cout << "PLAYER: " << players[i/game_elements::BOAT_NUMBER]->get_id()+1<<endl;
        cout<<players[i/game_elements::BOAT_NUMBER]->print_grid()<<endl;
        vector<coordinates> tmp;
        bool pass = true;
        if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM){
            cout<<"Dispatch battleship ship\n"; 
        }else if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM + SUPPORTO_NUM){
            cout<<"Dispatch support ship\n";
        }else{
            cout<<"Dispatch radar ship\n";
        }
        while(pass){
            tmp = game_elements::str_to_coord(players[i/game_elements::BOAT_NUMBER]->command_picker());
            if(tmp[1].get_x() != -1){
                try{
                    game_elements::boat* tmp_boat;
                    if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM){
                        tmp_boat = new game_elements::corazzata(tmp[0],tmp[1]); 
                    }else if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM + SUPPORTO_NUM){
                        tmp_boat = new game_elements::supporto(tmp[0],tmp[1]);
                    }else{
                        tmp_boat = new game_elements::esplorazione(tmp[0],tmp[1]);
                    }
                    if(players[i/game_elements::BOAT_NUMBER]->place_boat(tmp_boat)){
                        pass = false;
                    }else{
                        players[i/game_elements::BOAT_NUMBER]->print("Invalid placement, retry\n");
                    }
                }
                catch(std::logic_error& e){
                    players[i/game_elements::BOAT_NUMBER]->print("Invalid placement, retry\n");
                }
            }else{
                players[i/game_elements::BOAT_NUMBER]->print("Can't use this now, retry\n");
            }    
        }
    }
    for(int i = 0; !players[0]->has_lost() and !players[1]->has_lost(); i++){

    }
}
