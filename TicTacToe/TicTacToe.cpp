// TicTacToe.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include "boardDrawer.h"
#include "..\TicTac\board.h"
#include "..\TicTac\ticTacSolver.h"
#include "..\TicTac\gameManager.h"


bool playerMove(GameManager& gm)
{
    DrawBoard(gm.getBoard());

invalidMove:
    std::cout << "You are 'x', specify your move.\nRow: ";
    int row;
    std::cin >> row;
    std::cout << "Column: ";
    int column;
    std::cin >> column;

    if (!gm.isValidMove(nullptr, row, column))
    {
        std::cout << "Invalid move, try again." << std::endl;
        goto invalidMove;
    }

    auto result = gm.getBoard().play(row, column, 'x');
    if (result == Board::win)
    {
        std::cout << "Congratulations, you won";
        return false;
    }
    else if(result == Board::tie)
    {
        std::cout << "Tie game";
        return false;
    }
    return true;
}


bool computerMove(GameManager& gm)
{
    TicTacSolver solver('o', 'x');
    auto bestMove = solver.determineBestMove(gm.getBoard(), 'o');
    auto result = gm.getBoard().play(bestMove.first.first, bestMove.first.second, 'o');
    if (result == Board::win)
    {
        std::cout << "You lost!";
        return false;
    }
    else if(result == Board::tie)
    {
        std::cout << "Tie game";
        return false;
    }
    return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
    GameManager gm;
    Board& board = gm.getBoard();

    std::cout << "Play first (1) or second (2)?: ";
    int choice;
    std::cin >> choice;
    bool bPlayerFirst = false;
    if (choice == 1)
    {
        bPlayerFirst = true;
    }
 

    while (!board.boardFull())
    {
        if (bPlayerFirst)
        {
            if (!playerMove(gm) || board.boardFull())
                break;
            if (!computerMove(gm) || board.boardFull())
                break;
        }
        else
        {
            if (!computerMove(gm) || board.boardFull())
                break;
            if (!playerMove(gm) || board.boardFull())
                break;
        }
    }


	return 0;
}

