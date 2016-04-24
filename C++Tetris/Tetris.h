#pragma once
#include"GameInfo.h"
#include"Board.h"
#include"Block.h"
class Tetris
{
private:
	GameInfo Info;

	Board board;
	Block block;
	Console cnl;
public:
	void Init();
	void Update();
	Tetris();
	~Tetris();
};

