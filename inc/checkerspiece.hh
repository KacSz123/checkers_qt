#ifndef CHECKERSPIECE_H
#define CHECKERSPIECE_H
#include <stdint.h>


class CheckersPiece
{
    typedef enum {BLACK, WHITE}colorTypedef;
    typedef enum {ALIVE_NOT_ACTIVATED, DEAD, GRABBED, ACTIVATED} stateTypedef;
    int _position;
    colorTypedef _color;
    stateTypedef _status;
public:
//    using colorType = colorTypedef;
    static uint8_t _pieceCounter;
    CheckersPiece();
    CheckersPiece(int position, CheckersPiece::colorTypedef color);

//    static void  pieceCounterInit(){ uint8_t CheckersPiece::_pieceCounter=0;};
};

#endif // CHECKERSPIECE_H
