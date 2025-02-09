#ifndef CHECKERSBOARD_HH
#define CHECKERSBOARD_HH

#include "checkerspiece.hh"
#include<list>
#include <QPoint>
using namespace std;
class CheckersBoard
{
    typedef enum {WHITE, BLACK} whichPlayerTurnTypedef;
    typedef enum {GAME_ON, GAME_OFF} gameStatusTypedef;

    std::list<CheckersPiece> _blackPiecesList;
    std::list<CheckersPiece> _whitePiecesList;


    whichPlayerTurnTypedef _playerToPlay;
public:



    void doWhiteMove();
    void doBlackMove();
    bool setPlayer(whichPlayerTurnTypedef colour){if (colour!=_playerToPlay){_playerToPlay = colour; return true;} else {return false;} };

    void proceedGame();
    int checkForPieceToActivated(int p)
    {
        try{
            list<CheckersPiece>::iterator it;
            int tp;
            if(_playerToPlay == WHITE)
            {

                for (it =  _whitePiecesList.begin(); it != _whitePiecesList.end(); ++it)
                {
                    tp = (*it).getPosition();
                    if( tp == p)
                    {
                        return p;
                    }

                }

            }
            else if(_playerToPlay == BLACK)
            {

                for (it =  _blackPiecesList.begin(); it != _blackPiecesList.end(); ++it)
                {
                    tp = (*it).getPosition();
                    if( tp == p)
                    {
                        return p;
                    }

                }

            }
        }
        catch (...)
        {

            return -1;
        }

        return 0;
    }

    CheckersBoard();
};

#endif // CHECKERSBOARD_HH
