/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 6
 * Title:			chess.c
 * Author:			A. Handstanger
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
#include "chess.h"
#include <stdio.h>
#include <stdbool.h>
#include "general.h"

bool is_piece(struct ChessPiece cp, enum Color color, enum PieceType type){
  if(cp.color == color && cp.type == type){
    return true;
  }
  return false;
}

void init_chess_board(ChessBoard chess_board){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      chess_board[i][j].is_occupied = false;
    }
  }
}

struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank){
  if((file > 'h' || file < 'a') && (rank > 8 || rank < 1)){
    return 0;
  }
  return &chess_board[rank][file];;
}

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank){

}

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece){

}

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank){

}

void setup_chess_board(ChessBoard chess_board){

}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){

}

bool squares_share_file(File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_rank(File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_diagonal(File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_kings_move(File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_pawns_move(enum Color color, enum Move NormalMove, File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_queens_move(File file, Rank rank, File file1, Rank rank1){

}

bool squares_share_knights_move(File file, Rank rank, File file1, Rank rank1){

}
