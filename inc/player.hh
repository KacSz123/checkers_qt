#ifndef PLAYER_HH
#define PLAYER_HH
//std cpp lbs
#include <list>
#include<iostream>

//Qt libs
#include<QDebug>

/*!
 * \brief The player class
 */
class Player
{
private:
    std::list<int> _listOfPieces;
public:
    Player();
};

#endif // PLAYER_HH
