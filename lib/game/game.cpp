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
        cout<<players[i/game_elements::BOAT_NUMBER]->print()<<endl;
        vector<coordinates> tmp;
        bool pass = true;
        while(pass){
            if(i%game_elements::BOAT_NUMBER < 3){
                cout<<"Dispatch armored ship\n";
                tmp = game_elements::str_to_coord(players[i/game_elements::BOAT_NUMBER]->command_picker());
                if(tmp[1].get_x() != -1){
                    if(players[i/game_elements::BOAT_NUMBER]->place_boat(new game_elements::corazzata(tmp[0],tmp[1]))) {
                        pass = false;
                    }else{
                        cout<<"Invalid placement, retry\n";
                    }
                }else{
                    cout<<"Can't use this now, retry\n";
                }
                
            }else if(i%game_elements::BOAT_NUMBER < 6){
                cout<<"Dispatch support ship\n";
                tmp = game_elements::str_to_coord(players[i/game_elements::BOAT_NUMBER]->command_picker());
                if(tmp[1].get_x() != -1){
                    if(players[i/game_elements::BOAT_NUMBER]->place_boat(new game_elements::supporto(tmp[0],tmp[1]))) {
                        pass = false;
                    }else{
                        cout<<"Invalid placement, retry\n";
                    }
                }else{
                    cout<<"Can't use this now, retry\n";
                }
            }else{
                cout<<"Dispatch radar ship\n";
                tmp = game_elements::str_to_coord(players[i/game_elements::BOAT_NUMBER]->command_picker());
                if(tmp[1].get_x() != -1){
                    if(players[i/game_elements::BOAT_NUMBER]->place_boat(new game_elements::esplorazione(tmp[0],tmp[1]))) {
                        pass = false;
                    }else{
                        cout<<"Invalid placement, retry\n";
                    }
                }else{
                    cout<<"Can't use this now, retry\n";
                }
            }
        }
    }
    for(int i = 0; !players[0]->has_lost() and !players[1]->has_lost(); i++){

    }
}
