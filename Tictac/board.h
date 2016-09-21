#pragma once
#include <memory>

class Board
{
public:
    const static char k_emptySpace = ' ';
    const static int k_boardSize = 3;

    enum eResult { win, tie, none};

    Board();

    virtual std::unique_ptr<Board> Clone() const;

    virtual eResult play(int row, int column, char player);
    virtual char getSymbol(int row, int column) const;
    virtual bool boardFull() const;

private:
    bool detectWin() const;

    char spaces[k_boardSize][k_boardSize];
    char wonBy = k_emptySpace;
};