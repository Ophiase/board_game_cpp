#include "engine/Board.hpp"


int Board::getDimension() const {
    return cellPieces.size();
}

bool Board::isCellEven (CellPosition v) const {
    return ((v.x + v.y) & 1) == 0;
}

bool Board::isCaseInBoard(CellPosition v) const {
    return (0 <= v.x) && (0 <= v.y)
        && (v.x < getDimension()) && (v.y < getDimension());
}

bool Board::isCaseEmpty(CellPosition v) const {
    return getCell(v).isNone();
}

CellPiece Board::getCell(CellPosition v) const {
    return cellPieces[v.y][v.x];
}

CellPiece Board::getCell(int x, int y) const {
    return cellPieces[y][x];
}

bool Board::operator==(Board other) const {
    return (this->player == other.player) && 
        (this->cellPieces == other.cellPieces);
};

bool Board::operator!=(Board other) const {
    return (*this) != other;
};