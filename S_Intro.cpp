#include "S_Intro.h"



S_Intro::S_Intro()
{
}


S_Intro::~S_Intro()
{
}

bool S_Intro::Init()
{
	m_pBackGround = new CSprite();
	m_pBackGround->Init("Resources/bg.png");
	addChild(m_pBackGround, -1);

	return true;
}
void S_Intro::Update()
{
}