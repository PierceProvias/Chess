#pragma once
#include <array>
#include "moves_def.h"
#include "pieces_def.h"

static bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos);
static bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos);

class Moves
{
public:
    static bool VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
    // static bool isGameOver(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard);
    // static PieceColor getWinner(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard);
};
