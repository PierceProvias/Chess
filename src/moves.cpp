#include "../include/moves.h"
#include "../include/pieces_def.h"
#include <iostream> 

bool isBlack(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 > p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}
bool isWhite(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 < p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}

// TODO: Add pawn promotion
#pragma region Pawn
bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (0 <= StartPos.Row && StartPos.Row <= 7)
    {
        if (StartPos.Row + 1 == EndPos.Row) {
            if (0 == StartPos.Col)
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (EndPos.Col > 0 && EndPos.Col < 7)
            {
                if ( StartPos.Col - 1 <= EndPos.Col&& EndPos.Col <= StartPos.Col + 1 )
                    return true;
            }
        }
        else if (StartPos.Row + 2 == EndPos.Row && StartPos.Row == 1)
        {
            if (StartPos.Col == EndPos.Col) 
                return true;
        }
        else
        {
            return false; 
        }
    } 
    return false;
}
bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (7 > StartPos.Row && StartPos.Row > 0)
    {
        if (StartPos.Row - 1 == EndPos.Row ) {
            if ( StartPos.Col == 0 )
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board 
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (0 < StartPos.Col  && StartPos.Col < 7) 
            {
                if (StartPos.Col - 1 <= EndPos.Col && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            // TODO: Add condition for enspassant
            
            return false;
        }
        else if (StartPos.Row - 2 == EndPos.Row && StartPos.Row == 6)
        {
            if (StartPos.Col == EndPos.Col) 
                return true;
        }
        else
        {
            return false;
        }
    }
    return false;

}
#pragma endregion
#pragma region King
 bool possibleMoveKing(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if ((StartPos.Row + 1 >= EndPos.Row && EndPos.Row >= StartPos.Row - 1) &&
             (StartPos.Col + 1 >= EndPos.Col && EndPos.Col >= StartPos.Col - 1))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion
#pragma region Rook
 bool possibleMoveRook(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Col == EndPos.Col || StartPos.Row == EndPos.Row)
             return true;
     }
     return false;
 }
#pragma endregion
#pragma region Bishop
 bool possibleMoveBishop(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // first diagonal working 
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         for (int col = StartPos.Col , row = StartPos.Row ; col <= 7 && row <= 7 ; col++,row++) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row >=0; col--, row--) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row <= 7; col--, row++) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row >= 0; col++, row--) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
     }
     return false;
 }
#pragma endregion

#pragma region Queen
 bool possibleMoveQueen(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
      // Queen has the same movement as a bishop and rook combined
         if (possibleMoveRook(StartPos, EndPos) || possibleMoveBishop(StartPos, EndPos))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion

#pragma region Knight
 bool possibleMoveKnight(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Row -1 == EndPos.Row && StartPos.Col + -2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col - 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion

bool Moves::VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition)
{
    bool _WrongMove = true;
    int _PIECETYPE = p_PieceBoard[p_OldPosition.Row][p_OldPosition.Col];
    switch (_PIECETYPE)
    {
    case PIECES_TYPE::BLACK_PAWN:
        _WrongMove = (possibleMoveBlackPawn(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_PAWN:
        _WrongMove = ((possibleMoveWhitePawn(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard,p_NewPosition))) ? true : false;
        break; 
    case PIECES_TYPE::BLACK_KING:
        _WrongMove = (possibleMoveKing(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_KING:
        _WrongMove = (possibleMoveKing(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_ROOK:
        _WrongMove = (possibleMoveRook(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_ROOK:
        _WrongMove = (possibleMoveRook(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_BISHOP:
        _WrongMove = (possibleMoveBishop(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_BISHOP:
        _WrongMove = (possibleMoveBishop(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_QUEEN:
        _WrongMove = (possibleMoveQueen(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_QUEEN:
        _WrongMove = (possibleMoveQueen(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_KNIGHT:
        _WrongMove = (possibleMoveKnight(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_KNIGHT:
        _WrongMove = (possibleMoveKnight(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    }
    return _WrongMove;
}
