#ifndef DOODLEBUG_HPP_INCLUDED
#define DOODLEBUG_HPP_INCLUDED

#include "critter.hpp"

class Doodlebug : public Critter
{
    public:
        Doodlebug();
        void move(Critter*** c, int, int);
        void breed(Critter*** c, int, int);
        void starve(Critter*** c, int, int);
};

#endif // DOODLEBUG_HPP_INCLUDED
