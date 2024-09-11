#ifndef PLAYER_HH
#define PLAYER_HH
//std cpp lbs
#include <list>
#include<iostream>

//Qt libs
#include<QDebug>

// my classes
#include "pawn.hh"
/*!
 * \brief The player class
 */
class Player
{
private:
    std::list<Pawn> _listOfPieces;
public:
    Player();
};

#endif // PLAYER_HH
