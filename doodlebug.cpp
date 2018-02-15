#include "doodlebug.hpp"
#include "critter.hpp"

#include <time.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

Doodlebug::Doodlebug()
{
    id = 'X';
    num_starve = 0;
}

void Doodlebug::move(Critter*** c, int row, int col)
{
	bool ateAnt = false;

	while (moveHistory == false) {
		if (row != 19 && col != 0 && c[row + 1][col - 1] != nullptr) {
			if (c[row + 1][col - 1]->getID() == 'O') {
				delete c[row + 1][col - 1];
				c[row + 1][col - 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
        num_starve = 0;
				moveHistory = true;
			}
		}
		if (row != 19 && col != 19 && !ateAnt && c[row + 1][col + 1] != nullptr) {
			if (c[row + 1][col + 1]->getID() == 'O') {
				delete c[row + 1][col + 1];
				c[row + 1][col + 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
        num_starve = 0;
				moveHistory = true;
			}
		}
		if (row != 0 && col != 19 && !ateAnt && c[row - 1][col + 1] != nullptr) {
			if (c[row - 1][col + 1]->getID() == 'O') {
				delete c[row - 1][col + 1];
				c[row - 1][col + 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
        num_starve = 0;
				moveHistory = true;
			}
		}
		if (row != 0 && col != 0 && !ateAnt && c[row - 1][col - 1] != nullptr) {
			if (c[row - 1][col - 1]->getID() == 'O') {
				delete c[row - 1][col - 1];
				c[row - 1][col - 1] = c[row][col];
				c[row][col] = nullptr;
				ateAnt = true;
        num_starve = 0;
				moveHistory = true;
			}
		}

		if (!ateAnt) {

			int starter = rand() % 4 + 1;
      num_starve++;
			while (moveHistory == false)
			{
				if (starter == 1)
				{
					if (row == 0)
					{
						starter = 2;
					}
					else if (c[row - 1][col] == nullptr)
					{
						c[row - 1][col] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
					}
					else
					{
						starter = 2;
					}
				}
				if (starter == 2)
				{
					if (row == 19)
					{
						starter = 3;
					}
					else if (c[row + 1][col] == nullptr)
					{
						c[row + 1][col] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
					}
					else
					{
						starter = 3;
					}
				}
				if (starter == 3)
				{
					if (col == 0)
					{
						starter = 4;
					}
					else if (c[row][col - 1] == nullptr)
					{
						c[row][col - 1] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
					}
					else
					{
						starter = 4;
					}
				}
				if (starter == 4)
				{
					if (col == 19)
					{
						starter = 1;
					}
					else if (c[row][col + 1] == nullptr)
					{
						c[row][col + 1] = c[row][col];
						c[row][col] = nullptr;
						moveHistory = true;
					}
					else
					{
						starter = 1;
					}
				}
			}


		}
	}

}

void Doodlebug::breed(Critter*** c, int row, int col)
{
  int counter = 0;
  int starter = rand() % 4 + 1;
  if(c[row][col]->getAge() >= 8 && c[row][col]->getAge() % 8 == 0)
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

bool Doodlebug::starve()
{
  if(num_starve > 3)
  {
    return true;
  }
  else
  {
    return false;
  }
}
