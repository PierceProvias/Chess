#include "../include/board.h"
#include "../include/pieces_def.h"
#include "../include/color_def.h"
#include <iostream>

namespace Candy{
      void Board::resetBoardColor()
      {
          for (int row = 0; row < MAX_PIECES_LINE; row++)
          {
              for (int column = 0; column < MAX_PIECES_LINE; column++)
              {
                  //SDL_Color _color = 
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
      void Board::showHints(Player p_Player)
      {
          int _pieceType = p_Player.BoardPieces[p_Player.row][p_Player.col];
          PiecePosition _pos(p_Player.row,p_Player.col);
          switch (_pieceType) 
          {
          case PIECES_TYPE::WHITE_PAWN:
              WhitePawnHint(_pos);
              break;
          case PIECES_TYPE::BLACK_PAWN:
              BlackPawnHint(_pos);
              break;
          
          case PIECES_TYPE::BLACK_KING:
              KingHint(_pos);
              break;
          case PIECES_TYPE::WHITE_KING:
              KingHint(_pos);
              break;
          case PIECES_TYPE::BLACK_KNIGHT:
              KnightHint(_pos);
              break;
          case PIECES_TYPE::WHITE_KNIGHT:
              KnightHint(_pos);
              break;
          case PIECES_TYPE::BLACK_ROOK:
              RookHint(_pos);
              break;
          case PIECES_TYPE::WHITE_ROOK:
              RookHint(_pos);
              break;
          }
      }
      // I have added 
      // 
      // white Pawn hint and lets add other also
      void Board::WhitePawnHint(PiecePosition StartPos)
      {
          int col = StartPos.Col, row = StartPos.Row;
          if (0 <= StartPos.Row && StartPos.Row <= 7)
          {
              if (StartPos.Row > 0)
              {
                  if (0 == StartPos.Col)
                  {
                      for (int i = StartPos.Col; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col > 0 && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  if (StartPos.Row == 6)
                  {
                      m_BoardColor[row - 2][col] = { Green_COLOR };
                  }
              }
          }
      }
      void Board::BlackPawnHint(const PiecePosition StartPos) // some range after 7 row fix later
      {
          int col = StartPos.Col, row = StartPos.Row;

          if (0 <= StartPos.Row && StartPos.Row <= 7)
          {
              if (StartPos.Row < 7) {
                  if (StartPos.Col == 0)
                  {
                      for (int i = StartPos.Col; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  else if (0 < StartPos.Col && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  // later add condition for enspassant


              }
              if (StartPos.Row == 1)
              {
                  m_BoardColor[row + 2][col] = { Green_COLOR };
              }
          }

      }
      // i have just box arround the king does the same 
      void Board::KingHint(const PiecePosition StartPos) {
          int row = StartPos.Row, col = StartPos.Col;

          if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {

              for (int i = row - 1; i <= row + 1; i++) {
                  for (int j = col - 1; j <= col + 1; j++) {

                      if (i >= 0 && i <= 7 && j >= 0 && j <= 7) {
                          m_BoardColor[i][j] = { Green_COLOR };
                      }
                  }
              }
          }
      }

      void Board::KnightHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col<= 7)
          {
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  m_BoardColor[StartPos.Row - 1][StartPos.Col - 2] = { Green_COLOR };
              }

              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col - 2] = { Green_COLOR };
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  m_BoardColor[StartPos.Row + 2][StartPos.Col - 1] = { Green_COLOR };
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  m_BoardColor[StartPos.Row - 2][StartPos.Col - 1] = { Green_COLOR };
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  m_BoardColor[StartPos.Row - 2][StartPos.Col + 1] = { Green_COLOR };
              }
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row - 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  m_BoardColor[StartPos.Row + 2][StartPos.Col + 1] = { Green_COLOR };
              }
          }
      }
      
      void Board::RookHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col <= 7)
          {
              for (int i = 0; i <= 7;i++)
              {
                  m_BoardColor[i][StartPos.Col] = { Green_COLOR };
                  m_BoardColor[StartPos.Row][i] = { Green_COLOR };
              }
          }
      }
    // i have decided that lets finsh one more piece like rook 

      // i Want some after you select / hold a piece shows the which move are like this ^^^

      Board::Board(int p_SizeBoard , SDL_Renderer* p_Renderer)
          :m_BoardSize(p_SizeBoard) , m_Renderer(p_Renderer)
      {
          m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;
          resetBoardColor();
      }

      void Board::drawBoard()
      {
         for (int row = 0; row < MAX_PIECES_LINE ; row++)
         {
             for (int column = 0 ; column< MAX_PIECES_LINE ; column++)
             {
                 SDL_Rect _block = {};
                   _block.x = column* m_PiecesSize;
                   _block.y = row* m_PiecesSize;
                   _block.w = _block.h = m_PiecesSize;

                  SDL_SetRenderDrawColor (m_Renderer, 
                                          m_BoardColor[row][column].r,
                                          m_BoardColor[row][column].g,
                                          m_BoardColor[row][column].b,
                                          m_BoardColor[row][column].a
                                         );
                  SDL_RenderFillRect(m_Renderer,&_block);

             }
         }

      }
      void Board::UpdatePlayer(Player p_Player)
      {
          if (p_Player.isSeleted == true) {
              showHints(p_Player);
              m_BoardColor[p_Player.row][p_Player.col] = {Red_COLOR}; // i like some like this 
          }
          else {
              resetBoardColor();
          }
      }
      int Board::getPieceSize() const
      {
          return m_PiecesSize;
      }
     
  };