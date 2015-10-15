#include <gtest/gtest.h>
#include <Tictac/board.h>
#include <Tictac/ticTacSolver.h>

namespace SolverTests{

    TEST(SolverTests, OneMoveWin)
    {
        Board board;

        board.play(0, 0, 'x');
        board.play(0, 2, 'x');
        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(board, 'x');

        TicTacSolver::Move expectedBestMove(0, 1);

        EXPECT_EQ(expectedBestMove, bestMove.first);

        Board board2;
        board2.play(0, 0, 'x');
        board2.play(1, 1, 'x');

        bestMove = solver.determineBestMove(board2, 'x');

        TicTacSolver::Move expectedBestMove2(2, 2);

        EXPECT_EQ(expectedBestMove2, bestMove.first);
    }

    TEST(SolverTests, StartMove)
    {
        Board board;

        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(board, 'x');

        TicTacSolver::Move expectedBestMove(1, 1);

        EXPECT_EQ(expectedBestMove, bestMove.first);
    }
}