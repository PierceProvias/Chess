#pragma once 

class PiecePosition {
public:
	PiecePosition(int row, int col) :Row{row }, Col{ col } {};
	int Row, Col;
	bool operator==(const PiecePosition& other) const {
		return Row == other.Row && Col == other.Col;
	}
};

enum PieceColor  { NONE,BLACK,WHITE }; // later handle draw conditions