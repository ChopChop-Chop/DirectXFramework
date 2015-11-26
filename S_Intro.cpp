#include "S_Intro.h"
#include "Director.h"


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
	//addChild(m_pBackGround, -1);
	CDrawMgr->m_pCurCamera->setActive(true);
	CDrawMgr->m_pCurCamera->setEye(D3DXVECTOR3(0, 0, -150));

	_mesh = new CMesh();
	_mesh->Init("Resources/tiger.x");
	addChild(_mesh, 1);

	return true;
}
void S_Intro::Update()
{
	CDrawMgr->m_pCurCamera->Update();
}