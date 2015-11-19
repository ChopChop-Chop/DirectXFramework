#include "Director.h"
#include "S_Intro.h"


CDirector::CDirector()
{
	m_bIsActive = true;

	m_pCollisionMgr = nullptr;
	m_pDrawMgr = nullptr;
	m_pInputMgr = nullptr;
	m_pObjectMgr = nullptr;
	m_pTextureMgr = nullptr;
	m_pSceneMgr = nullptr;
	m_pSoundMgr = nullptr;
}


CDirector::~CDirector()
{
	Release();
}

bool CDirector::Init()
{
	m_pDrawMgr = new CDrawManager();
	m_pDrawMgr->Init();

	m_pCollisionMgr = new CCollisionManager();
	m_pInputMgr = new CInputManager();
	m_pObjectMgr = new CObjectManager();
	m_pTextureMgr = new CTextureManager();
	m_pSceneMgr = new CSceneManager();
	m_pSoundMgr = new CSoundManager();

	m_pSceneMgr->setCurScene(new S_Intro);
	m_pSceneMgr->getCurScene()->Init();

	return true;
}
void CDirector::Update()
{
	m_pSceneMgr->sceneUpdate();
	m_pSceneMgr->getCurScene()->Update();
	// Scene Update();
}
void CDirector::Render()
{
	CDrawMgr->PreRender();
	m_pSceneMgr->getCurScene()->Render();
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
		else if (CDIRECTOR->m_bIsActive)
		{
			Update();
			Render();
		}
	}
}
void CDirector::Release()
{
	SAFE_DELETE(m_pSoundMgr);
	SAFE_DELETE(m_pSceneMgr);
	SAFE_DELETE(m_pTextureMgr);
	SAFE_DELETE(m_pObjectMgr);
	SAFE_DELETE(m_pInputMgr);
	SAFE_DELETE(m_pDrawMgr);
	SAFE_DELETE(m_pCollisionMgr);
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