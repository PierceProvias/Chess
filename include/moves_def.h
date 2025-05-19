#pragma once 

class PiecePosition 
{
public:
	int Row, Col;
	PiecePosition(int row, int col) :Row{row}, Col{col} {};

	bool operator==(const PiecePosition& other) const {
		return Row == other.Row && Col == other.Col;
	}
};

enum PieceColor  { NONE,BLACK,WHITE }; 