#include "../include/elements/defensegrid.h"
#include "../include/elements/utilities.h"
#include "../include/elements/boat.h"

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

    //testing defense_grid constructor
    std::cout<<std::endl<<"Testing defense_grid constructor:"<<std::endl;
    game_elements::defense_grid dg {v};
    std::cout<<dg<<std::endl;

    //testing boats_in_radius overridden function member of defense_grid
    std::vector<game_elements::boat*> myvect = dg.boats_in_radius(v[1],1);
    game_elements::boat* b = myvect[0];

    //testing get_boat overridden function member of defense_grid
    game_elements::boat* b1 = dg.get_boat(game_elements::coordinates(1,9));
    
    //testing one way of moving boat (does change map_ data member in defense_grid)
    std::cout<<std::endl<<"Testing set_boat overidden function member, :"<<std::endl;
    std::cout<<"Coordinates of boat before moving: "<<std::endl;
    std::cout<<"begin_x: "<<b1->get_begin().get_x()<<" begin_y: "<<b1->get_begin().get_y()<<std::endl;
    std::cout<<"end_x: "<<b1->get_end().get_x()<<" end_y: "<<b1->get_end().get_y()<<std::endl;

    try{
        dg.set_boat(b1, game_elements::coordinates(1,10));
    }catch(std::invalid_argument e){
        std::cout<<e.what()<<std::endl;
        throw;
    }
    
    std::cout<<"Coordinates of boat after moving: "<<std::endl;
    std::cout<<"begin_x: "<<b1->get_begin().get_x()<<" begin_y: "<<b1->get_begin().get_y()<<std::endl;
    std::cout<<"end_x: "<<b1->get_end().get_x()<<" end_y: "<<b1->get_end().get_y()<<std::endl;

    std::cout<<dg<<std::endl;

    return 0;
}