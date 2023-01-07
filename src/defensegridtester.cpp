#include "../include/elements/defensegrid.h"
#include "../include/elements/utilities.h"

int main(){
    std::vector<game_elements::coordinates> v;
    v.push_back(game_elements::coordinates(1,0));
    v.push_back(game_elements::coordinates(3,0));
    v.push_back(game_elements::coordinates(5,1));
    v.push_back(game_elements::coordinates(9,1));
    v.push_back(game_elements::coordinates(1,3));
    v.push_back(game_elements::coordinates(1,7));
    v.push_back(game_elements::coordinates(5,3));
    v.push_back(game_elements::coordinates(7,3));
    v.push_back(game_elements::coordinates(7,5));
    v.push_back(game_elements::coordinates(11,5));
    v.push_back(game_elements::coordinates(7,10));
    v.push_back(game_elements::coordinates(7,10));
    v.push_back(game_elements::coordinates(1,9));
    v.push_back(game_elements::coordinates(1,9));
    v.push_back(game_elements::coordinates(5,9));
    v.push_back(game_elements::coordinates(7,9));
    try{
    game_elements::defense_grid dg {v};
    }catch(std::invalid_argument e){
        std::cout<<e.what();
    }
    //std::cout<<dg;
}