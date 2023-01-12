/*
@author

SHORT DEFINITION:
    Abstract class that defines all the operation possible for a general player (robot or person)  
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "defensegrid.h"
//#include "" 

namespace game_elements{

    const std::string CMD_CLEAR_SONAR {"AA AA"};
    const std::string CMD_CLEAR_HIT {"BB BB"};
    const std::string CMD_CLEAR_MISS {"CC CC"};
    const std::string CMD_GRID {"XX XX"};

    class attack_grid;
    class player{

    public:
    //CONSTRUCTORS
        //copy constructor (deleted)
        player(const player& p) = delete;
        //no argument constructor
        explicit player():dg{new defense_grid()}{}
    //MEMBER FUNCTIONS
        //links two players
        void link(player* other);
        //returns a known command
        virtual std::string command_picker() = 0;
        //executes the command if possible, else returns false
        virtual bool command_exec(const std::string& cmd) = 0;
        //checks if the boat choice is correct
        virtual bool boat_choice(const coordinates& coord) = 0;
        //prints to console the given string if needed
        virtual void print(const std::string& str) = 0;
        //changes the grid to print
        void switch_grid() {print_dg_ = !print_dg_;}
        //returns id_
        int get_id(){return id_;}
        //returns true if all ships in possession have sunk
        bool has_lost();
        //place a boat on the grid if possible
        bool place_boat(boat* b);
        //prints the active grid
        const std::string print_grid() const;
    //OPERATORS
        //copy assignment (deleted)
        player& operator=(const player& p) = delete;
    protected:
        attack_grid* ag = nullptr;
        defense_grid* dg;
        int id_;
        bool print_dg_ = true;
    private:

    };

}
#endif 