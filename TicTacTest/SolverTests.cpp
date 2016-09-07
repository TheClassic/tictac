#include <gtest/gtest.h>
#include <Tictac/board.h>
#include <Tictac/ticTacSolver.h>

using Results = TicTacSolver::Results;

namespace SolverTests{

    TEST(SolverTests, CompareResults)
    {
        TicTacSolver solver('x', 'o');

        EXPECT_TRUE(solver.compareResults(Results(1, 0, 0), Results(0, 1, 0)));
        EXPECT_TRUE(solver.compareResults(Results(0, 1, 0), Results(0, 0, 1)));
        EXPECT_TRUE(solver.compareResults(Results(1, 0, 0), Results(0, 0, 1)));
        EXPECT_TRUE(solver.compareResults(Results(1, 0, 0), Results(0, 1, 1)));
        EXPECT_TRUE(solver.compareResults(Results(1, 0, 0), Results(0, 55, 0)));
        EXPECT_TRUE(solver.compareResults(Results(0, 1, 0), Results(0, 2, 1)));
        EXPECT_TRUE(solver.compareResults(Results(0, 8, 1), Results(0, 1, 1)));

        /// this is a real world case from the bestDefense test that based on the current implementation of the solver, we would expect to pass
        EXPECT_TRUE(solver.compareResults(Results(8, 31, 12), Results(10, 6, 11)));
        EXPECT_FALSE(solver.compareResults(Results(10, 10, 11), Results(8, 33, 12)));

        EXPECT_FALSE(solver.compareResults(Results(4, 0, 1), Results(1, 1, 0)));
    }

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

    TEST(SolverTests, diags)
    {
        Board board;
        TicTacSolver solver('x', 'o');
        auto resultsCenter = solver.testMove(board, TicTacSolver::Move(1, 1), 'x');

        auto resultsCorner = solver.testMove(board, TicTacSolver::Move(0, 0), 'x');
        
        int jk32 = 23;
    }

    TEST(SolverTests, bestDefense)
    {
        Board board;

        board.play(0, 1, 'o');
        board.play(1, 1, 'o');

        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(board, 'x');
        
        TicTacSolver::Move expectedBestMove(2, 1);

        EXPECT_EQ(expectedBestMove, bestMove.first);
    }
    
    TEST(SolverTests, StartMove)
    {
        Board board;

        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(board, 'x');

        TicTacSolver::Move expectedBestMove(0, 0);

        EXPECT_EQ(expectedBestMove, bestMove.first);
    }

    TEST(SolverTests, twoPossibleMoves)
    {
        Board board;

        board.play(0, 0, 'o');
        board.play(1, 0, 'o');
        
        board.play(0, 1, 'x');
        board.play(1, 1, 'o');
        board.play(2, 1, 'x');

        board.play(0, 2, 'x');
        board.play(1, 2, 'x');

        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(board, 'x');

        TicTacSolver::Move expectedBestMove(2, 2);

        EXPECT_EQ(expectedBestMove, bestMove.first);
    }

}