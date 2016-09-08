#pragma  once

#include "IPlayer.h"
#include "board.h"

class GameManager
{
public:
    const IPlayer* getCurrentPlayer() const;
    Board& getBoard() { return board; }

    /// returns if move accepted, invalid moves will return false and have no affect
    bool submitMove(IPlayer* player, int row, int column);
    bool isValidMove(IPlayer* player, int row, int column) const;

private:
    Board board;
    IPlayer* playerX;
    IPlayer* playerO;

    IPlayer* nextPlayer;
};