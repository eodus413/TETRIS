#pragma once
#include"Console.h"
#define Billion 100000000
class GameInfo
{
private:
	const int MaxFrame;		//�ִ������� ��

	bool m_gameOn;			//������ ����������	

	int m_frame;					//�ʴ������Ӽ�
	int m_timer;					//Ÿ�̸�

	int m_score;					//����
	
	int m_level;						//����
	
	
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