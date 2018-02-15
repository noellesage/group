#include "critter.hpp"

#include <iostream>

using namespace std;

Critter::Critter()
{
    age = 0;
    id = ' ';
    moveHistory = false;
}

void Critter::move(Critter*** c, int row, int col)
{

}

void Critter::breed(Critter*** c, int row, int col)
{

}

char Critter::getID()
{
    return id;
}

void Critter::setMoveHistory(bool t)
{
    moveHistory = t;
}

void Critter::setAge()
{
    age += 1;
}

int Critter::getAge()
{
    return age;
}
