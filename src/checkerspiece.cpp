#include "../inc/checkerspiece.hh"


uint8_t CheckersPiece::_pieceCounter=0;
CheckersPiece::CheckersPiece():_position(0),_color(colorTypedef::BLACK), _status(stateTypedef::ALIVE_NOT_ACTIVATED)
{
   //CheckersPiece::pieceCounterInit();
}

CheckersPiece::CheckersPiece(int position, CheckersPiece::colorTypedef color):_position(position), _color(color), _status(stateTypedef::ALIVE_NOT_ACTIVATED)
{

}
