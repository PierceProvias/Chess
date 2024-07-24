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

namespace Candy{
    class Piece
    {
    public:
        Piece(SDL_Renderer* p_Renderer,const char* p_FilePath,int p_PieceSize);
        ~Piece();
        void setPosition(int p_X ,int  p_Y);
        void draw();
    private:
        SDL_Renderer *m_Renderer; // don't know the error for 
        SDL_Rect *m_PieceProperty; // don't know
        SDL_Texture* m_PieceTexture;
        void init();
    };
};