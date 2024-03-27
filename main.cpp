#include "chesselements.h"


int main() {

    Chessboard chessboard;
    chessboard.loadPieces();
    chessboard.loadFields();
    chessboard.displayBoard();

    return 1;
}