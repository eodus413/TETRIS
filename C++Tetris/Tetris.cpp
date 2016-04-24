#include "Tetris.h"



Tetris::Tetris()
{
}


Tetris::~Tetris()
{
}


void Tetris::Init()
{
	srand((unsigned)time(NULL));
	cnl.CursorVisible(false);
	board.Init();
	block.Init();


	block.Create();

	board.Draw();
	block.Draw();
}

void Tetris::Update()
{
	do
	{
		Info.delay(1000 / Info.Frame());
		Info.Timer(Info.Timer() + (1000 / Info.Frame()));

		if (Info.Timer() % 300 == 0)
		{
			block.Stack(board.GetThisBoard());
			board.StackLineClear(Info);
			board.Draw(0, 0, board.HEIGHT - 1, board.WIDTH);
			if (!block.GetIsStacking())
				block.Down(board.GetThisBoard());
			else
				block.Create();
		}
		else
		{
			block.Move(board.GetThisBoard());
		}

		Info.GameOn(board.StackBlockCheckHeight());

	} while (Info.GameOn());
}
