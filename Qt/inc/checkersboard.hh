#ifndef CHECKERSBOARD_HH
#define CHECKERSBOARD_HH

#include "checkerspiece.hh"
#include<list>
class CheckersBoard
{
    typedef enum {WHITE, BLACK} whosTurnTypedef;

    std::list<CheckersPiece> _blackPiecesList;
    std::list<CheckersPiece> _whitePiecesList;
    whosTurnTypedef _playerToPlay;
public:



    void doWhiteMove();
    void doBlackMove();

    void proceedGame();
    CheckersBoard();
};

#endif // CHECKERSBOARD_HH
