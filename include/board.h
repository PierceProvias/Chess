#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
//#include <array>

namespace Candy{
    class Board {
    public:
            Board(int p_SizeBoard,SDL_Renderer* p_Renderer); 
            void drawBoard();
            int getPieceSize();
    private:
            SDL_Renderer* m_Renderer;
           // std::array<int,MAX_PIECES_SPACE  > m_Pieces;
            int m_PiecesSize = 75;
            int m_BoardSize;
    };
};