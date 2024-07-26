#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "pieces.h"
#include "board.h"
#include <array>
namespace Candy {
    class PiecesManger {
    public:

        PiecesManger(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManger(){}

        void drawPieces();
        void resetPieces();
        void updateBoardPieces(int* p_MouseX,int* p_MouseY);
        void isPieceSelect(bool p_state,int* p_MouseX,int* p_MouseY);

    public:

        void setSize(int p_PieceSize);
        std::string GameOver();
        Player getPlayer() const ;

    private:

        void init();
        void initDefaultBoard();
        bool isBlack();
        void addPiece(const char* p_FilePath, int row, int col);
        void CalculatePieces();


    private:

        SDL_Renderer* m_Renderer;
        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;
        bool m_IsLastBlackMove = 1;
        Piece** m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };
}

