#pragma  once

#include "IPlayer.h"
#include "board.h"

class GameManager
{
    const IPlayer* getCurrentPlayer() const;
    const Board* getBoard() const;

    /// returns if move accepted, invalid moves will return false and have no affect
    bool submitMove(IPlayer* player, int row, int column);
    bool isValidMove(IPlayer* player, int row, int column) const;

private:
    Board board;
    IPlayer* playerX;
    IPlayer* playerO;

    IPlayer* nextPlayer;
};