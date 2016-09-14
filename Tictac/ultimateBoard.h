#pragma once

#include "board.h"


///TODO we should make a Board interface
class UltimateBoard : public Board
{
public:
    Board& GetBoard(int row, int column);
    const Board& GetBoard(int row, int column) const;

private:
    Board board[Board::k_boardSize][Board::k_boardSize];
    Board* activeBoard = nullptr;


};