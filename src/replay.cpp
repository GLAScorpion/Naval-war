/*
@author: PIERPAOLO COLELLA

    SHORT DEFINITION: there are two possible way of doing the replay of a game: 
        printing in file, or on the screen. the equivalent for this two are the 
        format "v" or "f" (which are specified in a field of terminal string passed 
        to this program). 
*/

#include <fstream>
#include <thread>
#include <chrono>
#include "../include/boats.h"
#include "../include/person.h"

using std::cout;
using std::string;
using std::vector;
using std::endl;

using game_elements::player;
using game_elements::coordinates;

constexpr int CMD_MAX_SIZE = 7;
constexpr int kCorazzataNum = 3;
constexpr int kSupportoNum = 3;
constexpr int kEsplorazioneNum = 2;
constexpr int SLEEP = 1;

const string flag_val {"GAME_PHASE"};
const string starting_player_flag {"STARTING_PLAYER:"};
const string file_ext {".txt"};

//validate a file name 
void validate(const string& str);

int main(int argc, char* argv[]){
    //doing some simple checks on the argument
    bool file_mode = false;
    if(argc < 3) throw std::invalid_argument("Not enough arguments");
    if(argc > 4) throw std::invalid_argument("Too many arguments");

    string mode {argv[1]};
    validate(string(argv[2]));
    std::fstream log {string(argv[2]), std::fstream::in};
    std::fstream file_out;

    //reads the mode (possible: "v", "f") 
    if(mode == "v" and argc == 3){
        //do nothing
    }else if(mode == "f" and argc == 4){
        file_mode = true;
        validate(string(argv[3]));
        file_out = std::fstream (string(argv[3]), std::fstream::out | std::fstream::trunc);
    }else{
        throw std::invalid_argument("Invalid argument");
    }

    vector<player*> players{2};
    players[0] = new game_elements::person();
    players[1] = new game_elements::person();
    players[0]->link(players[1]);

    //setting the boats
    for(int i=0; i < game_elements::kBoatNumber * 2; i++){
        vector<coordinates> tmp;
        game_elements::boat* tmp_boat;
        string tmp_cmd;
        string cmd;

        //log file reading operations
        log >> tmp_cmd;
        cmd += tmp_cmd;
        cmd += " ";
        log >> tmp_cmd;
        cmd += tmp_cmd;
        tmp = game_elements::str_to_coord(cmd);

        if(tmp[1].get_x() == -1) throw std::invalid_argument("Invalid log format");

        //creating instances of boats
        if(i%game_elements::kBoatNumber < kCorazzataNum){
            tmp_boat = new game_elements::corazzata(tmp[0],tmp[1]); 
        }else if(i%game_elements::kBoatNumber < kCorazzataNum + kSupportoNum){
            tmp_boat = new game_elements::supporto(tmp[0],tmp[1]);
        }else{
            tmp_boat = new game_elements::esplorazione(tmp[0],tmp[1]);
        }

        players[i/game_elements::kBoatNumber]->place_boat(tmp_boat);
    }
    
    //print setup phase in active stream
    if(file_mode){
        file_out << "SETUP PHASE\n";
        file_out << "PLAYER: " << players[0]->get_id()+1<<endl<<endl;
        file_out << players[0]->print_grid()<<endl;  
        file_out << "PLAYER: " << players[1]->get_id()+1<<endl<<endl;
        file_out << players[1]->print_grid()<<endl<<endl;  
    }else{
        cout << "SETUP PHASE\n";
        cout << "PLAYER: " << players[0]->get_id()+1<<endl<<endl;
        cout << players[0]->print_grid()<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));  
        cout << "\033[H\033[2J";
        cout << "PLAYER: " << players[1]->get_id()+1<<endl<<endl;
        cout << players[1]->print_grid()<<endl<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
    }

    //mid file format check
    string flag;
    log >> flag;
    if(flag != flag_val) throw std::invalid_argument("Invalid file format");
    log >> flag;
    if(flag != starting_player_flag) throw std::invalid_argument("Invalid file format");
    int i;
    log >> i;

    if(file_mode){
        file_out << "GAME PHASE\n\n";
    }else{
        cout << "GAME PHASE\n\n";
    }
    //turns on attack grid
    players[0]->switch_print_attackgrid();
    players[1]->switch_print_attackgrid();
    //replaying game phase
    for(; !log.eof();i++){
        string tmp_cmd;
        string cmd;
        log >> tmp_cmd;
        cmd += tmp_cmd;
        cmd += " ";
        log >> tmp_cmd;
        cmd += tmp_cmd;

        if(!players[i%2]->command_exec(cmd)) throw std::invalid_argument("Invalid file format");
        //print both grids of game phase in active stream
        if(file_mode){
            file_out << "PLAYER: " << players[i%2]->get_id()+1<<endl; 
            file_out << "COMMAND: " << cmd<<endl;
            file_out << players[i%2]->print_grid()<<endl;
        }else{
            cout << "\033[H\033[2J";
            cout << "PLAYER: " << players[i%2]->get_id()+1<<endl;
            cout << "COMMAND: " << cmd<<endl;
            cout << players[i%2]->print_grid()<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        }

    } 
    return 0;
}

void validate(const string& str){
    string tmp;
    for(int i = str.length() -1 ; i>1 and str[i]!='.';i--){
        tmp = str[i] + tmp;
    }
    tmp = '.' + tmp;
    if(tmp != file_ext) throw std::invalid_argument("Invalid file type: " + tmp + " instead of " + file_ext );
}