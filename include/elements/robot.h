/*
@author
SHORT DEFINITION:
    Contains derived class (from player) with all the elements necessaire to simulate a robot behavior in the game
*/


#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

#include "player.h" 

namespace game_elements{
    
    class robot : public player{
        public:
        //CONSTRUCTORS
            robot(const robot& b) = delete;
            //costruttore di default
            robot():player(){
                static int counter_;
                id_ = counter_++;
                }
        //MEMBER FUNCTIONS
            //retuns a command choosen randomly
            std::string command_picker() override;
            //executes the command if possible, else returns false
            bool command_exec(const std::string& cmd) override;
            //checks if the boat choice is correct
            bool boat_choice(const coordinates& coord) override;
        //OPERATORS
            robot& operator=(const robot& b) = delete;
        private:
    };

}

#endif 