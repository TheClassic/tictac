#include "ultimateBoard.h"

std::unique_ptr<Board> UltimateBoard::Clone() const
{
    return std::unique_ptr<Board>(new UltimateBoard(*this));
}

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
    if (Board::getSymbol(activeBoardRow, activeBoardColumn) == k_emptySpace)
    {
        if (state == win)
            overallState = Board::play(activeBoardRow, activeBoardColumn, player);
        else if (state == tie)
            overallState = Board::play(activeBoardRow, activeBoardColumn, '.');
    }
    
    activeBoardRow = row;
    activeBoardColumn = column;

    //TODO handle board full state

    return overallState;
}

char UltimateBoard::getSymbol(int row, int column) const
{
    return m_board[activeBoardRow][activeBoardColumn].getSymbol(row, column);

}