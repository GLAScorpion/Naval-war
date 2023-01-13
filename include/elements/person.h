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
    constexpr char PERSON_CHAR = 'P';
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
            //checks if the boat choice is correct
            bool boat_choice(const coordinates& coord) override;
            //prints to console the string
            void print(const std::string& str) override{std::cout<<str<<std::endl;}
            //returns char identifier
            char char_id() override {return PERSON_CHAR;}
            //returns coords in valid format
            std::string coord_picker() override;
            //executes special commands if recognized
            bool exec_special(const std::string& cmd) override;
        //OPERATORS
            person& operator=(const person& b) = delete;
        private:
    };

}
#endif 