#include "ticTacSolver.h"
#include <cstdint>

TicTacSolver::TicTacSolver(char desiredWinner, char desiredLoser)
    : m_desiredWinner(desiredWinner),
    m_desiredLoser(desiredLoser)
{}


char TicTacSolver::getOpposingSymbol(char symbol) const
{
    if (symbol == m_desiredWinner)
        return m_desiredLoser;
    else
        return m_desiredWinner;
}

// results need more info in order to be invertible
TicTacSolver::Results TicTacSolver::invertResults(Results& result) const
{
    // swap wins and losses
    return Results(std::get<2>(result), std::get<1>(result), std::get<0>(result));
}

TicTacSolver::Results TicTacSolver::testMove(const Board& board, const Move& move, char symbol) const
{
    // doesn't currently detect tie
    Board newBoard(board);
    if (newBoard.play(move.first, move.second, symbol))
        return (symbol == m_desiredWinner) ? Results(1, 0, 0) : Results(0, 0, 1);
    else
    {
        auto answer = determineBestMove(newBoard, getOpposingSymbol(symbol));
        return (symbol == m_desiredWinner) ? invertResults(answer.second) : answer.second; // if we came in here as the desiredWinner we're finding the opponents bestMove and need to invert the results
    }
}


std::pair<TicTacSolver::Move, TicTacSolver::Results> TicTacSolver::determineBestMove(const Board& board, char symbol) const
{
    Results bestResults(INT_MIN, 0, 0);
    Move bestMove;
    for (int i = 0; i <= 3; ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {
            if (board.getSymbol(i, j) == Board::k_emptySpace)
            {
                Move currentMove(i, j);
                auto result = testMove(board, currentMove, symbol);
                if (std::get<0>(result) < std::get<0>(bestResults) || std::get<0>(result) == std::get<0>(bestResults) && std::get<1>(result) < std::get<1>(result))
                {
                    ///\todo need to create a comparison for results that considers percentages, in order to detect an instant win, and not just most possible wins
                    bestMove = currentMove;
                    bestResults = result;
                }
            }

        }
    }
   
    return std::pair<TicTacSolver::Move, TicTacSolver::Results>(bestMove, bestResults);
}