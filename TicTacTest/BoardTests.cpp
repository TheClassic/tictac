#include <gtest/gtest.h>
#include <Tictac/board.h>

namespace BoardTests{

    TEST(BoardTests, WinDetectionSimple)
    {
        const auto noWin = Board::none;
        const auto Win = Board::win;

        Board board;

        auto result = board.play(0, 0, 'x');
        EXPECT_EQ(noWin, result);

        result = board.play(1, 1, 'o');
        EXPECT_EQ(noWin, result);

        result = board.play(2, 2, 'x');
        EXPECT_EQ(noWin, result);

        result = board.play(0, 1, 'x');
        EXPECT_EQ(noWin, result);

        result = board.play(0, 2, 'x');
        EXPECT_EQ(Win, result);

        Board newBoard;
        board.play(0, 0, 'x');
        board.play(0, 1, 'o');
        board.play(0, 2, 'x');
        board.play(1, 0, 'o');
        board.play(1, 1, 'x');
        board.play(1, 2, 'o');
        board.play(2, 0, 'x');
        board.play(2, 1, 'o');
        result = board.play(2, 2, 'x');

        EXPECT_EQ(Board::tie, result);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    std::cin.get();
}