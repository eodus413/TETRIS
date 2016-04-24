#pragma once
#include"Console.h"
#include "GameInfo.h"
#include "Block.h"
class Viewer
{
private:
	enum { WIDTH = 6, HEIGHT = 6 };
	enum { NONE, WALL, FLOOR, CORNER };
	int m_blockViewer[HEIGHT][WIDTH];
	int m_nextBlock[4][4][4];

	int m_x, m_y;

	Console cnl;

	
public:
	
	void Init();
	void Draw();
	
	void ChangeNextBlock(Block& p_block);

	Viewer();
	~Viewer();
};

