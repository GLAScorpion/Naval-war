/*
@author
SHORT DEFINITION:
    derived class (from player) with all the elements necessaire to describe the possible operations
    of a person playing the game
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "player.h"

namespace game_elements{

    class person : public player{
        public:
        //CONSTRUCTORS
            person(const person& b) = delete;
            //costruttore di default
            person():player(){
                static int counter_;
                id_ = counter_++;
                }
        //MEMBER FUNCTIONS
            //asks user for a command, returns it if known
            std::string command_picker() override;
            //executes the command if possible, else returns false
            bool command_exec(const std::string& cmd) override;
            //checks if the boat choice is correct
            bool boat_choice(const coordinates& coord) override;
        //OPERATORS
            person& operator=(const person& b) = delete;
        private:
    };

}
#endif 