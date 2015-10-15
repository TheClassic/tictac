#include <gtest/gtest.h>
#include <Tictac/board.h>

namespace BoardTests{

    TEST(BoardTests, WinDetectionSimple)
    {
        const auto noWin = false;
        const auto Win = true;

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
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    std::cin.get();
}