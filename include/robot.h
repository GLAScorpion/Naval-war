/*
@author: PIERPAOLO COLELLA

SHORT DEFINITION:
    Contains derived class (from player) with all the elements necessaire to simulate a robot behavior in the game
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

#include "../include/player.h" 

namespace game_elements{

    constexpr char ROBOT_CHAR = 'C';

    class robot : public player{
        public:
            //CONSTRUCTORS

                //copy constructor (deleted)
                robot(const robot& b) = delete;
                
                //default constructor
                robot():player(){
                    static int counter_;
                    id_ = counter_++;
                }
            
            //MEMBER FUNCTIONS
                
                //returns a command choosen randomly
                std::string command_picker() const override;
                
                //checks if the boat choice is correct
                bool boat_choice(const coordinates& coord) const override;
                
                //doesn't print anything
                void print(const std::string& str) const override {  return;}
                
                //returns char identifier
                char char_id() const override {  return ROBOT_CHAR;}
                
                //returns false, robot can't execute special
                bool exec_special(const std::string& cmd) override {  return false;}
                
                //returns coords in valid format
                std::string coord_picker() const override;
            
            //OPERATORS
            
                //copy assignment (deleted)
                robot& operator=(const robot& b) = delete;
    };

}

#endif 