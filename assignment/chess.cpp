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
  return &chess_board[rank][file];
}

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank){
  return chess_board[rank][file].is_occupied == true;
}

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece){
  if(file >= 8 || rank >= 8 || file < 0 || rank < 0 ||chess_board[rank][file].is_occupied == true){
    return false;
  }
  chess_board[rank][file].piece = piece;
}

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank){
  struct ChessPiece piece;
  if(file >= 8 || rank >= 8 || file < 0 || rank < 0 ||chess_board[rank][file].is_occupied == false){
    piece.type = NoPiece;
    return piece;
  }
  piece.type=chess_board[rank][file].piece.type;
  piece.color=chess_board[rank][file].piece.color;
  return piece;
}

void setup_chess_board(ChessBoard chess_board){
  //White Pawn(Bauer)
  for(size_t i = 1; i < 8; i++){
    chess_board[1][i].piece.type = Pawn;
    chess_board[1][i].piece.color = White;
    chess_board[1][i].is_occupied = true;
  }
  //Black Pawn(Bauer)
  for(size_t i = 1; i < 8; i++){
    chess_board[6][i].piece.type = Pawn;
    chess_board[6][i].piece.color = Black;
    chess_board[6][i].is_occupied = true;
  }
  //White Rook(Turm)
  chess_board[0][0].piece.type = Rook;
  chess_board[0][0].piece.color = White;
  chess_board[0][0].is_occupied = true;
  chess_board[0][7].piece.type = Rook;
  chess_board[0][7].piece.color = White;
  chess_board[0][7].is_occupied = true;
  //Black Rook(Turm)
  chess_board[7][0].piece.type = Rook;
  chess_board[7][0].piece.color = Black;
  chess_board[7][0].is_occupied = true;
  chess_board[7][7].piece.type = Rook;
  chess_board[7][7].piece.color = Black;
  chess_board[7][7].is_occupied = true;

  //White Knight(Pferd)
  chess_board[0][1].piece.type = Knight;
  chess_board[0][1].piece.color = White;
  chess_board[0][1].is_occupied = true;
  chess_board[0][6].piece.type = Knight;
  chess_board[0][6].piece.color = White;
  chess_board[0][6].is_occupied = true;
  //Black Knight(Pferd)
  chess_board[7][1].piece.type = Knight;
  chess_board[7][1].piece.color = Black;
  chess_board[7][1].is_occupied = true;
  chess_board[7][6].piece.type = Knight;
  chess_board[7][6].piece.color = Black;
  chess_board[7][6].is_occupied = true;

  //White Bishop(Läufer)
  chess_board[0][2].piece.type = Bishop;
  chess_board[0][2].piece.color = White;
  chess_board[0][2].is_occupied = true;
  chess_board[0][5].piece.type = Bishop;
  chess_board[0][5].piece.color = White;
  chess_board[0][5].is_occupied = true;
  //Black Bishop(Läufer)
  chess_board[7][2].piece.type = Bishop;
  chess_board[7][2].piece.color = Black;
  chess_board[7][2].is_occupied = true;
  chess_board[7][5].piece.type = Bishop;
  chess_board[7][5].piece.color = Black;
  chess_board[7][5].is_occupied = true;

  //White Queen(Dame)
  chess_board[0][4].piece.type = Queen;
  chess_board[0][4].piece.color = White;
  chess_board[0][4].is_occupied = true;
  //Black Queen(Dame)
  chess_board[7][4].piece.type = Queen;
  chess_board[7][4].piece.color = Black;
  chess_board[7][4].is_occupied = true;

  //White King(König)
  chess_board[0][3].piece.type = King;
  chess_board[0][3].piece.color = White;
  chess_board[0][3].is_occupied = true;
  //Black King(König)
  chess_board[7][3].piece.type = King;
  chess_board[7][3].piece.color = Black;
  chess_board[7][3].is_occupied = true;
}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){
  if(file >= 8 || rank >= 8 || file < 0 || rank < 0 ||chess_board[rank][file].is_occupied == false){
    return false;
  }
  chess_board[rank][file].is_occupied = false;
  return true;
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
