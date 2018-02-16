#include <iostream>

#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    Board b1;

	Critter* c1 = new Ant();
	Critter* c2 = new Doodlebug();

	Critter*** g1 = b1.getGrid();
    g1[5][18] = c1;
	g1[4][16] = c2;

    b1.printBoard();

    for(int i = 0; i < 10; i++)
    {
		    b1.checkDoodleMove();
		    b1.checkAntMove();
        b1.checkAntBreed();
        b1.checkDoodleStarve();
        b1.advanceAge();
        b1.printBoard();
    }

    return 0;
}
