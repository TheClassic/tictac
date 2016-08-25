#include "gameManager.h"

const IPlayer* GameManager::getCurrentPlayer() const
{
    return nextPlayer;
}


bool GameManager::isValidMove(IPlayer* player, int row, int column) const
{
//    if (player != getCurrentPlayer())
//        return false;
    if (board.getSymbol(row, column) != Board::k_emptySpace)
        return false;
    return true;
}