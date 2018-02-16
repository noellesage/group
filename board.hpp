#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "critter.hpp"

class Board
{
    private:
        Critter*** grid;
        int critterCount;

    public:
        Board();
        ~Board();
        Board getBoard();
        Critter*** getGrid();
        void printBoard();
        void checkAntMove();
        void checkDoodleStarve();
		    void checkDoodleMove();
        void advanceAge();
        void checkAntBreed();

};

#endif // BOARD_HPP_INCLUDED
