#pragma once
#include "Header.h"
#include "Define.h"
#include "CollisionManager.h"
#include "DrawManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

class CDirector
{
public:
	bool Init();	// Manager Init
	void Update();	 
	void Render();	
	void Run();	// Main Loop
	void Release();	// Manager Release

	CCollisionManager* getCollisionManager() { return m_pCollisionMgr; }
	CDrawManager* getDrawManager() { return m_pDrawMgr; }
	CInputManager* getInputManager() { return m_pInputMgr; }
	CObjectManager* getObjectManager() { return m_pObjectMgr; }
	CTextureManager* getTextureManager() { return m_pTextureMgr; }
	CSceneManager* getSceneManager() { return m_pSceneMgr; }
	CSoundManager* getSoundManager() { return m_pSoundMgr; }
	
	static CDirector* getInstance()
	{
		static CDirector* Inst;
		if (Inst == NULL)
		{
			Inst = new CDirector();
		}

		return Inst;
	}

	~CDirector();
private:

	CCollisionManager* m_pCollisionMgr;
	CDrawManager* m_pDrawMgr;
	CInputManager* m_pInputMgr;
	CObjectManager* m_pObjectMgr;
	CTextureManager* m_pTextureMgr;
	CSceneManager* m_pSceneMgr;
	CSoundManager* m_pSoundMgr;

	bool m_bIsActive;

	CDirector();

};
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
