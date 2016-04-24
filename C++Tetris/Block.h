#pragma once
#include"Console.h"
#include"Board.h"
#include<iostream>
class Block
{
private:
	enum { NONE, BLOCK };
	enum { LEFT = 75,RIGHT = 77,UP = 72,DOWN = 80,SPACE = 32};
	int types[7][4][4][4];
	int m_now[4][4];
	
	int m_rotation;
	int m_nextType;
	int m_type;
	int m_x, m_y;

	bool m_isStacking;

	Console cnl;
public:
	Block();
	~Block();

	void Init();

	void Draw();
	void Erase();

	void Move(Board* p_board);
	void Rotate(Board* p_board);
	void SetStack(Board* p_board);
	void Stack(Board* p_board);
	void Down(Board* p_board);
	void Create();
	bool IntersectCheck(Board* p_board, int type, int rotation, int p_x, int p_y);


	int GetTypesOfBlock(int p_type, int p_rotation, int p_x, int p_y);
	
	int Rotation() { return m_rotation; }
	int NextType() { return m_nextType; }
	bool GetIsStacking() { return m_isStacking; }

};

