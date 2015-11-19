#pragma once
#include "Header.h"


class CDrawManager
{
public:	
	bool Init();
	bool InitWin();
	bool InitD3D();
	//void SetMetrices();
	void PreRender();
	void Draw2D(LPDIRECT3DTEXTURE9 a_lpTexture, RECT a_rtSrc, D3DXVECTOR3 a_vCenter, D3DXVECTOR3 a_vPos, D3DCOLOR a_Color);
	void Draw3D();
	void PostRender();
	void Release();

	LPDIRECT3D9 getD3D() { return m_pD3D; }
	LPDIRECT3DDEVICE9 getDevice() { return m_pDevice; }
	LPD3DXSPRITE getSprite() { return m_pSprite; }
	LPD3DXMESH getMesh() { return m_pMesh; }
	HWND getHWND() { return m_HWND; }

	/*
	void setCamera(CCamera* a_pCamera);
	CCamera m_pCurCamera;
	*/

	CDrawManager();
	~CDrawManager();
private:
	LPDIRECT3D9         m_pD3D;
	LPDIRECT3DDEVICE9    m_pDevice;
	LPD3DXSPRITE		   m_pSprite;
	LPD3DXMESH          m_pMesh;
	HWND				   m_HWND;

	RECT				   m_rtScreen;

};
