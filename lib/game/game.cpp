#include <iostream>
#include <fstream>
#include <vector>
#include <random>
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
constexpr int GAME_LENGTH = 100;
const std::string filename {"log.txt"};
void print(vector<player*>& players, int turn);
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
    std::fstream file {filename, std::fstream::out | std::fstream::trunc};
    players[0]->link(players[1]);
    for(int i=0; i < game_elements::BOAT_NUMBER * 2; i++){
        print(players,i/game_elements::BOAT_NUMBER);
        vector<coordinates> tmp;
        string tmp_cmd;
        bool pass = true;
        if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM){
            players[i/game_elements::BOAT_NUMBER]->print("Dispatch battleship ship\n"); 
        }else if(i%game_elements::BOAT_NUMBER < CORAZZATA_NUM + SUPPORTO_NUM){
            players[i/game_elements::BOAT_NUMBER]->print("Dispatch support ship\n");
        }else{
            players[i/game_elements::BOAT_NUMBER]->print("Dispatch radar ship\n");
        }
        while(pass){
            tmp_cmd = players[i/game_elements::BOAT_NUMBER]->coord_picker();
            tmp = game_elements::str_to_coord(tmp_cmd);
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
                    file << tmp_cmd << "\n";
                }else{
                    players[i/game_elements::BOAT_NUMBER]->print("Invalid placement, retry\n");
                }
            }
            catch(std::logic_error& e){
                players[i/game_elements::BOAT_NUMBER]->print("Invalid placement, retry\n");
            }           
        }
    }
    cout << "GAME PHASE\n";
    file << "GAME_PHASE\n";
    std::random_device rand;
    std::uniform_int_distribution<int> start(0,1);
    int i = start(rand);
    file<<"STARTING_PLAYER: " << i;
    for(; !players[0]->has_lost() and !players[1]->has_lost() and i < GAME_LENGTH; i++){
        print(players,i%2);
        players[i%2]->print("Waiting for orders, captain!\n");
        bool pass = true;
        std::string tmp;
        while(pass){
            tmp = players[i%2]->command_picker();
            if(players[i%2]->exec_special(tmp)){
                print(players,i%2);
                players[i%2]->print("Waiting for orders, captain!\n");
            }else if(players[i%2]->command_exec(tmp)){
                pass = false;
                file << "\n"<< tmp ;
            }else{
                players[i%2]->print("Coordinates unreachable\n");
            }
        }
        print(players,i%2);
        //players[i%2]->print("Enter to pass turn\n");
        //int pause = getchar();
        if(!players[i%2]->which_grid()) players[i%2]->switch_grid();
    }
    if(players[0]->has_lost()){
        cout << "PLAYER " << players[1]->get_id()+1<<" "<<players[1]->char_id()<<" has won"<<endl;
    }else if(players[1]->has_lost()){
        cout << "PLAYER " << players[0]->get_id()+1<<" "<<players[0]->char_id()<<" has won"<<endl;
    }else{
        cout << "Draw\n";
    }
}
void print(vector<player*>& players, int turn){
    string print;
    print += "PLAYER: "; 
    print += '0' + players[turn]->get_id()+1;
    print += " "; 
    print += players[turn]->char_id(); 
    print += "\n";
    print += players[turn]->print_grid();
    print += "\n";
    players[turn]->print(print);
}