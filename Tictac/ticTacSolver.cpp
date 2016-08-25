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

/// tests all possible opponent moves
TicTacSolver::Results TicTacSolver::testOpponentMoves(const Board& board, char symbol) const
{
    Results results(0,1,0);
    for (int i = 0; i < Board::k_boardSize; ++i)
    {
        for (int j = 0; j < Board::k_boardSize; ++j)
        {
            if (board.getSymbol(i, j) == Board::k_emptySpace)
            {
                Move currentMove(i, j);
                Results result = testMove(board, currentMove, symbol);
                std::get<0>(results) += std::get<0>(result);
                std::get<1>(results) += std::get<1>(result);
                std::get<2>(results) += std::get<2>(result);
            }
        }
    }
    return results;
}

/// tests a move and returns the results for it
TicTacSolver::Results TicTacSolver::testMove(const Board& board, const Move& move, char symbol) const
{
    Board newBoard(board);
    Board::eResult result = newBoard.play(move.first, move.second, symbol);
    if (Board::eResult::win == result)
        return (symbol == m_desiredWinner) ? Results(1, 0, 0) : Results(0, 0, 1);
    else if (Board::eResult::tie == result)
        return Results(0, 1, 0);
    else
    {
        char nextSymbol = getOpposingSymbol(symbol);
        if (nextSymbol == m_desiredWinner)
            return determineBestMove(newBoard, nextSymbol).second;
        else
            return testOpponentMoves(newBoard, nextSymbol);
    }
}

bool TicTacSolver::compareResults(const Results& result1, const Results& result2) const
{
    int result1Total = std::get<0>(result1) + std::get<1>(result1) + std::get<2>(result1);
    int result2Total = std::get<0>(result2) + std::get<1>(result2) + std::get<2>(result2);

    double winPercentage1 = std::get<0>(result1) / result1Total;
    double winPercentage2 = std::get<0>(result2) / result2Total;
    
    if (winPercentage1 > winPercentage2)
        return true;
    else if (winPercentage1 == winPercentage2)
    {
        double tiePercentage1 = std::get<1>(result1) / result1Total;
        double tiePercentage2 = std::get<1>(result2) / result2Total;

        if (tiePercentage1 > tiePercentage2)
            return true;
    }

    return false;
}


std::pair<TicTacSolver::Move, TicTacSolver::Results> TicTacSolver::determineBestMove(const Board& board, char symbol) const
{
    Results bestResults((INT_MIN + 1) / 2, (INT_MIN + 1) / 2, 0);
    Move bestMove;
    const Results instantWin(1, 0, 0);
    for (int i = 0; i < Board::k_boardSize; ++i)
    {
        for (int j = 0; j < Board::k_boardSize; ++j)
        {
            if (board.getSymbol(i, j) == Board::k_emptySpace)
            {
                Move currentMove(i, j);
                auto result = testMove(board, currentMove, symbol);
                if (compareResults(result, bestResults))
                {
                    bestMove = currentMove;
                    bestResults = result;
                    if (bestResults == instantWin)
                        return std::pair<TicTacSolver::Move, TicTacSolver::Results>(bestMove, bestResults);
                }
            }

        }
    }
   
    return std::pair<TicTacSolver::Move, TicTacSolver::Results>(bestMove, bestResults);
}