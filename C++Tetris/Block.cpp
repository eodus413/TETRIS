#include "Block.h"



Block::Block() : m_nextType(rand() % 7)
{
}

Block::~Block()
{
}

void Block::Init()
{
	int temp[7][4][4][4] =
	{
		//00
		//00
		{
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			}
		},
		//0
		//0
		//00
		{
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 },
				{ 0,1,1,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,1 },
				{ 0,1,0,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,0,1,0 },
				{ 0,0,1,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,0,1,0 },
				{ 1,1,1,0 },
				{ 0,0,0,0 }
			}
		},
		//  0
		//  0
		//0 0
		{
			{
				{ 0,0,0,0 },
				{ 0,0,1,0 },
				{ 0,0,1,0 },
				{ 0,1,1,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 0,1,1,1 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 1,1,1,0 },
				{ 0,0,1,0 },
				{ 0,0,0,0 }
			}
		},
		//0
		//0
		//0
		//0
		{
			{
				{ 0,1,0,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,0,0,0 },
				{ 1,1,1,1 },
				{ 0,0,0,0 }
			},
			{
				{ 0,1,0,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 },
				{ 0,1,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,0,0,0 },
				{ 1,1,1,1 },
				{ 0,0,0,0 }
			}
		},

		//00
		//  00

		{
			{
				{ 0,0,0,0 },
				{ 1,1,0,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,0,1,0 },
				{ 0,1,1,0 },
				{ 0,1,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 1,1,0,0 },
				{ 0,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,0,1,0 },
				{ 0,1,1,0 },
				{ 0,1,0,0 }
			}
		},

		//00
		//  00

		{
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 1,1,0,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 0,1,1,0 },
				{ 0,0,1,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,1,0 },
				{ 1,1,0,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 0,1,1,0 },
				{ 0,0,1,0 }
			}
		},


		// 0
		//000

		{
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 1,1,1,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 0,1,1,0 },
				{ 0,1,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 1,1,1,0 },
				{ 0,1,0,0 },
				{ 0,0,0,0 }
			},
			{
				{ 0,0,0,0 },
				{ 0,1,0,0 },
				{ 1,1,0,0 },
				{ 0,1,0,0 }
			}
		}
	};



	for (int i_1 = 0; i_1 < 7; i_1++)
		for (int i_2 = 0; i_2 < 4; i_2++)
			for (int i_3 = 0; i_3 < 4; i_3++)
				for (int i_4 = 0; i_4 < 4; i_4++)
					types[i_1][i_2][i_3][i_4] = temp[i_1][i_2][i_3][i_4];

}

void Block::Draw()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (m_now[y][x] == NONE);
			else if (m_now[y][x] == BLOCK)
			{
				cnl.GotoXY(m_x + x, m_y + y);
				std::cout << "■";
			}
		}
	}	
}

void Block::Erase()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (m_now[y][x] == NONE);
			else if (m_now[y][x] == BLOCK)
			{
				cnl.GotoXY(m_x + x, m_y + y);
				std::cout << "  ";
			}
		}
	}
}

void Block::Move(Board* p_board)
{
	int key = 0;

	if (_kbhit())
	{
		Erase();
		key = _getch();
		if (key == 224)
		{
			do { key = _getch(); } while (key == 224);
			if (key == LEFT)
			{
				if (IntersectCheck(p_board, m_type, m_rotation, m_x - 1, m_y))
				{
					m_x--;
				}
			}
			else if (key == RIGHT)
			{
				if (IntersectCheck(p_board, m_type, m_rotation, m_x + 1, m_y))
				{
					m_x++;
				}
			}
			else if (key == UP)
			{
				Rotate(p_board);
			}
			else if (key == DOWN)
			{
				while (IntersectCheck(p_board, m_type, m_rotation, m_x , m_y + 1))
				{
					Down(p_board);
				}
			}
			
		}
		else
		{
			if (key == SPACE)
			{
				if (IntersectCheck(p_board, m_type, m_rotation, m_x, m_y + 1))
				{
					Down(p_board);
				}
			}
		}

	}
	while (_kbhit()) _getch();
	Draw();
}

void Block::Rotate(Board* p_board)
{
	if (m_rotation < 3)
	{
		if (IntersectCheck(p_board, m_type, m_rotation + 1, m_x, m_y))
		{
			m_rotation++;
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					m_now[y][x] = types[m_type][m_rotation][y][x];
		}
	}
	else if (m_rotation == 3)
	{
		if (IntersectCheck(p_board, m_type, m_rotation - 3, m_x, m_y))
		{
			m_rotation = 0;
			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					m_now[y][x] = types[m_type][m_rotation][y][x];
		}
	}
}

void  Block::SetStack(Board* p_board)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (m_now[y][x] == BLOCK)
				p_board->SetStackBlock(m_x + x, m_y + y);
		}
	}
}

void Block::Down(Board* p_board)
{
	Erase();
	m_y++;
	Draw();
}

void Block::Stack(Board* p_board)
{
	if (!(IntersectCheck(p_board, m_type, m_rotation, m_x, m_y + 1)))	//아래체크
	{
		m_isStacking = true;
		SetStack(p_board);
	}
}

void Block::Create()
{
	m_rotation = 0;
	m_type = m_nextType;
	m_nextType = rand() % 7;
	m_x = 4;
	m_y = 0;
	m_isStacking = false;
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			m_now[y][x] = types[m_type][m_rotation][y][x];
}

bool Block::IntersectCheck(Board* p_board, int type, int rotation, int p_x, int p_y)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if ((types[type][rotation][y][x] == BLOCK) && p_board->GetBoard(p_x + x, p_y + y) > p_board->NONE)
			{
				return false;
			}
	return true;
}

int Block::GetTypesOfBlock(int p_type, int p_rotation, int p_x, int p_y)
{
	if ((p_type > 0 && p_type < 7) && (p_rotation >0 && p_rotation < 4) && (p_x > 0 && p_x < 4) && (p_y > 0 && p_y < 4))
		return types[p_type][p_rotation][p_x][p_y];
	else
		return 0;
}