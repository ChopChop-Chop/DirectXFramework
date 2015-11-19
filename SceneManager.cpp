#include "SceneManager.h"
#include "Node.h"
#include "Director.h"


CSceneManager::CSceneManager()
{
	m_bIsExistNextScene = false;
}


CSceneManager::~CSceneManager()
{
	if (m_pCurScene != NULL)
	{
		delete m_pCurScene;
		m_pCurScene = nullptr;
	}
	if (m_pNextScene != NULL)
	{
		delete m_pNextScene;
		m_pNextScene = nullptr;
	}
}


void CSceneManager::setNextScene(CScene* a_pNextScene)
{
	this->m_pNextScene = a_pNextScene;

	m_bIsExistNextScene = true;
}

void CSceneManager::setCurScene(CScene* a_pCurScene)
{
	m_pCurScene = a_pCurScene;
}
CScene* CSceneManager::getNextScene()
{
	if (m_pNextScene == NULL)
	{
		MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "NextSceneNullException", "NextSceneNullException", MB_OK);
		std::cout << "NextSceneNullException" << std::endl;

		return NULL;
	}

	return m_pNextScene;
}
CScene* CSceneManager::getCurScene()
{
	if (m_pCurScene == NULL)
	{
		MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "CurSceneNullException", "CurSceneNullException", MB_OK);
		std::cout << "CurSceneNullException" << std::endl;

		return NULL;
	}

	return m_pCurScene;
}
void CSceneManager::sceneUpdate()
{
	if (!m_bIsExistNextScene)
		return;

	m_pCurScene->Release();
	delete m_pCurScene;
	m_pCurScene = nullptr;
	m_pCurScene = m_pNextScene;
	m_pCurScene->Init();

	m_bIsExistNextScene = false;
}