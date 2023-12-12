#include "mainGame.h"

mainGame::mainGame()
{
	m_znFirstGame = new zeroNum();
}


mainGame::~mainGame()
{
	delete m_znFirstGame;
	m_znFirstGame = NULL;
}
