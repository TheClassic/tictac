#pragma once
#include <array>

class Board
{
public:
    const static char k_emptySpace = ' ';
    const static int k_boardSize = 3;

    enum eResult { win, tie, none};

    Board();
    eResult play(int row, int column, char player);
    char getSymbol(int row, int column) const;
    bool boardFull() const;

private:
    bool detectWin() const;

    char spaces[k_boardSize][k_boardSize];
    char wonBy = k_emptySpace;
};