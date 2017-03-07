/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, checkFreshBoardIsClear)
{
	TicTacToeBoard game;
	game.clearBoard();
	char testPiece;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			testPiece = game.getPiece(i, j);
			ASSERT_EQ(testPiece, Blank);
		}
	}
}

TEST(TicTacToeBoardTest, checkFreshBoardTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	ASSERT_EQ(getTurn(game), X);
}

TEST(TicTacToeBoardTest, checkTurnXtoO)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	ASSERT_EQ(getTurn(game), O);
}

TEST(TicTacToeBoardTest, checkTurnOtoX)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	ASSERT_EQ(getTurn(game), X);
}

TEST(TicTacToeBoardTest, placePieceXEmpty)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	ASSERT_EQ(game.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceOEmpty)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	ASSERT_EQ(game.getPiece(1, 1), O);
}

TEST(TicTacToeBoardTest, placePieceEmptyEmpty)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	ASSERT_EQ(game.getPiece(1, 1), Blank);
}

TEST(TicTacToeBoardTest, placePieceXInvalid)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(5, 5);
	ASSERT_EQ(game.getPiece(5, 5), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOInvalid)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	game.placePiece(-1, -1);
	ASSERT_EQ(game.getPiece(-1, -1), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOOccupiedX)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(1, 2);
	game.placePiece(1, 2);
	ASSERT_EQ(game.getPiece(1, 2), X);
}

TEST(TicTacToeBoardTest, placePieceXOccupiedO)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(2, 0);
	game.placePiece(1, 0);
	game.placePiece(1, 0);
	ASSERT_EQ(game.getPiece(1, 0), O);
}

TEST(TicTacToeBoardTest, placePieceXInvalidTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(100, 100);
	ASSERT_EQ(getTurn(game), O);
}

TEST(TicTacToeBoardTest, placePieceOInvalidTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 2);
	game.placePiece(-50, -200);
	ASSERT_EQ(getTurn(game), X);
}

TEST(TicTacToeBoardTest, placePieceXOccupiedOTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(2, 0);
	game.placePiece(1, 1);
	game.placePiece(1, 1);
	ASSERT_EQ(getTurn(game), O);
}

TEST(TicTacToeBoardTest, placePieceOOccupiedXTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(0, 0);
	game.placePiece(0, 0);
	ASSERT_EQ(getTurn(game), X);
}

TEST(TicTacToeBoardTest, placePieceXOccupiedXTurn)
{
	TicTacToeBoard game;
	game.clearBoard();
	game.placePiece(2, 1);
	game.placePiece(1, 2);
	game.placePiece(2, 1);
	ASSERT_EQ(getTurn(game), O);
}

TEST(TicTacToeBoardTest, placePieceReturnInvalid)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(3, 3), Invalid);
}

TEST(TicTacToeBoardTest, placePieceXReturnExistingO)
{
	TicTacToeBoard game;
	game.placePiece(2, 0);
	game.placePiece(1, 2);
	ASSERT_EQ(game.placePiece(1, 2), O);
}

TEST(TicTacToeBoardTest, placePieceOReturnExistingX)
{
	TicTacToeBoard game;
	game.placePiece(1, 1);
	ASSERT_EQ(game.placePiece(1, 1), X);
}

TEST(TicTacToeBoardTest, getPieceReturnBlank)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.getPiece(1, 1), Blank);
}

TEST(TicTacToeBoardTest, checkRow0WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(0, 1);
	game.placePiece(1, 1);
	game.placePiece(0, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkRow1WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(1, 0);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(0, 0);
	game.placePiece(1, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkRow2WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(2, 0);
	game.placePiece(0, 0);
	game.placePiece(2, 1);
	game.placePiece(0, 0);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkRow0WinnerO)
{
	TicTacToeBoard game;
	game.placePiece(1, 1);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(0, 1);
	game.placePiece(1, 1);
	game.placePiece(0, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkRow1WinnerO)
{

	TicTacToeBoard game;
	game.placePiece(0, 1);
	game.placePiece(1, 0);
	game.placePiece(0, 1);
	game.placePiece(1, 1);
	game.placePiece(0, 1);
	game.placePiece(1, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkRow2Winner0)
{

	TicTacToeBoard game;
	game.placePiece(1, 1);
	game.placePiece(2, 0);
	game.placePiece(1, 1);
	game.placePiece(2, 1);
	game.placePiece(1, 1);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkColumn0WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(0, 0);
	game.placePiece(0, 1);
	game.placePiece(1, 0);
	game.placePiece(0, 1);
	game.placePiece(2, 0);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkColumn1WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(0, 1);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(0, 0);
	game.placePiece(2, 1);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkColumn2WinnerX)
{
	TicTacToeBoard game;
	game.placePiece(0, 2);
	game.placePiece(0, 1);
	game.placePiece(1, 2);
	game.placePiece(0, 1);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkColumn0WinnerO)
{
	TicTacToeBoard game;
	game.placePiece(1, 1);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(1, 0);
	game.placePiece(5, 5);
	game.placePiece(2, 0);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkColumn1WinnerO)
{
	TicTacToeBoard game;
	game.placePiece(1, 0);
	game.placePiece(0, 1);
	game.placePiece(1, 0);
	game.placePiece(1, 1);
	game.placePiece(5, 5);
	game.placePiece(2, 1);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkColumn2WinnerO)
{
	TicTacToeBoard game;
	game.placePiece(1, 1);
	game.placePiece(0, 2);
	game.placePiece(1, 1);
	game.placePiece(1, 2);
	game.placePiece(5, 5);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkLowHighDiagWinnerX)
{
	TicTacToeBoard game;
	game.placePiece(0, 0);
	game.placePiece(0, 1);
	game.placePiece(1, 1);
	game.placePiece(1, 1);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkLowHighDiagWinnerO)
{
	TicTacToeBoard game;
	game.placePiece(2, 0);
	game.placePiece(0, 0);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(2, 0);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkHighLowDiagWinnerX)
{
	TicTacToeBoard game;
	game.placePiece(2, 0);
	game.placePiece(0, 0);
	game.placePiece(1, 1);
	game.placePiece(1, 1);
	game.placePiece(0, 2);
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, checkHighLowDiagWinnerO)
{
	TicTacToeBoard game;
	game.placePiece(5, 5);
	game.placePiece(2, 0);
	game.placePiece(2, 0);
	game.placePiece(1, 1);
	game.placePiece(1, 1);
	game.placePiece(0, 2);
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, checkFullBoardNoWin)
{
	TicTacToeBoard game;
	game.placePiece(0, 1);
	game.placePiece(0, 0);
	game.placePiece(1, 0);
	game.placePiece(0, 2);
	game.placePiece(1, 2);
	game.placePiece(1, 1);
	game.placePiece(2, 0);
	game.placePiece(2, 1);
	game.placePiece(2, 2);
	ASSERT_EQ(game.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, checkGameNotOver)
{
	TicTacToeBoard game;
	game.placePiece(1, 1);
	ASSERT_EQ(game.getWinner(), Invalid);
}
