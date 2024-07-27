#include "../include/pieces_def.h"
#include "../include/board.h"
#include "../include/color_def.h"
#include <iostream>

static bool round(int num)
{
    return (num > 0);
}

// Move calculations
namespace Candy 
{
    void Board::WhitePawnHint()
    {
        // Illegal moves display no hints
        if (m_Player.row < 1 || m_Player.row > 6 || m_Player.col < 0 || m_Player.col > 7)
        {
            return;
        }
        // Single step hint
        if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col] == PIECES_TYPE::EMPTY && m_Player.row >= 0 && m_Player.row <= 7)
        {
            SetHighlight(m_Player.row - 1, m_Player.col);
        }
        // Double step hint
        if (m_Player.row == 6 && m_Player.row >= 0 && m_Player.row <= 7)
        {
            if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col] == PIECES_TYPE::EMPTY)
            {
                if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row - 2, m_Player.col);
                }
            }
        }


        // First diagonal (Pawn has right to capture)
        if (m_Player.col >= 1)
        {
            if ((m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 1] != PIECES_TYPE::EMPTY))
            {
                if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 1] < 0)
                {
                    showPieceHightlight(m_Player.row - 1, m_Player.col - 1);
                }
            }
        }
        // Second Diagonal (Pawn has right to capture)
        if (m_Player.col <= 6)
        {
            if ((m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 1] != PIECES_TYPE::EMPTY))
            {
                if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 1] < 0)
                {
                    showPieceHightlight(m_Player.row - 1, m_Player.col + 1);
                }
            }
        }
    } 
    void Board::BlackPawnHint() 
    {
        // Illegal moves display no hints
        if (m_Player.row < 0 || m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7)
        {
            return;
        }
        // Single pawn step hint
        if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col] == PIECES_TYPE::EMPTY && m_Player.row >= 0 && m_Player.row <= 7)
        {
            SetHighlight(m_Player.row + 1, m_Player.col);
        }
        // Two step pawn hint
        if (m_Player.row == 1 && m_Player.row >= 0 && m_Player.row <= 7)
        {
            if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col] == PIECES_TYPE::EMPTY)
            {
                if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 2, m_Player.col);
                }
            }
        }
        
        // First diagonal (Pawn has right to capture)
        if (m_Player.col >= 1)
        {
            if ((m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 1] != PIECES_TYPE::EMPTY))
            {
                if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 1] > 0)
                {
                    showPieceHightlight(m_Player.row + 1, m_Player.col - 1);
                }
            }
        }
        // Second diagonal (Pawn has right to capture)
        if (m_Player.col <= 6) 
        {
            if ((m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 1] != PIECES_TYPE::EMPTY))
            {
                if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 1] > 0)
                {
                    showPieceHightlight(m_Player.row + 1, m_Player.col + 1);
                }
            }
        }
    }
    void Board::KingHint()
    {
        int row = m_Player.row, col = m_Player.col;
        int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);
        if (row >= 0 && row <= 7 && col >= 0 && col <= 7)
        {

            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {

                    if (i >= 0 && i <= 7 && j >= 0 && j <= 7)
                    {
                        if (m_Player.BoardPieces[i][j] == PIECES_TYPE::EMPTY)
                        {
                            SetHighlight(i, j);
                        }
                        else
                        {
                            if (round(m_Player.BoardPieces[i][j]) != pieceColor)
                                showPieceHightlight(i, j);
                        }
                    }
                }
            }
        }
    } 
    void Board::QueenHint()
    {
        BishopHint();
        RookHint();
    }
    void Board::KnightHint()
    {
        if (0 <= m_Player.row && m_Player.row <= 7 || 0 <= m_Player.col && m_Player.col <= 7)
        {
            int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);

            if (m_Player.row - 1 <= 7 && m_Player.row - 1 >= 0 && m_Player.col - 2 <= 7 && m_Player.col - 2 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2]) != pieceColor && m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row - 1, m_Player.col - 2);
                else if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row - 1, m_Player.col - 2);
                }
            }
            if (m_Player.row + 1 <= 7 && m_Player.row + 1 >= 0 && m_Player.col - 2 <= 7 && m_Player.col - 2 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row + 1, m_Player.col - 2);
                else if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 1, m_Player.col - 2);
                }
            }
            if (m_Player.row + 2 <= 7 && m_Player.row + 2 >= 0 && m_Player.col - 1 <= 7 && m_Player.col - 1 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1]) != pieceColor && m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row + 2, m_Player.col - 1);
                else if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 2, m_Player.col - 1);
                }
            }
            if (m_Player.row - 2 <= 7 && m_Player.row - 2 >= 0 && m_Player.col - 1 <= 7 && m_Player.col - 1 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1]) != pieceColor && m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row - 2, m_Player.col - 1);
                else if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row - 2, m_Player.col - 1);
                }
            }
            if (m_Player.row - 2 <= 7 && m_Player.row - 2 >= 0 && m_Player.col + 1 <= 7 && m_Player.col + 1 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1]) != pieceColor && m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row - 2, m_Player.col + 1);
                else if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row - 2, m_Player.col + 1);
                }
            }
            if (m_Player.row - 1 <= 7 && m_Player.row - 1 >= 0 && m_Player.col + 2 <= 7 && m_Player.col + 2 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row - 1, m_Player.col + 2);
                else if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row - 1, m_Player.col + 2);
                }
            }
            if (m_Player.row + 1 <= 7 && m_Player.row + 1 >= 0 && m_Player.col + 2 <= 7 && m_Player.col + 2 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row + 1, m_Player.col + 2);
                else if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 1, m_Player.col + 2);
                }
            }
            if (m_Player.row + 1 <= 7 && m_Player.row + 1 >= 0 && m_Player.col + 2 <= 7 && m_Player.col + 2 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row + 1, m_Player.col + 2);
                else if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 1, m_Player.col + 2);
                }
            }
            if (m_Player.row + 2 <= 7 && m_Player.row + 2 >= 0 && m_Player.col + 1 <= 7 && m_Player.col + 1 >= 0)
            {
                if (round(m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1]) != pieceColor && m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1] != PIECES_TYPE::EMPTY)
                    showPieceHightlight(m_Player.row + 2, m_Player.col + 1);
                else if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1] == PIECES_TYPE::EMPTY)
                {
                    SetHighlight(m_Player.row + 2, m_Player.col + 1);
                }
            }
        }
    }
    void Board::RookHint() 
    {
        // Illegal moves display no hints
        if (m_Player.row < 0 || m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7)
        {
            return;
        }
        int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);

        // Hints are shown for all legal moves in the forward row
        for (int i = m_Player.row - 1; i >= 0; i--)
        {
            if (m_Player.BoardPieces[i][m_Player.col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(i, m_Player.col);
            }
            if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[i][m_Player.col]) != pieceColor)
                    showPieceHightlight(i, m_Player.col);
            }
            if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
        // Hints are shown for all legal moves in the backward row
        for (int i = m_Player.row + 1; i <= 7; i++)
        {
            if (m_Player.BoardPieces[i][m_Player.col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(i, m_Player.col);
            }
            if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[i][m_Player.col]) != pieceColor)
                    showPieceHightlight(i, m_Player.col);
            }
            if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }

        // Hints are shown for all legal moves in the column left of current column

        for (int i = m_Player.col - 1; i >= 0; i--)
        {
            if (m_Player.BoardPieces[m_Player.row][i] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(m_Player.row, i);
            }
            if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[m_Player.row][i]) != pieceColor)
                    showPieceHightlight(m_Player.row, i);
            }
            if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
        // Hints are shown for all legal moves in the column right of current column
        for (int i = m_Player.col + 1; i <= 7; i++)
        {
            if (m_Player.BoardPieces[m_Player.row][i] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(m_Player.row, i);
            }
            if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[m_Player.row][i]) != pieceColor)
                    showPieceHightlight(m_Player.row, i);
            }
            if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
    }
    void Board::BishopHint()
    {
        // Illegal moves do not display hints
        if (m_Player.row < 0 || m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7)
        {
            return;
        }
        int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);

        int _row = 0, _col = 0;
        // Hints for first diagonal forward
        _row = m_Player.row - 1;
        _col = m_Player.col - 1;
        while (_row >= 0 && _col >= 0)
        {
            if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(_row, _col);
            }
            if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                {
                    showPieceHightlight(_row, _col);
                }
                break;
            }
            _row--;
            _col--;
        }
        // Hints for first diagonal backward
        _row = m_Player.row + 1;
        _col = m_Player.col + 1;
        while (_row <= 7 && _col <= 7)
        {
            if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(_row, _col);
            }
            if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                {
                    showPieceHightlight(_row, _col);
                }
                break;
            }
            _row++;
            _col++;
        }

        // Hints for second diagonal forward
        _row = m_Player.row - 1;
        _col = m_Player.col + 1;
        while (_row >= 0 && _col <= 7)
        {
            if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(_row, _col);
            }
            if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                {
                    showPieceHightlight(_row, _col);
                }
                break;
            }
            _row--;
            _col++;
        }
        // Hints for second diagonal backward
        _row = m_Player.row + 1;
        _col = m_Player.col - 1;
        while (_row <= 7 && _col >= 0)
        {
            if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
            {
                SetHighlight(_row, _col);
            }
            if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
            {
                if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                {
                    showPieceHightlight(_row, _col);
                }
                break;
            }
            _row++;
            _col--;
        }
    }
};

