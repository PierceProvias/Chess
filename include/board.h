#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "pieces_def.h"
#include "moves_def.h"
#include <array>

namespace Candy{
    class Board {
    public:
        Board(int p_SizeBoard,SDL_Renderer* p_Renderer); // i will only drawSquare     
        void drawBoard();
        void UpdatePlayer(Player p_Player); // handle player pieces hints
        int getPieceSize() const ;
    private:
        void resetBoardColor();
        void SetHighlight(unsigned const int row, unsigned const int col);
        void showHints(Player p_Player);

        void WhitePawnHint( PiecePosition StartPos);
        void BlackPawnHint(const PiecePosition StartPos);
        void KingHint(const PiecePosition StartPos);
        void QueenHint(const PiecePosition StartPos);
        void KnightHint(const PiecePosition StartPos);
        void RookHint(const PiecePosition StartPos);
        void BishopHint(const PiecePosition StartPos);
       
        SDL_Renderer* m_Renderer;
        std::array<int, MAX_PIECES_SPACE  > m_Pieces;
        std::array<std::array<SDL_Color, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardColor;

        int m_PiecesSize = 75;
        int m_BoardSize;
    };
};