#pragma once

#include "board.h"


///TODO we should make a Board interface
class UltimateBoard : public Board
{
public:
    virtual std::unique_ptr<Board> Clone() const override;

    //Board& GetBoard(int row, int column);
    const Board& GetBoard(int row, int column) const;

    void ChooseInitialBoard(int row, int column);
    virtual eResult play(int row, int column, char player) override;
    char UltimateBoard::getSymbol(int row, int column) const override;


private:
    Board m_board[Board::k_boardSize][Board::k_boardSize];
    int activeBoardRow = -1;
    int activeBoardColumn = -1;


};