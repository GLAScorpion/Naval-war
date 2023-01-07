#include <iostream>
#include <vector>

#include "../include/elements/attackgrid.h"
#include "../include/elements/defensegrid.h"
#include "../include/elements/boat.h"
#include "../include/elements/corazzata.h"

int main(void){
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
    game_elements::defense_grid dg1 {v};
    game_elements::defense_grid dg2{v};
    game_elements::attack_grid ag2 {&dg1};
    game_elements::attack_grid ag1 {&dg2};

    std::cout<<std::endl<<"Testing attack_grid constructor:"<<std::endl;
    std::vector<game_elements::boat*> b = dg1.get_boats();

    //Testing boat_in_radius of attacking_grid
    std::cout<<std::endl<<"Testing boat_in_radius:"<<std::endl;
    std::vector<game_elements::boat*> b1 = ag2.boats_in_radius(game_elements::coordinates(1,0),5);
    std::cout<<"Printing all the begin coordinates of boats in a radius of 5 from point (1,0):"<<std::endl;
    for(int i = 0; i < b1.size(); i++){
        std::cout<<"boat number: "<<i<<" coordinates: ("<<b1[i]->get_begin().get_x()<<", "<<b1[i]->get_begin().get_y()<<")"<<std::endl;
    }

    //testing corazzata attack
    std::cout<<std::endl<<"Testing corazzata attack (get_boat, set_cell of attacking grid):"<<std::endl;
    game_elements::corazzata* attacker;
    
    //selecting casual attacker
    for(int i = 0; i < b.size(); i++){
        if(b[i]->get_dimension() == 5){
            attacker = dynamic_cast<game_elements::corazzata*> (b[i]);
            std::cout<<"Found attacking boat!"<<std::endl;
            break;
        }
    }

    std::cout<<"Attacking map before:"<<std::endl<<ag1<<std::endl;
    std::cout<<"Defender map"<<std::endl<<dg2<<std::endl<<std::endl;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(attacker != nullptr && attacker->attack(&ag1,game_elements::coordinates(j,i))){
                //std::cout<<"Hey, you caught a boat!"<<std::endl;
            }else{
                //std::cout<<"Nothing special in the attacking coordinates!"<<std::endl;
            }
        }
    }
    std::cout<<"Attacking map after attacking all possible coordinates:"<<std::endl<<ag1<<std::endl;

}

/*
here we have 2 couples of grid (dg1,ag1) and (dg2,ag2) whit identical boats placements
*/