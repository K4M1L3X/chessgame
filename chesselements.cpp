#include "chesselements.h"
#define ROW 8
#define COL 8


unsigned short fieldNum(unsigned short row, unsigned short col) {
    return 8*(row-1) + (col-1);
}


void Chessboard::loadPieces() {
    // Pawns
    for (int i=0; i<16; i++) {
        pawn[i].set("pawn", 1, (i<8)?0:1, 0, true);
    }

    // Knights
    for (int i=0; i<4; i++) {
        knight[i].set("knight", 3, (i<2)?0:1, 1, true);
    }

    // Bishops
    for (int i=0; i<4; i++) {
        bishop[i].set("bishop", 3, (i<2)?0:1, 2, true);
    }

    // Rooks
    for (int i=0; i<4; i++) {
        rook[i].set("rook", 5, (i<2)?0:1, 3, true);
    }

    // Queens
    for (int i=0; i<2; i++) {
        queen[i].set("queen", 9, (i<1)?0:1, 4, true);
    }

    // Kings
    for (int i=0; i<2; i++) {
        king[i].set("king", 4, (i<1)?0:1, 5, true);
    }

    return;
}

void Chessboard::loadFields() {
    // Pawns
    for (int i=0; i<8; i++) {
        field[fieldNum(2, i+1)].set(i+1, 2, fieldNum(2, i+1)%2==0?1:0, true, true, false, &pawn[i]);
        field[fieldNum(7, i+1)].set(i+1, 7, fieldNum(7, i+1)%2==0?1:0, true, false, true, &pawn[i+8]);
    }

    // Knights
    field[fieldNum(1, 2)].set(2, 1, fieldNum(1, 2)%2==0?1:0, true, true, false, &knight[0]);
    field[fieldNum(1, 7)].set(7, 1, fieldNum(1, 7)%2==0?1:0, true, true, false, &knight[1]);
    field[fieldNum(8, 2)].set(2, 8, fieldNum(8, 2)%2==0?1:0, true, false, true, &knight[2]);
    field[fieldNum(8, 7)].set(7, 8, fieldNum(8, 7)%2==0?1:0, true, false, true, &knight[3]);

    // Bishops
    field[fieldNum(1, 3)].set(3, 1, fieldNum(1, 3)%2==0?1:0, true, true, false, &bishop[0]);
    field[fieldNum(1, 6)].set(6, 1, fieldNum(1, 6)%2==0?1:0, true, true, false, &bishop[1]);
    field[fieldNum(8, 3)].set(3, 8, fieldNum(8, 3)%2==0?1:0, true, false, true, &bishop[2]);
    field[fieldNum(8, 6)].set(6, 8, fieldNum(8, 6)%2==0?1:0, true, false, true, &bishop[3]);

    // Rooks
    field[fieldNum(1, 1)].set(1, 1, fieldNum(1, 1)%2==0?1:0, true, false, false, &rook[0]);
    field[fieldNum(1, 8)].set(8, 1, fieldNum(1, 8)%2==0?1:0, true, false, false, &rook[1]);
    field[fieldNum(8, 1)].set(1, 8, fieldNum(8, 1)%2==0?1:0, true, false, false, &rook[2]);
    field[fieldNum(8, 8)].set(8, 8, fieldNum(8, 8)%2==0?1:0, true, false, false, &rook[3]);

    // Queens
    field[fieldNum(1, 4)].set(4, 1, fieldNum(1, 4)%2==0?1:0, true, true, false, &queen[0]);
    field[fieldNum(8, 4)].set(4, 8, fieldNum(8, 4)%2==0?1:0, true, false, true, &queen[1]);

    // Kings
    field[fieldNum(1, 5)].set(5, 1, fieldNum(1, 5)%2==0?1:0, true, true, false, &king[0]);
    field[fieldNum(8, 5)].set(5, 8, fieldNum(8, 5)%2==0?1:0, true, false, false, &king[1]);

    // Others
    for (int r=3; r<=6; r++) {
        for (int c=1; c<=8; c++) {
            field[fieldNum(r, c)].set(c, r, fieldNum(r, c)%2==0?1:0, false, (r==3)?true:false, (r==6)?true:false, NULL);
        }
    }
}


void Chessboard::displayBoard() {
    char temp;
    for (int r=0; r<8; r++) {
        for (int c=0; c<8; c++) {
            if (field[fieldNum(r+1, c+1)].is_piece) {
                if (field[fieldNum(r+1, c+1)].piece->color) temp = 'W';
                else temp = 'B';
                std::cout << field[fieldNum(r+1, c+1)].piece->name << "(" << temp << ")\t"; 
            }
            else {
                std::cout << "EMPTY \t"; 
            }
        }
        std::cout << "\n";
    }
}


void Field::set(int column_, int row_, int color_, bool is_piece_, bool is_attacked_by_white_, bool is_attacked_by_black_, Piece *piece_) {
        column = column_;
        row = row_;
        color = color_;
        is_piece = is_piece_;
        is_attacked_by_white = is_attacked_by_white_;
        is_attacked_by_black = is_attacked_by_black_;
        updatePiece(piece_);
} 


void Piece::set(std::string name_, int value_, int color_, int type_, bool is_on_board_) {
        name = name_;
        value = value_;
        color = color_;
        type = type_;
        is_on_board = is_on_board_;
} 