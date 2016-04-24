#pragma once
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>

class Console
{
private:
public:
	Console();
	~Console();

	void GotoXY(int p_x, int p_y);
	void CursorVisible(bool p_CursorVisible);
	COORD GetCursorPosition();
};

