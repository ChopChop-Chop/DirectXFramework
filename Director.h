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

	CCollisionManager* getCollisionManager() { return _collisionMgr; }
	CDrawManager* getDrawManager() { return _drawMgr; }
	CInputManager* getInputManager() { return _inputMgr; }
	CObjectManager* getObjectManager() { return _objectMgr; }
	CTextureManager* getTextureManager() { return _textureMgr; }
	CSceneManager* getSceneManager() { return _sceneMgr; }
	CSoundManager* getSoundManager() { return _soundMgr; }
	
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

	CCollisionManager* _collisionMgr;
	CDrawManager* _drawMgr;
	CInputManager* _inputMgr;
	CObjectManager* _objectMgr;
	CTextureManager* _textureMgr;
	CSceneManager* _sceneMgr;
	CSoundManager* _soundMgr;

	bool _isActive;

	CDirector();

};
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
