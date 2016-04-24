#include"GameInfo.h"	

bool GameInfo::GameOn() {						//get

	return m_gameOn;
}
void GameInfo::GameOn(bool p_isOn) {		//set

	m_gameOn = p_isOn;
}

int GameInfo::Frame() {							//get

	if (m_frame <= MaxFrame)
		return m_frame;

	else {
		m_frame = MaxFrame;
		return m_frame;
	}
}
void GameInfo::Frame(int p_frame) {			//set

	if (p_frame <= MaxFrame)
		m_frame = p_frame;
	else
		m_frame = MaxFrame;
}

int GameInfo::Timer() {							//get
	return m_timer;
}
void GameInfo::Timer(int p_timer) {			//set

	if(p_timer <= Billion)
		m_timer = p_timer;
}

int GameInfo::Score()
{
	if (m_score > 0)
		return m_score;
	else
		return 0;

}
void GameInfo::Score(int p_score)
{
	if (p_score > 0)
		m_score = p_score;
	else
		m_score = 0;
}
void GameInfo::AddScore(int p_add)
{
	if (p_add > 0 && p_add < 100)
		m_score += p_add;
	else
		m_score += 0;
}

int GameInfo::Level()
{
	if (m_level > 0)
		return m_level;
	else
		return 1;
}
void GameInfo::Level(int p_level)
{
	if (p_level > 0)
		m_level = p_level;
	else
		m_level = 1;
}


GameInfo::GameInfo() : 
	MaxFrame(10) {
	
	GameOn(true);
	Frame(5);
	Timer(0);
	Score(0);
	Level(1);
}

GameInfo::~GameInfo() {

}

void GameInfo::delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}


void GameInfo::Draw()
{

}
