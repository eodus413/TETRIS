#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}



void Console::GotoXY(int p_x, int p_y)
{
	COORD pos = { p_x * 2, p_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::CursorVisible(bool p_CursorVisible)    // Console.CursorVisible = false;
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = p_CursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

COORD Console::GetCursorPosition()
{
	COORD cursor;
	CONSOLE_SCREEN_BUFFER_INFO cursorInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursor.X = cursorInfo.dwCursorPosition.X;
	cursor.Y = cursorInfo.dwCursorPosition.Y;
	return cursor;
}

