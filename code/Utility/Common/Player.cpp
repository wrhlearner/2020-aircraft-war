#include "Player.h"

Player::Player()
{
	m_Name = PLAYER;
	m_Width = PLAYERWIDTH;
	m_Height = PLAYERHEIGHT;
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Speed = PLAYERSPEED;
	m_Blood = PLAYERBLOOD;
	m_FirePower = PLAYERFIREPOWER;
	m_Direction = Pos;
	m_Exist = true;
}
Player::Player(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower) :Aircraft(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower){}
Player::Player(const Player& p)
{
	m_Name = p.m_Name;
	m_Width = p.m_Width;
	m_Height = p.m_Height;
	m_PosX = p.m_PosX;
	m_PosY = p.m_PosY;
	m_Speed = p.m_Speed;
	m_Direction = p.m_Direction;
	m_Exist = p.m_Exist;
	m_PictureMap = p.m_PictureMap;
	m_Blood = p.m_Blood;
	m_FirePower = p.m_FirePower;
}