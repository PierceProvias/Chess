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

#define EMPTY_PATH "assets/Pieces_IMG/EMPTY.png"
namespace Candy{
    class Piece
    {
    public:
        Piece(const char* p_FilePath,int p_PieceSize);
        Piece(){initVariable();}
        
        ~Piece(){}
        // functions that should use during in main Game
        void init(const char* p_FilePath,int p_PieceSize);
        void setPosition(int p_X ,int  p_Y);
        void setOrgin(int p_OffsetX , int p_OffsetY);
        void setTextureFromPath(const char* p_FilePath);
        void setPieceSize(int p_Size);

        void Log();
        void draw();

        // make it easy so all have same renderer 
        static SDL_Renderer *s_Renderer;
        static void setRenderer(SDL_Renderer* p_Renderer); 
        static SDL_Renderer* GetRenderer();
    private:
        SDL_Rect *m_PieceProperty;
        SDL_Texture* m_PieceTexture;
        bool m_CancelDraw;
        int  m_OrginOffsetX;
        int  m_OrginOffsetY;
        void initVariable();
    };
};