#include "gameManager.h"

const IPlayer* GameManager::getCurrentPlayer()
{
    return nextPlayer;
}


bool GameManager::isValidMove(IPlayer* player, int row, int column)
{
    if (player != getCurrentPlayer())
        return false;
    if (board.getSymbol(row, column) != Board::k_emptySpace)
        return false;
    return true;
}