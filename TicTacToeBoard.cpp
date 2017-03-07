#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if (turn == X) {
		turn = O;
	} else if (turn == O) {
		turn = X;
	}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	clearBoard();
	turn = X;
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = Blank;
		}
	}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if (board[row][column] == Blank) {
	  	if (turn == X) {
			board[row][column] = X;
			toggleTurn();
			return X;
		} else {
			board[row][column] = O;
			toggleTurn();
			return O;
		}
	} else if ((row > 2 || column > 2) || (row < 0 || column < 0)) {
		toggleTurn();
		return Invalid;
	} else {
		toggleTurn();
		return board[row][column];
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if ((row > 2 || column > 2) || (row < 0 || column < 0)) {
		return Invalid;
	} else if (board[row][column] == Blank) {
		return Blank;
	} else {
		return board[row][column];
	}
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	Piece winner = Invalid;
	bool full = true;
	// Check rows
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != 		    Invalid) && (board[i][0] != Blank)) {
			winner = board[i][0];
		}
	}
	// Check columns
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != 		    Invalid) && (board[0][i] != Blank)) {
			winner = board[0][i];
		}
	}
	// Check low-high diagonal
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != Invalid) 	    && (board[1][1] != Blank)) {
		winner = board[1][1];
	}
	// Check high-low diagonal
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[1][1] != Invalid)	    && (board[1][1] != Blank)) {
		winner = board[1][1];	
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == Blank) {
				full = false;
			}
		}
	}
	if ((full == true) && (winner == Invalid)) {
		return Blank;
	} else if ((full == false) && (winner == Invalid)) {
		return Invalid;
	} else {
		return winner;
	}
}

/**
 * Returns current turn, X or O.
**/
Piece getTurn(TicTacToeBoard game)
{
	return game.turn;
}
