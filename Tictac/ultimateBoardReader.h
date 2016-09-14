#pragma once

#include "ultimateBoard.h"

namespace UltimateBoardReader
{
    /// reads from file and creates a board given a file containing a Board::k_boardSize by Board::k_boardSize grid of characters
    UltimateBoard CreateBoard(const char * filename);

}