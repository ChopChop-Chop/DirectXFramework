#include "Director.h"
#include "S_Intro.h"


CDirector::CDirector()
{
	_isActive = true;

	_collisionMgr = nullptr;
	_drawMgr = nullptr;
	_inputMgr = nullptr;
	_objectMgr = nullptr;
	_textureMgr = nullptr;
	_sceneMgr = nullptr;
	_soundMgr = nullptr;
}


CDirector::~CDirector()
{
	Release();
}

bool CDirector::Init()
{
	_drawMgr = new CDrawManager();
	_drawMgr->Init();
	
	_collisionMgr = new CCollisionManager();
	_inputMgr = new CInputManager();
	_objectMgr = new CObjectManager();
	_textureMgr = new CTextureManager();
	_sceneMgr = new CSceneManager();
	_soundMgr = new CSoundManager();
	
	_sceneMgr->setCurScene(new S_Intro);
	_sceneMgr->getCurScene()->Init();

	return true;
}
void CDirector::Update()
{
	_sceneMgr->sceneUpdate();
	_sceneMgr->getCurScene()->Update();
	// Scene Update();
}
void CDirector::Render()
{
	CDrawMgr->PreRender();
	_sceneMgr->getCurScene()->Render();
	CDrawMgr->PostRender();
}
void CDirector::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (CDIRECTOR->_isActive)
		{
			Update();
			Render();
		}
	}
}
void CDirector::Release()
{
	SAFE_DELETE(_soundMgr);
	SAFE_DELETE(_sceneMgr);
	SAFE_DELETE(_textureMgr);
	SAFE_DELETE(_objectMgr);
	SAFE_DELETE(_inputMgr);
	SAFE_DELETE(_drawMgr);
	SAFE_DELETE(_collisionMgr);
}
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		CInputMgr->setCurDownKey(wParam);
		break;
	case WM_KEYUP:
		CInputMgr->setCurUpKey(wParam);
		break;
	case WM_LBUTTONDBLCLK:
		CInputMgr->setLButtonState(LButtonState::DBClick);
		break;
	case WM_LBUTTONDOWN:
		CInputMgr->setLButtonState(LButtonState::Down);
		break;
	case WM_LBUTTONUP:
		CInputMgr->setLButtonState(LButtonState::Up);
		break;
	case WM_RBUTTONDBLCLK:
		CInputMgr->setRButtonState(RButtonState::DBClick);
		break;
	case WM_RBUTTONDOWN:
		CInputMgr->setRButtonState(RButtonState::Down);
		break;
	case WM_RBUTTONUP:
		CInputMgr->setRButtonState(RButtonState::Up);
		break;
	case WM_MOUSEMOVE:
		CInputMgr->setMousePosition(lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}