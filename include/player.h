/*
@author: ALBERTO PASINATO

SHORT DEFINITION:
    Abstract class that defines all the operation possible for a general player (robot or person)  
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "../include/defensegrid.h"
#include "../include/attackgrid.h"

namespace game_elements{

    const std::string kCmdClearSonar {"AA AA"};
    const std::string kCmdClearHit {"BB BB"};
    const std::string kCmdClearMiss {"CC CC"};
    const std::string kCmdGrid {"XX XX"};
    class player{
        public:

            //CONSTRUCTORS

                //copy constructor (deleted)
                player(const player& p) = delete;

                //no argument constructor
                explicit player():dg {  new defense_grid()}{}

            //MEMBER FUNCTIONS

                //links two players
                void link(player* other);

                //returns a known command
                virtual std::string command_picker() const = 0;

                //executes the command if possible, else returns false
                bool command_exec(const std::string& cmd);

                //checks if the boat choice is correct
                virtual bool boat_choice(const coordinates& coord) const = 0;

                //prints to console the given string if needed
                virtual void print(const std::string& str) const = 0;

                //returns coords in valid format
                virtual std::string coord_picker() const = 0;

                //returns char identifier
                virtual char char_id() const = 0;

                //executes special commands if recognized
                virtual bool exec_special(const std::string& cmd) = 0;

                //changes the grid to print
                void switch_grid() {  print_grid_ = !print_grid_;}
                
                //true if set to print defensegrid
                bool which_grid() const {  return print_grid_;}
                
                //returns id_
                int get_id() const {  return id_;}
                
                //returns true if all ships in possession have sunk
                bool has_lost() const {  return dg->get_boats().size() == 0;}
                
                //place a boat on the grid if possible
                bool place_boat(boat* b);

                //activates or deactivates attackgrid print
                void switch_print_attackgrid() {print_attackgrid_ = !print_attackgrid_;}
                
                //prints the active grid
                const std::string print_grid() const;
            
            //OPERATORS
                
                //copy assignment (deleted)
                player& operator=(const player& p) = delete;
        
        protected:
            //DATA MEMBERS

                attack_grid* ag = nullptr;
                defense_grid* dg;
                int id_;
                bool print_grid_ = true;
                bool print_attackgrid_ = false;
    };

}
#endif 