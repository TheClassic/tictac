#include "ultimateBoard.h"

/*Board& UltimateBoard::GetBoard(int row, int column)
{
    return m_board[row][column];
}*/

const Board& UltimateBoard::GetBoard(int row, int column) const
{
    return m_board[row][column];
}

void UltimateBoard::ChooseInitialBoard(int row, int column)
{
    activeBoardColumn = column;
    activeBoardRow = row;
}

Board::eResult UltimateBoard::play(int row, int column, char player)
{
    if (activeBoardColumn < 0 || activeBoardRow < 0)
        throw;
    
    auto& activeBoard = m_board[activeBoardRow][activeBoardColumn];

    auto state = activeBoard.play(row, column, player);
    eResult overallState = Board::none;
    if (getSymbol(activeBoardRow, activeBoardColumn) == k_emptySpace)
    {
        if (state == win)
            overallState = Board::play(activeBoardRow, activeBoardColumn, player);
        else if (state == tie)
            overallState = Board::play(activeBoardRow, activeBoardColumn, '.');
    }

    return overallState;

}