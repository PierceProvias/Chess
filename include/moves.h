#pragma once
#include <array>
#include "moves_def.h"
#include "pieces_def.h"

class Moves
{
public:
    
    static bool ValidMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
    static bool Castle(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
    static bool isCastled();
};