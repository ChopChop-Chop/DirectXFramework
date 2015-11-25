#pragma once
#include "Header.h"
#include "Scene.h"
#include "Sprite.h"

class S_Intro : public CScene
{
public:
	bool Init();
	void Update();
	
	S_Intro();
	~S_Intro();
private:
	CSprite* m_pBackGround;
};

