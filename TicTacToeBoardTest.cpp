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
		virtual void TearDown(){} //clean up after each test, (fore destructor) 
};

//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, boardIsBlank)
{
	TicTacToeBoard tb;
	//ASSERT_TRUE(tb.placePiece(1,1) == X);
	ASSERT_TRUE(tb.getPiece(0,0) == Blank);
}

TEST(TicTacToeBoardTest, canSwitchTurn)
{
	TicTacToeBoard tb;
	tb.placePiece(1,1);
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getPiece(0,0) == O);
}

TEST(TicTacToeBoardTest, horizontalMiddleWin)
{
	TicTacToeBoard tb;
	tb.placePiece(1,1);
	tb.placePiece(0,0);
	tb.placePiece(1,0);
	tb.placePiece(0,1);
	tb.placePiece(1,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, DiagnolDownWin)
{
	TicTacToeBoard tb;
	tb.placePiece(1,1);
	tb.placePiece(0,0);
	tb.placePiece(0,2);
	tb.placePiece(0,1);
	tb.placePiece(2,0);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, noWinner)
{
	TicTacToeBoard tb;
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(0,2);
	tb.placePiece(2,0);
	tb.placePiece(2,1);
	tb.placePiece(2,2);
	tb.placePiece(1,0);
	tb.placePiece(0,1);
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getWinner() == Blank);
}