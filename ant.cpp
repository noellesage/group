#include "ant.hpp"
#include "critter.hpp"

#include <time.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

Ant::Ant()
{
    id = 'O';
}

Ant::~Ant()
{

}

void Ant::move(Critter*** c, int row, int col)
{
    int counter = 0;
    int starter = rand() % 4 + 1;

    while(moveHistory == false)
    {
        if(starter == 1)
        {
            if(row == 0)
            {
                counter += 1;
                starter = 2;
            }
            else if(c[row-1][col] == nullptr)
            {
                c[row-1][col] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter += 1;
                starter = 2;
            }
        }
        if(starter == 2)
        {
            if(row == 19)
            {
                counter +=1;
                starter = 3;
            }
            else if(c[row+1][col] == nullptr)
            {
                c[row+1][col] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 3;
            }
        }
        if(starter == 3)
        {
            if(col == 0)
            {
                counter +=1;
                starter = 4;
            }
            else if(c[row][col-1] == nullptr)
            {
                c[row][col-1] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 4;
            }
        }
        if(starter == 4)
        {
            if(col == 19)
            {
                counter +=1;
                starter = 1;
            }
            else if(c[row][col+1] == nullptr)
            {
                c[row][col+1] = c[row][col];
                c[row][col] = nullptr;
                moveHistory = true;
            }
            else
            {
                counter +=1;
                starter = 1;
            }
        }
    }
}


void Ant::breed(Critter*** c, int row, int col)
{
    int counter = 0;
    int starter = rand() % 4 + 1;
    if(c[row][col]->getAge() >= 3 && c[row][col]->getAge() % 3 == 0)
    {
        while(counter < 4)
        {
            if(starter == 1)
            {
                if(row == 0)
                {
                    counter += 1;
                    starter = 2;
                }
                else if(c[row-1][col] == nullptr)
                {
                    c[row-1][col] = new Ant();
                    c[row-1][col]->setMoveHistory(true);
                    break;
                }
                else
                {
                    counter += 1;
                    starter = 2;
                }
            }
            if(starter == 2)
            {
                if(row == 19)
                {
                    counter +=1;
                    starter = 3;
                }
                else if(c[row+1][col] == nullptr)
                {

                    c[row+1][col] = new Ant();
                    c[row+1][col]->setMoveHistory(true);
                    break;
                }
                else
                {
                    counter +=1;
                    starter = 3;
                }
            }
            if(starter == 3)
            {
                if(col == 0)
                {
                    counter +=1;
                    starter = 4;
                }
                else if(c[row][col-1] == nullptr)
                {
                    c[row][col-1] = new Ant();
                    c[row][col-1]->setMoveHistory(true);
                    break;
                }
                else
                {
                    counter +=1;
                    starter = 4;
                }
            }
            if(starter == 4)
            {
                if(col == 19)
                {
                    counter +=1;
                    starter = 1;
                }
                else if(c[row][col+1] == nullptr)
                {
                    c[row][col+1] = new Ant();
                    c[row][col+1]->setMoveHistory(true);
                    break;

                }
                else
                {
                    counter +=1;
                    starter = 1;
                }
            }
        }
    }

}

