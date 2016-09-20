#include "ultimateBoardReader.h"
#include <fstream>

namespace UltimateBoardReader
{
    UltimateBoard CreateBoard(const char * filename)
    {
        std::ifstream in(filename);
        UltimateBoard ultBoard;

        const char alternateEmptySpot = '_'; // istream won't read whitespace, so we need an alternate for that file i/o

        char c;
        in >> c;
        int count = 0;

        const int boardSizeCubed = Board::k_boardSize*Board::k_boardSize*Board::k_boardSize;
        while (!in.eof() && in.good())
        {
            int boardRow = count / boardSizeCubed;
            int boardColumn = count % (Board::k_boardSize * Board::k_boardSize) / Board::k_boardSize;

            //int boardStartSpot = boardColumn*Board::k_boardSize + boardRow*boardSizeCubed;

            int row = count / (Board::k_boardSize * Board::k_boardSize) - boardRow*Board::k_boardSize;
            int column = count % (Board::k_boardSize * Board::k_boardSize) - boardColumn*Board::k_boardSize;

            ultBoard.ChooseInitialBoard(boardRow, boardColumn);
            if (c == alternateEmptySpot)
                c = Board::k_emptySpace;
            ultBoard.play(row, column, c);

            in >> c;
            ++count;
        }
        return ultBoard;
    }

}