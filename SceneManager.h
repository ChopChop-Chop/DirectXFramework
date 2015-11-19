#pragma once
#include "Scene.h"


class CSceneManager
{
private:
	CScene* m_pNextScene;
	CScene* m_pCurScene;

	bool m_bIsExistNextScene;
public:
	void setNextScene(CScene* a_pNextScene);
	void setCurScene(CScene* a_pCurScene);

	CScene* getNextScene();
	CScene* getCurScene();

	void sceneUpdate();

	CSceneManager();
	~CSceneManager();
};

