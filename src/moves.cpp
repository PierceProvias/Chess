#include "../include/moves.h"
#include "../include/pieces_def.h"
#include <iostream> 
#include "../include/pieces_manager.h"

static int round(int num)
{
    return (num > 0) ? num : num * -1;
}

static bool isBlack(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 > p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}
static bool isWhite(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 < p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}


// TODO: add promotion
#pragma region Pawn
bool possibleMoveBlackPawn(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // Illegal moves
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
        EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }
    // Single step move
    if (StartPos.Row + 1 == EndPos.Row && StartPos.Col == EndPos.Col)
    {
        if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
            return true;
    }
    // Double step for first move option
    else if (StartPos.Row == 1 && StartPos.Col == EndPos.Col)
    {
        if ( EndPos.Row == 3)
        {
            if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
                return true;
        }
    }
    // Capture piece diagonally
    else if ((StartPos.Col - 1 == EndPos.Col || StartPos.Col + 1 == EndPos.Col) && (StartPos.Row + 1 == EndPos.Row))
    {
        if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)
            return true;
    }
    return false;
} 

 bool possibleMoveWhitePawn(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // Illegal moves
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
        EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }
    // Single step move
    if (StartPos.Row - 1 == EndPos.Row && StartPos.Col == EndPos.Col)
    {
        if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
            return true;
    }
    // Double step for first move option
    else if (StartPos.Row == 6 && StartPos.Col == EndPos.Col)
    {
        if (EndPos.Row == 4)
        {
            if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
                return true;
        }
    }
    // Capture piece diagonally
    else if ((StartPos.Col - 1 == EndPos.Col || StartPos.Col + 1 == EndPos.Col) && (StartPos.Row - 1 == EndPos.Row))
    {

        if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)
            return true;
        
    }
    return false;

}
#pragma endregion

#pragma region King
// TODO: Castling
static bool possibleMoveKing(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // Illegal moves
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7
        || EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }
    
    // single move from all side 
    if ((StartPos.Row + 1 >= EndPos.Row && EndPos.Row >= StartPos.Row - 1) &&
        (StartPos.Col + 1 >= EndPos.Col && EndPos.Col >= StartPos.Col - 1))
    {
        return true;
    }
    
    // Castle
    if (StartPos.Col + 2 == EndPos.Col || StartPos.Col - 2 == EndPos.Col)
    {
        if(p_PieceBoard[7][7] == PIECES_TYPE::WHITE_ROOK)
        {
            //if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)

             //if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)
            //return true;
            p_PieceBoard[7][5] = p_PieceBoard[7][7];
            p_PieceBoard[7][7] = PIECES_TYPE::EMPTY;
            p_PieceBoard[7][6] = PIECES_TYPE::WHITE_KING;
            if(p_PieceBoard[7][6] == PIECES_TYPE::WHITE_KING && p_PieceBoard[7][5] == PIECES_TYPE::WHITE_ROOK)
            {
                std::cout << "White rook \n";
                return Moves::isCastled();

            }
            
        }
       //Moves::Castle(p_PieceBoard, StartPos, EndPos);

    }   
    return false;
}
#pragma endregion

