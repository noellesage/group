#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

#include <iostream>

using namespace std;

Board::Board()
{
    grid = new Critter**[20];
    for(int i = 0; i < 20; i++)
    {
        grid[i] = new Critter*[20];
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            grid[i][j] = nullptr;
        }
    }

    critterCount = 1;
}

Board::~Board()
{
    for(int i = 0; i < 20; i++)
    {
        delete [] grid[i];
    }

    delete [] grid;
}

void Board::printBoard()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {
                cout << '.';
            }
            else if(grid[i][j]->getID() == 'O')
            {
                cout << 'O';
            }
			else if (grid[i][j]->getID() == 'X')
			{
				cout << 'X';
			}
        }
        cout << endl;
    }

    cout << endl;

}

Critter*** Board::getGrid()
{
    return grid;
}

void Board::checkAntMove()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->move(getGrid(), i, j);
            }
        }
    }
}

void Board::checkDoodleMove()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] == nullptr)
			{

			}
			else if (grid[i][j]->getID() == 'X')
			{
				grid[i][j]->move(getGrid(), i, j);
			}
		}
	}
}

void Board::advanceAge()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else //if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->setAge();
                grid[i][j]->setMoveHistory(false);
            }
        }
    }
}

void Board::checkAntBreed()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->breed(getGrid(), i, j);
            }
        }
    }
}

void Board::checkDoodleStarve()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else if(grid[i][j]->getAge() > 3)
            {
                grid[i][j]->starve(getGrid(), i, j);
            }
        }
    }
}
