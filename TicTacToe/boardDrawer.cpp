
#include "boardDrawer.h"
#include "..\TicTac\board.h"
#include <iostream>

void DrawBoard(const Board& board)
{
    for (int i = 0; i < Board::k_boardSize; ++i)
    {
        for (int j = 0; j < Board::k_boardSize; ++j)
        {
            std::cout << board.getSymbol(i, j) << " ";
        }
        std::cout << std::endl;
    }
}