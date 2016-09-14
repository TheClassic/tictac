#include "ultimateBoard.h"

Board& UltimateBoard::GetBoard(int row, int column)
{
    return board[row][column];
}

const Board& UltimateBoard::GetBoard(int row, int column) const
{
    return board[row][column];
}