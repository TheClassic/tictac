#include "board.h"

Board::Board()
{
    spaces[0][0] = ' ';
    spaces[0][1] = ' ';
    spaces[0][2] = ' ';
    spaces[1][0] = ' ';
    spaces[1][1] = ' ';
    spaces[1][2] = ' ';
    spaces[2][0] = ' ';
    spaces[2][1] = ' ';
    spaces[2][2] = ' ';
}

/// returns true for a win
Board::eResult Board::play(int row, int column, char player)
{
    spaces[row][column] = player;
    if (wonBy == ' ')
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
    for (int i = 0; i <= 3; ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {
            if (getSymbol(i, j) == Board::k_emptySpace)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::detectWin() const
{
    if ((spaces[0][0] != ' ' && spaces[0][0] == spaces[0][1] && spaces[0][0] == spaces[0][2]) ||
        (spaces[1][0] != ' ' && spaces[1][0] == spaces[1][1] && spaces[1][0] == spaces[1][2]) ||
        (spaces[2][0] != ' ' && spaces[2][0] == spaces[2][1] && spaces[2][0] == spaces[2][2]) ||
        (spaces[0][0] != ' ' && spaces[0][0] == spaces[1][0] && spaces[0][0] == spaces[2][0]) ||
        (spaces[0][1] != ' ' && spaces[0][1] == spaces[1][1] && spaces[0][1] == spaces[2][1]) ||
        (spaces[0][2] != ' ' && spaces[0][2] == spaces[1][2] && spaces[0][2] == spaces[2][2]) ||
        (spaces[0][0] != ' ' && spaces[0][0] == spaces[1][1] && spaces[0][0] == spaces[2][2]) ||
        (spaces[0][2] != ' ' && spaces[0][2] == spaces[1][1] && spaces[0][2] == spaces[2][0]))
    {
        return true;
    }
    return false;

}

char Board::getSymbol(int row, int column) const
{
    return spaces[row][column];
}