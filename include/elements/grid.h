/*
@author: Mattia Scantamburlo

SHORT DEFINITION:
--> This abstract class describes the general behavior of a grid
*/
#ifndef GRID_H
#define GRID_H

#include <iostream>

#include "boat.h"
#include "corazzata.h"
#include "supporto.h"
#include "sottomarino.h"

namespace game_elements{

    class grid{
    public:
        grid() = delete;
        grid(const grid& g) = delete;
        grid& operator=(const grid& g) = delete;  
    protected:
        grid();
    private:
    };

}
#endif 