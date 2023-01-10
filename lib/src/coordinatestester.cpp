#include <iostream>
#include <vector>
#include "../include/elements/utilities.h"

constexpr int CORAZZATA_SIZE = 5;
constexpr int ESPORAZIONE_SIZE = 1;
constexpr int SUPPORTO_SIZE = 3;

int main(void){
    //testing the main features of coordinates

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


    std::cout<<"Printing coordinates (test: get_x, get_y, constructor ):"<<std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout<<"coordinates number "<<i<<" is ("<<v[i].get_x()<<", "<<v[i].get_y()<<")"<<std::endl;
    }

    std::vector<int> distance(8);
    std::cout<<std::endl<<"Printing coordinates horizontal and vertical distance (testing: horizontal_distance and vertical_distance):"<<std::endl;
    for(int i = 0; i < v.size(); i+=2){
        distance[i/2] = 1;
        distance[i] += horizontal_distance(v[i],v[i+1]);
        std::cout<<"horizontal distance between coordinates n: "<<i<<" and "<<i+1<<" is: "<<horizontal_distance(v[i],v[i+1])<<std::endl;
    }

    std::cout<<std::endl;
    for(int i = 0; i < v.size(); i+=2){
        distance[i/2] += vertical_distance(v[i],v[i+1]);
        std::cout<<"vertical distance between coordinates n: "<<i<<" and "<<i+1<<" is: "<<vertical_distance(v[i],v[i+1])<<std::endl;
    }

    std::cout<<std::endl<<"Printing the name of boats entered: "<<std::endl;
    for(int i = 0; i < distance.size(); i++){
        std::cout<<"with dimension: "<<distance[i]<<" ";
        if(distance[i] == CORAZZATA_SIZE){
            std::cout<<"Corazzata"<<std::endl;
        }else if(distance[i] == ESPORAZIONE_SIZE){
            std::cout<<"Esplorazione"<<std::endl;
        }else if(distance[i] == SUPPORTO_SIZE){
            std::cout<<"Supporto"<<std::endl;
        }else{
            std::cout<<"Not identified boat!"<<std::endl;
        }
    }
    return 0;
}