#ifndef CRITTER_HPP_INCLUDED
#define CRITTER_HPP_INCLUDED


class Critter
{
    protected:
        int age;
        char id;
        bool moveHistory;

    public:
        Critter();
        virtual void move(Critter***, int, int);
        virtual void breed(Critter***, int, int);
        void setMoveHistory(bool);
        char getID();
        void setAge();
        int getAge();

};

#endif // CRITTER_HPP_INCLUDED
