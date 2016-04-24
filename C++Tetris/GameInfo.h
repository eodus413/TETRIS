#pragma once
#include"Console.h"
#define Billion 100000000
class GameInfo
{
private:
	const int MaxFrame;		//최대프레임 수

	bool m_gameOn;			//게임이 실행중인지	

	int m_frame;					//초당프레임수
	int m_timer;					//타이머

	int m_score;					//점수
	
	int m_level;						//레벨
	
	
public:
	GameInfo();
	~GameInfo();

	bool GameOn();
	void GameOn(bool p_on);

	int Frame();
	void Frame(int p_frame);

	int Timer();
	void Timer(int p_frame);

	int Score();
	void Score(int p_score);
	void AddScore(int p_add);

	int Level();
	void Level(int p_level);
	
	void delay(clock_t n);
	
	GameInfo* GetThisInfo() { return this; }

	
	void  Draw();
};