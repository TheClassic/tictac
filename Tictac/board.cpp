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
bool Board::play(int row, int column, char player)
{
    spaces[row][column] = player;
    if (wonBy == ' ')
    {
        bool won = detectWin();
        if (won)
        {
            wonBy = player;
            return true;
        }
    }

    return false;
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