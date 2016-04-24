#include "Viewer.h"


void Viewer::Draw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; y++)
		{
			cnl.GotoXY(m_x+x, m_y+y);
			if (m_blockViewer[y][x] == NONE);
			else if (m_blockViewer[y][x] == WALL)
				std::cout << "¥¹";
			else if (m_blockViewer[y][x] == FLOOR)
				std::cout << "¡ë";
			else if (m_blockViewer[y][x] == CORNER)
				std::cout << "©¸";
		}
	}
	
}

void Viewer::Init()
{
	int temp[HEIGHT][WIDTH] = {
		{ CORNER, FLOOR,  FLOOR,  FLOOR,  FLOOR,  CORNER },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ CORNER, FLOOR,  FLOOR,  FLOOR,  FLOOR,  CORNER },
	};
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			m_blockViewer[y][x] = temp[y][x];
		}
	}
}

void Viewer::ChangeNextBlock(Block& p_block)
{
	for (int r = 0; r < 4; r++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				m_nextBlock[r][y][x] = p_block.GetTypesOfBlock(p_block.NextType(),r,x,y);
			}
		}
	}
}

Viewer::Viewer()
{
}


Viewer::~Viewer()
{
}

