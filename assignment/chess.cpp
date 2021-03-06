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
  if(file > 'h' || file < 'a' || rank > 8 || rank < 1){
    return 0;
  }
  return &chess_board[rank-1][file-'a'];
}

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank){
  struct ChessSquare* square = get_square(chess_board, file, rank);
  return square->is_occupied;
}

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 ||chess_board[rank-1][file-'a'].is_occupied == true){
    return false;
  }
  chess_board[rank-1][file-'a'].is_occupied = true;
  chess_board[rank-1][file-'a'].piece = piece;
  return true;
}

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank){
  struct ChessPiece piece;
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 ||chess_board[rank-1][file-'a'].is_occupied == false){
    piece.type = NoPiece;
    return piece;
  }
  piece.type=chess_board[rank-1][file-'a'].piece.type;
  piece.color=chess_board[rank-1][file-'a'].piece.color;
  return piece;
}

void setup_chess_board(ChessBoard chess_board){
  struct ChessPiece white_pawn = {White, Pawn};
  struct ChessPiece white_rook = {White, Rook};
  struct ChessPiece white_knight = {White, Knight};
  struct ChessPiece white_bishop = {White, Bishop};
  struct ChessPiece white_queen = {White, Queen};
  struct ChessPiece white_king = {White, King};

  struct ChessPiece black_pawn = {Black, Pawn};
  struct ChessPiece black_rook = {Black, Rook};
  struct ChessPiece black_knight = {Black, Knight};
  struct ChessPiece black_bishop = {Black, Bishop};
  struct ChessPiece black_queen = {Black, Queen};
  struct ChessPiece black_king = {Black, King};

  init_chess_board(chess_board);
  //White Pawn(Bauer)
  for(File file = 'a'; file <= 'h'; file++){
    add_piece(chess_board, file, 2, white_pawn);
  }
  //Black Pawn(Bauer)
  for(File file = 'a'; file <= 'h'; file++){
    add_piece(chess_board, file, 7, black_pawn);
  }
  //White Rook(Turm)
  add_piece(chess_board, 'a', 1, white_rook);
  add_piece(chess_board, 'h', 1, white_rook);
  //Black Rook(Turm)
  add_piece(chess_board, 'a', 8, black_rook);
  add_piece(chess_board, 'h', 8, black_rook);

  //White Knight(Pferd)
  add_piece(chess_board, 'b', 1, white_knight);
  add_piece(chess_board, 'g', 1, white_knight);
  //Black Knight(Pferd)
  add_piece(chess_board, 'b', 8, black_knight);
  add_piece(chess_board, 'g', 8, black_knight);

  //White Bishop(Läufer)
  add_piece(chess_board, 'c', 1, white_bishop);
  add_piece(chess_board, 'f', 1, white_bishop);
  //Black Bishop(Läufer)
  add_piece(chess_board, 'c', 8, black_bishop);
  add_piece(chess_board, 'f', 8, black_bishop);

  //White Queen(Dame)
  add_piece(chess_board, 'd', 1, white_queen);
  //Black Queen(Dame)
  add_piece(chess_board, 'd', 8, black_queen);

  //White King(König)
  add_piece(chess_board, 'e', 1, white_king);
  //Black King(König)
  add_piece(chess_board, 'e', 8, black_king);
}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 ||chess_board[rank-1][file-'a'].is_occupied == false){
    return false;
  }
  chess_board[rank-1][file-'a'].is_occupied = false;
  return true;
}

bool squares_share_file(File file, Rank rank, File file1, Rank rank1){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 || file1 > 'h' || rank1 > 8 || file1 < 'a' || rank1 < 1){
    return false;
  }
  return file == file1;
}

bool squares_share_rank(File file, Rank rank, File file1, Rank rank1){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 || file1 > 'h' || rank1 > 8 || file1 < 'a' || rank1 < 1){
    return false;
  }
  return rank == rank1;
}

bool squares_share_diagonal(File file, Rank rank, File file1, Rank rank1){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 || file1 > 'h' || rank1 > 8 || file1 < 'a' || rank1 < 1){
    return false;
  }
  return (double)file-file1 && (double)rank-rank1;
}

bool squares_share_kings_move(File file, Rank rank, File file1, Rank rank1){
  if(rank-1 == rank1 && file-1 == file1){
    return true;
  }
  if(rank-1 == rank1 && file == file1){
    return true;
  }
  if(rank-1 == rank1 && file+1 == file1){
    return true;
  }
  if(rank == rank1 && file-1 == file1){
    return true;
  }
  if(rank == rank1 && file+1 == file1){
    return true;
  }
  if(rank+1 == rank1 && file-1 == file1){
    return true;
  }
  if(rank+1 == rank1 && file == file1){
    return true;
  }
  if(rank+1 == rank1 && file+1 == file1){
    return true;
  }
  return false;
}

bool squares_share_pawns_move(enum Color color, enum Move move, File file, Rank rank, File file1, Rank rank1){
  if(file > 'h' || rank > 8 || file < 'a' || rank < 1 || file1 > 'h' || rank1 > 8 || file1 < 'a' || rank1 < 1){
    return false;
  }
  if(color == White){
    if(rank > 1){
      if(move == NormalMove){
        if(rank == 2){
          return file == file1 && (rank + 1 == rank1 || rank + 2 == rank1);
        }
        else{
          return file == file1 && rank + 1 == rank1;
        }
      }
      else{
        return rank + 1 == rank1 && (file + 1 == file1 || file - 1 == file1);
      }
    }
  }
  else{
    if(rank < 8){
      if(move == NormalMove){
        if(rank == 7){
          return file == file1 && (rank - 1 == rank1 || rank - 2 == rank1);
        }
        else{
          return file == file1 && rank - 1 == rank1;
        }
      }
      else{
        return rank - 1 == rank1 && (file + 1 == file1 || file - 1 == file1);
      }
    }
  }
  return false;
}

bool squares_share_queens_move(File file, Rank rank, File file1, Rank rank1){
  return squares_share_diagonal(file,rank,file1,rank1) || file==file1 || rank==rank1;
}

bool squares_share_knights_move(File file, Rank rank, File file1, Rank rank1){
  if((rank - 2 == rank1 || rank + 2 == rank1) && (file - 1 - 'a' == file1 - 'a' || file + 1 - 'a' == file1 - 'a')){
    return true;
  }
  if((rank - 1 == rank1 || rank + 1 == rank1) && (file - 2 - 'a' == file1 - 'a' || file + 2 - 'a' == file1 - 'a')){
    return true;
  }
  return false;
}
