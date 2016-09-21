#include "board.h"

Board::Board()
{
    spaces[0][0] = k_emptySpace;
    spaces[0][1] = k_emptySpace;
    spaces[0][2] = k_emptySpace;
    spaces[1][0] = k_emptySpace;
    spaces[1][1] = k_emptySpace;
    spaces[1][2] = k_emptySpace;
    spaces[2][0] = k_emptySpace;
    spaces[2][1] = k_emptySpace;
    spaces[2][2] = k_emptySpace;
}

std::unique_ptr<Board> Board::Clone() const
{
    return std::unique_ptr<Board>(new Board(*this));
}

/// returns true for a win
Board::eResult Board::play(int row, int column, char player)
{
    spaces[row][column] = player;
    if (wonBy == k_emptySpace)
    {
        bool won = detectWin();
        if (won)
        {
            wonBy = player;
            return win;
        }
    }

    if (boardFull())
        return tie;

    return none;
}

bool Board::boardFull() const
{
    for (int i = 0; i < k_boardSize; ++i)
    {
        for (int j = 0; j < k_boardSize; ++j)
        {
            if (getSymbol(i, j) == k_emptySpace)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::detectWin() const
{
    if ((spaces[0][0] != k_emptySpace && spaces[0][0] == spaces[0][1] && spaces[0][0] == spaces[0][2]) ||
        (spaces[1][0] != k_emptySpace && spaces[1][0] == spaces[1][1] && spaces[1][0] == spaces[1][2]) ||
        (spaces[2][0] != k_emptySpace && spaces[2][0] == spaces[2][1] && spaces[2][0] == spaces[2][2]) ||
        (spaces[0][0] != k_emptySpace && spaces[0][0] == spaces[1][0] && spaces[0][0] == spaces[2][0]) ||
        (spaces[0][1] != k_emptySpace && spaces[0][1] == spaces[1][1] && spaces[0][1] == spaces[2][1]) ||
        (spaces[0][2] != k_emptySpace && spaces[0][2] == spaces[1][2] && spaces[0][2] == spaces[2][2]) ||
        (spaces[0][0] != k_emptySpace && spaces[0][0] == spaces[1][1] && spaces[0][0] == spaces[2][2]) ||
        (spaces[0][2] != k_emptySpace && spaces[0][2] == spaces[1][1] && spaces[0][2] == spaces[2][0]))
    {
        return true;
    }
    return false;

}

char Board::getSymbol(int row, int column) const
{
    return spaces[row][column];
}