#ifndef CHECKERSPIECE_H
#define CHECKERSPIECE_H
#include <stdint.h>
#include<QString>
#include<QPoint>
class CheckersPiece
{
    typedef enum {BLACK, WHITE}colorTypedef;
    typedef enum {NOT_ACTIVATED, ACTIVATED, DEAD, GRABBED} stateTypedef;
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
    void setPosition(int p){ this->_position = p;};
    int getPosition(){return this->_position;};
    void activatePiece() {_status = ACTIVATED;};
    void deactivatePiece() {_status = NOT_ACTIVATED;}
    //    static void  pieceCounterInit(){ uint8_t CheckersPiece::_pieceCounter=0;};
};

#endif // CHECKERSPIECE_H
