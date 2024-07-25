#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "pieces_def.h"
#include <array>

namespace Candy{
    class Board {
    public:
        Board(int p_SizeBoard,SDL_Renderer* p_Renderer); 
        void drawBoard();
        void UpdatePlayer(Player p_Player); 
        int getPieceSize();
    private:
        void resetBoardColor();
        SDL_Renderer* m_Renderer;
        std::array<int, MAX_PIECES_SPACE  > m_Pieces;
        std::array<std::array<SDL_Color, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardColor;
        //Player m_Player;
        int m_PiecesSize = 75;
        int m_BoardSize;
    };
};