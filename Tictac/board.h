#pragma once
#include <array>

class Board
{
public:
    const static char k_emptySpace = ' ';

    Board();
    bool play(int row, int column, char player);
    char getSymbol(int row, int column) const;

private:
    bool detectWin() const;

    char spaces[3][3];
    char wonBy = k_emptySpace;
};