namespace Candy
{
    Board::Board(int p_SizeBoard, SDL_Renderer* p_Renderer)
        : m_BoardSize(p_SizeBoard), m_Renderer(p_Renderer)
    {
        m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;
        resetBoardColor();
    }

    void Board::resetBoardColor()
    {
        for (int row = 0; row < MAX_PIECES_LINE; row++)
        {
            for (int column = 0; column < MAX_PIECES_LINE; column++)
            {
                if ((row + column) % 2 == 0)
                {
                    m_BoardColor[row][column] = { Board_COlOR1 };
                }
                else
                {
                    m_BoardColor[row][column] = { Board_COlOR2 };
                }
            }
        }
    }

    // Decides on color of tile
    void Board::SetHighlight(unsigned const int row, unsigned const int col)
    {
        if (((row + col) % 2) == 0)
        {
            m_BoardColor[row][col] = { Green_COLOR };
        }
        else
        {
            m_BoardColor[row][col] = { DarkGreen_COLOR };
        }
    }

    void Board::showHints(Player p_Player)
    {
        int _pieceType = p_Player.BoardPieces[p_Player.row][p_Player.col];
        PiecePosition _pos(p_Player.row, p_Player.col);
        switch (_pieceType)
        {
        case PIECES_TYPE::WHITE_PAWN:
            WhitePawnHint();
            break;
        case PIECES_TYPE::BLACK_PAWN:
            BlackPawnHint();
            break;

        case PIECES_TYPE::BLACK_KING:
            KingHint();
            break;
        case PIECES_TYPE::WHITE_KING:
            KingHint();
            break;
        case PIECES_TYPE::BLACK_KNIGHT:
            KnightHint();
            break;
        case PIECES_TYPE::WHITE_KNIGHT:
            KnightHint();
            break;
        case PIECES_TYPE::BLACK_ROOK:
            RookHint();
            break;
        case PIECES_TYPE::WHITE_ROOK:
            RookHint();
            break;
        case PIECES_TYPE::BLACK_BISHOP:
            BishopHint();
            break;
        case PIECES_TYPE::WHITE_BISHOP:
            BishopHint();
            break;
        case PIECES_TYPE::BLACK_QUEEN:
            QueenHint();
            break;
        case PIECES_TYPE::WHITE_QUEEN:
            QueenHint();
            break;
        }
    }
    void Board::showPieceHightlight(unsigned const int row, unsigned const int col)
    {
        m_BoardColor[row][col] = { Red_COLOR };
    }

    void Board::UpdatePlayer(Player p_Player)
    {
        m_Player = p_Player;
        if (p_Player.isSeleted == true)
        {
            showHints(p_Player);
            m_BoardColor[p_Player.row][p_Player.col] = { Red_COLOR }; // i like some like this
        }
        else
        {
            resetBoardColor();
        }
    }
    void Board::drawBoard()
    {
        for (int row = 0; row < MAX_PIECES_LINE; row++)
        {
            for (int column = 0; column < MAX_PIECES_LINE; column++)
            {
                SDL_Rect _block = {};

                _block.x = column * m_PiecesSize;
                _block.y = row * m_PiecesSize;
                _block.w = _block.h = m_PiecesSize;

                SDL_SetRenderDrawColor(m_Renderer,
                    m_BoardColor[row][column].r,
                    m_BoardColor[row][column].g,
                    m_BoardColor[row][column].b,
                    m_BoardColor[row][column].a);
                SDL_RenderFillRect(m_Renderer, &_block);
            }
        }
    }

    int Board::getPieceSize() const
    {
        return m_PiecesSize;
    }
};