#pragma once

#include "board.h"


///TODO we should make a Board interface
class UltimateBoard : public Board
{
public:
    //Board& GetBoard(int row, int column);
    const Board& GetBoard(int row, int column) const;

    void ChooseInitialBoard(int row, int column);
    virtual eResult play(int row, int column, char player) override;

private:
    Board m_board[Board::k_boardSize][Board::k_boardSize];
    int activeBoardRow = -1;
    int activeBoardColumn = -1;


};