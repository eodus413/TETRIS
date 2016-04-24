#pragma once
#include<iostream>	
#include"Console.h"
#include"GameInfo.h"

class Board
{
public:
	enum { NONE, WALL, FLOOR, CORNER, STACKBLOCK };

	enum { WIDTH = 10, HEIGHT = 20 };

private:
	int m_board[HEIGHT][WIDTH];

	Console cnl;

public:
	
	Board();
	~Board();
	
	void Init();

	Board* GetThisBoard();
	int GetBoard(int p_x,int p_y);
	void SetStackBlock(int p_x,int p_y);

	void StackLineClear(GameInfo& p_Info);
	void StackBlockDown(int p_y);

	void Draw();
	void Draw(int p_top, int p_left, int p_bottom, int p_right);
	void Erase();
	void Erase(int p_top, int p_left, int p_bottom, int p_right);

	bool StackBlockCheckHeight();
};

