#pragma once
#include <utility>
#include <tuple>
#include "board.h"

class TicTacSolver
{
public:
    typedef std::pair<int /*row*/, int /*col*/> Move;
    typedef std::tuple<int /*wins*/, int /*ties*/, int /*losses*/> Results;

    TicTacSolver(char desiredWinner, char desiredLoser);
    std::pair<TicTacSolver::Move, TicTacSolver::Results> determineBestMove(const Board& board, char symbol) const;
    Results testMove(const Board& board, const Move& move, char symbol) const;
    Results testOpponentMoves(const Board& board, char symbol) const;
    char getOpposingSymbol(char symbol) const;
    Results invertResults(Results& result) const;

    /// returns true if the first result is better than the second
    /// this was made public solely to test it
    /// this probably belongs in another class
    bool compareResults(const Results& result1, const Results& result2) const;

private:
    char m_desiredWinner;
    char m_desiredLoser;
};