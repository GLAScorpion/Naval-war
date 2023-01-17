/*
@author: PIERPAOLO COLELLA

SHORT DEFINITION:
    derived class (from player) with all the elements necessaire to describe the possible operations
    of a person playing the game
*/

#ifndef PERSON_H
#define PERSON_H

#include "../include/player.h"

namespace game_elements{

    constexpr char kPersonChar = 'P';

    class person : public player{
        public:
            //CONSTRUCTORS

                //copy constructor (deleted)
                person(const person& b) = delete;

                //default constructor
                person():player(){
                    static int counter_;
                    id_ = counter_++;
                    }

            //MEMBER FUNCTIONS

                //asks user for a command, returns it if known
                std::string command_picker() const override;

                //checks if the boat choice is correct
                bool boat_choice(const coordinates& coord) const override;

                //prints to console the string
                void print(const std::string& str) const override {  std::cout<<str<<std::endl;}
                
                //returns char identifier
                char char_id() const override {return kPersonChar;}
                
                //returns coords in valid format
                std::string coord_picker() const override;
                
                //executes special commands if recognized
                bool exec_special(const std::string& cmd) override;
            
            //OPERATORS

                //copy assignment (deleted)
                person& operator=(const person& b) = delete;
    };

}
#endif 