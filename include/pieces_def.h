#pragma once
#include <SDL2/SDL.h>

// BLACK Piece PATH

#define BLACK_PAWN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Pawn_Black.png"
#define BLACK_BISHOP_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Bishop_Black.png"
#define BLACK_KNIGHT_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Knight_Black.png"
#define BLACK_ROOK_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Rook_Black.png"
#define BLACK_QUEEN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Queen_Black.png"
#define BLACK_KING_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/King_Black.png"

// WHITE Piece PATH

#define WHITE_PAWN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Pawn_White.png"
#define WHITE_BISHOP_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Bishop_White.png"
#define WHITE_KNIGHT_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Knight_White.png"
#define WHITE_ROOK_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Rook_White.png"
#define WHITE_QUEEN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Queen_White.png"
#define WHITE_KING_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/King_White.png" 

#define EMPTY_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/empty.png" 

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