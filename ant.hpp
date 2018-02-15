#ifndef ANT_HPP_INCLUDED
#define ANT_HPP_INCLUDED

#include "critter.hpp"

class Ant : public Critter
{
    private:

    public:
        Ant();
        virtual ~Ant();
        void move(Critter***, int , int);
        void breed(Critter***, int, int);

};

#endif // ANT_HPP_INCLUDED
