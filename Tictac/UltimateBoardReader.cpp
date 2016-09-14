#include "ultimateBoardReader.h"
#include <fstream>

namespace UltimateBoardReader
{
    UltimateBoard CreateBoard(const char * filename)
    {
        std::ifstream in(filename);
        UltimateBoard ultBoard;

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

            auto& board = ultBoard.GetBoard(boardRow, boardColumn);
            board.play(row, column, c);

            in >> c;
            ++count;
        }
        return ultBoard;
    }

}