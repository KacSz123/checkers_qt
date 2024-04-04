#ifndef PAWN_HH
#define PAWN_HH


class Pawn
{
private:
    using ENUM_colour = enum{BLACK,WHITE};
    using ENUM_pawnType = enum{PIECE, QUEEN};
    int _postion;
    ENUM_colour _colour;
    ENUM_pawnType _type;
    Pawn();
    Pawn(int position, ENUM_colour colour, ENUM_pawnType type = PIECE);

    void setPosition(int newPosition);
    int getPosition(){return this->_postion;}
    void promotePiece(){this->_type = QUEEN;}
};

#endif // PAWN_HH
