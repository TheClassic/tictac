#include <gtest/gtest.h>
#include <Tictac/board.h>
#include "Tictac/ultimateBoardReader.h"


namespace BoardReaderTests{

    // reads a file with a board filled with " " chars, except for the center square which has a number between "1-9"
    TEST(BoardReaderTests, readBoard)
    {
        const auto& ultBoard = UltimateBoardReader::CreateBoard("..\\TicTacTest\\data\\ultimateBoard.txt");

        const int centerSpot = 1;

        for (int x = 0; x < Board::k_boardSize; ++x)
        {
            for (int y = 0; y < Board::k_boardSize; ++y)
            {
                const auto& board = ultBoard.GetBoard(y, x);

                for (int i = 0; i < Board::k_boardSize; ++i)
                {
                    for (int j = 0; j < Board::k_boardSize; ++j)
                    {
                        const auto& spot = board.getSymbol(i, j);
                        if (i == 1 && j == 1)
                        {
                            std::string str;
                            str += spot;
                            EXPECT_EQ(y*Board::k_boardSize + x + 1, std::atoi(str.c_str()));
                        }
                        else
                        {
                            EXPECT_EQ(' ', spot);
                        }
                    }
                }
            }
        }


    }
}