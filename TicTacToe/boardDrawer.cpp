
#include "boardDrawer.h"
#include "..\TicTac\board.h"
#include <iostream>

void DrawBoard(const Board& board)
{
    for (int i = 0; i < Board::k_boardSize; ++i)
    {
        for (int j = 0; j < Board::k_boardSize; ++j)
        {
            char boardSymbol = board.getSymbol(i, j);
            char printSymbol = Board::k_emptySpace == board.getSymbol(i, j) ? '-' : board.getSymbol(i, j);
            std::cout << printSymbol << " ";
        }
        std::cout << std::endl;
    }
}