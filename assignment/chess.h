/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 6
 * Title:			chess.h
 * Author:			A. Handstanger
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */

enum Color {White, Black};
enum PieceType{
  PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
};

struct ChessPiece{
  enum Color color;
  enum PieceType type;
};

struct ChessSquare{
  bool is_occupied;
  struct ChessPiece piece;
};

typedef ChessSquare ChessBoard[8] [8];

bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

void init_chess_board(ChessBoard chess_board);
