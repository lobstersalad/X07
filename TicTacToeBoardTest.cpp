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
	Piece test;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			test = game.getPiece(i, j);
			ASSERT_EQ(test, Blank);
		}
	}
}

TEST(TicTacToeBoardTest, checkFreshBoardTurn)
{
	TicTacToeBoard game;
//	ASSERT_EQ(game.getTurn(), X);
	ASSERT_TRUE(false);
}
