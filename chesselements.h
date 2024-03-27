#ifndef CHESSELEMENTS_H
#define CHESSELEMENTS_H
#include <string>
#include <iostream>


unsigned short fieldNum(unsigned short row, unsigned short col);


class Piece {
    public:
    std::string name;
    int value;
    int color;  /*  
                    0 - white, 1 - black 
                */
    int type;   /* 
                    0 - pawn        1 - knight
                    2 - bishop      3 - rook
                    4 - queen       5 - king 
                */
    bool is_on_board;

    public:
    void set(std::string name_, int value_, int color_, int type_, bool is_on_board_);

};


class Field {
    public:
    int column;
    int row;
    int color; // 0 - white, 1 - black
    bool is_piece;
    bool is_attacked_by_white;
    bool is_attacked_by_black;
    Piece *piece;

    public:
    void updatePiece(Piece *piece_passed) {
        piece = piece_passed;
    }

    void set(int column_, int row_, int color_, bool is_piece_, bool is_attacked_by_white_, bool is_attacked_by_black_, Piece *piece_);
};


class Chessboard {
    private:
    
    Field field[64];
    Piece pawn[16], knight[4], bishop[4], rook[4], queen[2], king[2];

    public:
    void loadFields();
    void loadPieces();
    void displayBoard();
    
};

#endif // CHESSELEMENTS_H