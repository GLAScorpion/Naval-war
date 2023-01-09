#include "../../include/elements/esplorazione.h"
#include "../../include/elements/attackgrid.h"

void game_elements::esplorazione::sonar(attack_grid& ag, const coordinates& coord){
    std::vector<boat*> boats = ag.boats_in_radius(coord, ESPLORAZIONE_RADIUS); 
}