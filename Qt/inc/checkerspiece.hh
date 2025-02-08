#ifndef CHECKERSPIECE_H
#define CHECKERSPIECE_H
#include <stdint.h>
#include<QString>
#include<QPoint>>
class CheckersPiece
{
    typedef enum {BLACK, WHITE}colorTypedef;
    typedef enum {ALIVE_NOT_ACTIVATED, DEAD, GRABBED, ACTIVATED} stateTypedef;
    int _position;
    colorTypedef _color;
    stateTypedef _status;
    QString _ActivatedName;
    QString _notActivatedName;

public:
//    using colorType = colorTypedef;
    static uint8_t _pieceCounter;
    CheckersPiece();
    CheckersPiece(int position, CheckersPiece::colorTypedef color, QString activated = ":/board_img/piece_png_act", QString notActivated=":/board_img/piece_png");

    void activatePiece() {_status = ACTIVATED;};
    void deactivatePiece() {_status = ALIVE_NOT_ACTIVATED;}
    //    static void  pieceCounterInit(){ uint8_t CheckersPiece::_pieceCounter=0;};
};

#endif // CHECKERSPIECE_H
