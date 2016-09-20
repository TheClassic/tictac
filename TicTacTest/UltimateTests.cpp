#include <gtest/gtest.h>
#include <Tictac/ultimateBoard.h>
#include <Tictac/ultimateBoardReader.h>
#include <Tictac/ticTacSolver.h>

using Results = TicTacSolver::Results;

namespace SolverTests{

    TEST(SolverTests, UltimateOnePlayWin)
    {
        auto& ultBoard = UltimateBoardReader::CreateBoard("..\\TicTacTest\\data\\ultimateBoardWinnable.txt");

        ultBoard.ChooseInitialBoard(2, 2);

        TicTacSolver solver('x', 'o');
        auto bestMove = solver.determineBestMove(ultBoard, 'x');

        TicTacSolver::Move expectedBestMove(0, 1);

        EXPECT_EQ(expectedBestMove, bestMove.first);
    }


}