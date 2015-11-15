#include "DrawManager.h"
#include "Director.h"

CDrawManager::CDrawManager()
{
	m_rtScreen.left = 100;
	m_rtScreen.right = m_rtScreen.left + 1280;
	m_rtScreen.top = 100;
	m_rtScreen.bottom = m_rtScreen.top + 720;
}


CDrawManager::~CDrawManager()
{
}

bool CDrawManager::Init()
{
	if (!InitWin())
		return false;

	if (!InitD3D())
		return false;

	return true;
}
bool CDrawManager::InitWin()
{

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"framework", NULL
	};
	RegisterClassEx(&wc);

	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);

	m_rtScreen.left = (width / 2) - (WINWIDTH / 2);
	m_rtScreen.right = (width / 2) + (WINWIDTH / 2);
	m_rtScreen.top = (height / 2) - (WINHEIGHT / 2);
	m_rtScreen.bottom = (height / 2) + (WINHEIGHT / 2);

	// Create the application's window
	m_HWND = CreateWindow("framework", "DirectXFrameworkAlpha",
		WS_OVERLAPPEDWINDOW, m_rtScreen.left, m_rtScreen.top, m_rtScreen.right, m_rtScreen.bottom,
		NULL, NULL, wc.hInstance, NULL);

	return true;
}
bool CDrawManager::InitD3D()
{
	// Create the D3D object.
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return false;

	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// Create the D3DDevice
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_HWND,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &m_pDevice)))
	{
		return false;
	}

	// Turn on the zbuffer
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	// Turn on ambient lighting 
	m_pDevice->SetRenderState(D3DRS_AMBIENT, 0xffffffff);

	return true;
}
void CDrawManager::PreRender()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	m_pDevice->BeginScene();
}
void CDrawManager::Draw2D(LPDIRECT3DTEXTURE9 a_lpTexture, RECT a_rtSrc, D3DXVECTOR3 a_vCenter, D3DXVECTOR3 a_vPos, D3DCOLOR a_Color)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	try{
		if (a_lpTexture == NULL)
		{
			throw true;
		}
	}
	catch (bool a_bIsTextureNullException)
	{
		if (a_bIsTextureNullException)
		{
			MessageBox(NULL, "Texture NULL", "TextureNullException", MB_OK);
			std::cout << "Exception : TextureNullException - LPDIRECT3DTEXTURE9형 인자에 주소값이 Null입니다." << std::endl;
		}
	} 
	m_pSprite->Draw(a_lpTexture, &a_rtSrc, &a_vCenter, &a_vPos, a_Color);
	
	m_pSprite->End();
}
void CDrawManager::Draw3D()
{

}
void CDrawManager::PostRender()
{
	m_pDevice->EndScene();
	m_pDevice->Present(0, 0, 0, 0);
}
void CDrawManager::Release()
{
	SAFE_RELEASE(m_pMesh)
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pD3D);
}