#pragma region Rook
static bool possibleMoveRook(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // Invalid moves
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
        EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }
    // Check for forward row
    if (StartPos.Col == EndPos.Col)  
    {
        for (int i = StartPos.Row - 1; i >= 0; i--)
        { 
            if (i == EndPos.Row) 
            {
                if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
                return true;

            }
            if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        
        }
        // Check for backward row
        for (int i = StartPos.Row + 1; i <= 7; i++)
        {
            if (i == EndPos.Row)
            {
                if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
                    return true;
                return true;
            }
            if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
    }
    // Left of col
    if (StartPos.Row == EndPos.Row)
    {
        for (int i = StartPos.Col - 1 ; i >= 0; i--)
        {
            if (i == EndPos.Col)
            {
                if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
                    return true;
                return true;
            }
            if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
        // Right of col
        for (int i = StartPos.Col + 1; i <= 7; i++)
        {
            if (i == EndPos.Col)
            {
                if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
                    return true;
                return true;
            }
            if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
            {
                break;
            }
        }
    }
    
    if(Moves::isCastled() && StartPos.Col -2 == EndPos.Col && StartPos.Row == EndPos.Row)
    {
        std::cout << "White King Castled" << std::endl;
        return true;
    }
    
    return false;
} 
#pragma endregion

#pragma region Bishop
static bool possibleMoveBishop(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // Invalid moves
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
        EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }

    int _row = 0, _col = 0;

    // First diagonal forward
    _row = StartPos.Row - 1;
    _col = StartPos.Col - 1;
    while (_row >= 0 && _col >= 0)
    {
        if (_row == EndPos.Row && _col == EndPos.Col)
        {
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                return true;
            return true;
        }
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
            _row--; _col--;
        
    }
    // First diagonal backward
    _row = StartPos.Row + 1;
    _col = StartPos.Col + 1;
    while (_row <= 7 && _col <= 7)
    {
        if (_row == EndPos.Row && _col == EndPos.Col)
        {
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                return true;
            return true;
        }
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
            {
                break;
            }
            _row++; _col++;
        
    }
    // Second diagonal forward
    _row = StartPos.Row - 1;
    _col = StartPos.Col + 1;
    while (_row >= 0 && _col <= 7)
    {
        if (_row == EndPos.Row && _col == EndPos.Col)
        {
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                return true;
            return true;
        }
        if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
        {
            break;
        }
        _row--; _col++;

    }
    // Second diagonal backward
    _row = StartPos.Row + 1;
    _col = StartPos.Col - 1;
    while (_row <= 7 && _col >= 0)
    {
        if (_row == EndPos.Row && _col == EndPos.Col)
        {
            if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                return true;
            return true;
        }
        if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
        {
            break;
        }
        _row++; _col--;

    }
    return false;
}
#pragma endregion

#pragma region Queen
 bool possibleMoveQueen(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
        // Queen movement = Rook + Bishop
         if (possibleMoveRook(p_PieceBoard,StartPos, EndPos) || possibleMoveBishop(p_PieceBoard, StartPos, EndPos))
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

bool Moves::ValidMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition)
{
    
    // TODO: Handle array for legal move
    bool _WrongMove = true;
    
    int _PIECETYPE = p_PieceBoard[p_OldPosition.Row][p_OldPosition.Col];
    switch (_PIECETYPE)
    {
    case PIECES_TYPE::BLACK_PAWN:
        _WrongMove = (possibleMoveBlackPawn(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_PAWN:
        _WrongMove = ((possibleMoveWhitePawn(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard,p_NewPosition))) ? true : false;
        break; 
    case PIECES_TYPE::BLACK_KING:
        _WrongMove = (possibleMoveKing(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_KING:
        _WrongMove = (possibleMoveKing(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_ROOK:
        _WrongMove = (possibleMoveRook(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_ROOK:
        _WrongMove = (possibleMoveRook(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_BISHOP:
        _WrongMove = (possibleMoveBishop(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_BISHOP:
        _WrongMove = (possibleMoveBishop(p_PieceBoard ,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_QUEEN:
        _WrongMove = (possibleMoveQueen(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_QUEEN:
        _WrongMove = (possibleMoveQueen(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
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

bool Moves::Castle(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition)
{
    
    if(p_PieceBoard[7][6] == PIECES_TYPE::WHITE_KING)
    return false;
    
}

bool Moves::isCastled()
{
    std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard;
    if(p_PieceBoard[7][6] == PIECES_TYPE::WHITE_KING )
    {
        p_PieceBoard[7][5] = PIECES_TYPE::WHITE_ROOK;
        std::cout << "Is castled\n";
        return true;
    }
    return false;
}


/*
bool Candy::Moves::isGameOver(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard)
{
    return false;
}

PieceColor Candy::Moves::getWinner(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard)
{
    return PieceColor();
}
*/