#pragma once
#include <SDL2/SDL.h>

#define BLACK_PAWN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Pawn_Black.png"
#define WHITE_PAWN_PATH "/Users/pierce/Documents/programming/projects/chess/assets/pieces/Pawn_White.png"

//#define IMG "ai-generated-8707694_1280.png"
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