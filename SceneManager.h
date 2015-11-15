#pragma once

class CScene;

class CSceneManager
{
private:
	CScene* m_pNextScene;
	CScene* m_pCurScene;

	bool m_bIsExistNextScene;
public:
	void setNextScene(CScene* a_pNextScene);

	CScene* getNextScene();
	CScene* getCurScene();

	void sceneUpdate();

	CSceneManager();
	~CSceneManager();
};

