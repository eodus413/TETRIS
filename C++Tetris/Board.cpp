#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::Init()
{
	int temp[HEIGHT][WIDTH] = {

		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ CORNER,FLOOR,FLOOR,FLOOR,FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, CORNER }

	};

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			m_board[y][x] = temp[y][x];
}

Board* Board::GetThisBoard()
{
	return this;
}
int Board::GetBoard(int p_x, int p_y)
{
	return m_board[p_y][p_x];
}


void Board::StackLineClear(GameInfo& p_Info)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		int stackBlockCount = 0;
		for (int x = 0; x < WIDTH; x++)
		{

			if (m_board[y][x] == STACKBLOCK)
			{
				stackBlockCount++;
			}
		}

		if (stackBlockCount == WIDTH - 2)
		{
			for (int x = 1; x < WIDTH - 1; x++)
			{
				m_board[y][x] = NONE;
			}
			StackBlockDown(y);
			p_Info.AddScore(100);
			Erase(0, 1, HEIGHT-1, WIDTH - 1);
			Draw(0,1,y, WIDTH-1);
		}
	}
}

void Board::StackBlockDown(int p_y)
{
	for (int x = 1; x < WIDTH-1; x++)
	{
		for (int y = p_y; y>0;y--)
		{
			m_board[y][x] = m_board[y- 1][x];
		}
	}
}


void Board::SetStackBlock(int p_x, int p_y)
{
	if ((p_x < WIDTH && p_x > 0) && (p_y < HEIGHT && p_y >0))

		m_board[p_y][p_x] = STACKBLOCK;

}

void Board::Draw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{

			cnl.GotoXY(x, y);

			if (m_board[y][x] == NONE);
			else if (m_board[y][x] == WALL)
				std::cout << "│";
			else if (m_board[y][x] == FLOOR)
				std::cout << "━";
			else if (m_board[y][x] == CORNER)
				std::cout << "◇";
			else if (m_board[y][x] == STACKBLOCK)
				std::cout << "▣";
		}
	}
}
void Board::Draw(int p_top, int p_left, int p_bottom, int p_right)
{
	for (int y = p_top; y < p_bottom; y++)
	{
		for (int x = p_left; x < p_right; x++)
		{
			cnl.GotoXY(x, y);

			if (m_board[y][x] == NONE);
			else if (m_board[y][x] == WALL)
				std::cout << "│";
			else if (m_board[y][x] == FLOOR)
				std::cout << "━";
			else if (m_board[y][x] == CORNER)
				std::cout << "◇";
			else if (m_board[y][x] == STACKBLOCK)
				std::cout << "▣";
		}
	}
}

void Board::Erase()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cnl.GotoXY(x, y);
			std::cout << "  ";
		}
	}
}
void Board::Erase(int p_top, int p_left, int p_bottom, int p_right)
{
	for (int y = p_top; y < p_bottom; y++)
	{
		for (int x = p_left; x < p_right; x++)
		{
			cnl.GotoXY(x, y);
			std::cout << "  ";
		}
	}
}

bool Board::StackBlockCheckHeight()
{
	for (int x = 1; x < WIDTH - 1; x++)
	{
		if (m_board[1][x] == STACKBLOCK)
		{
			return false;
		}
	}
	return true;
}
