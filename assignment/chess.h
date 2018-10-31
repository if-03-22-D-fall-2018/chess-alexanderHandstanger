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
  Pawn, Rook, Knight, Bishop, Queen, King
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
typedef int Rank;
typedef int File;
typedef ChessSquare Chessboard[8] [8];

bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

void init_chess_board(ChessBoard chess_board);

struct ChessSquare* get_square(Chessboard chess_board, File file, Rank rank);

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank);

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece);

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank);

void setup_chess_board(ChessBoard chess_board);

bool remove_piece(ChessBoard chess_board, File file, Rank rank);

bool squares_share_file(File file, Rank rank, File file1, Rank rank1);

bool squares_share_rank(File file, Rank rank, File file1, Rank rank1);
