/*
@author:

SHORT DEFINITION:
    start the game idntifieng the type of game : person vs computer(false) or computer vs computer(true)
*/

#include <iostream>
#include "../include/game/game.h"
int main(int argc, char** argv){
    if(argc != 2) return -1;
    
    char coord1 = argv[1][0];
    char coord2 = argv[1][0];
    bool game_type = false;

    if((coord1 == 'p' && coord2 == 'c') || (coord1 == 'c' && coord2 == 'p')){
        
    }else if( coord1 == 'c' && coord2 == 'c'){
        game_type = true;
    }else{
        throw std::invalid_argument("Game type not know!");
    }
    naval_game::game game(game_type);
    game.start();
    return 0;
}