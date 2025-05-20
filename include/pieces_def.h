#pragma once
#include <SDL2/SDL.h>
#include <array>

// BLACK Piece PATH

#define BLACK_PAWN_PATH         "assets/pieces/Pawn_Black.png"
#define BLACK_BISHOP_PATH       "assets/pieces/Bishop_Black.png"
#define BLACK_KNIGHT_PATH       "assets/pieces/Knight_Black.png"
#define BLACK_ROOK_PATH         "assets/pieces/Rook_Black.png"
#define BLACK_QUEEN_PATH        "assets/pieces/Queen_Black.png"
#define BLACK_KING_PATH         "assets/pieces/King_Black.png"

// WHITE Piece PATH

#define WHITE_PAWN_PATH         "assets/pieces/Pawn_White.png"
#define WHITE_BISHOP_PATH       "assets/pieces/Bishop_White.png"
#define WHITE_KNIGHT_PATH       "assets/pieces/Knight_White.png"
#define WHITE_ROOK_PATH         "assets/pieces/Rook_White.png"
#define WHITE_QUEEN_PATH        "assets/pieces/Queen_White.png"
#define WHITE_KING_PATH         "assets/pieces/King_White.png" 

#define EMPTY_PATH              "assets/pieces/empty.png" 

namespace PIECES_TYPE {
    const int EMPTY = 0;
    const int WHITE_KING = 1;
    const int WHITE_QUEEN = 2;
    const int WHITE_BISHOP = 3;
    const int WHITE_KNIGHT = 4;
    const int WHITE_ROOK = 5;
    const int WHITE_PAWN = 6;
    const int BLACK_KING = -1;
    const int BLACK_QUEEN = -2;
    const int BLACK_BISHOP = -3;
    const int BLACK_KNIGHT = -4;
    const int BLACK_ROOK = -5;
    const int BLACK_PAWN = -6;
};


#define MAX_PIECES_SPACE 64
#define MAX_PIECES_LINE 8
#define MAX_DIFFERENT_TYPES_PIECES 16


// PLayer class for handling the player information/state sharing between functions
struct Player
{
    Player(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_BoardPiece) 
        : BoardPieces(p_BoardPiece) ,row (0),col(0),isSeleted(false)
    {}
    Player() : row(0), col(0), isSeleted(false){}

    void setPosition(int row, int col) { this->row = row; this->col = col; }
    void setBoardPieces(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> BoardPieces) { this->BoardPieces = BoardPieces; }
    void setIsSelected(bool state) { isSeleted = state; }
    
    bool isSeleted;
    int row;
    int col;
    std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> BoardPieces;
};