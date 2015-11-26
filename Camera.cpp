#include "Camera.h"
#include "Director.h"


CCamera::CCamera()
{
}


CCamera::~CCamera()
{
}

void CCamera::Init()
{
	_eye = D3DXVECTOR3(0.0f,3.0f,-50.0f);
	_lookAt = D3DXVECTOR3(0.0f,0.0f,0.0f);
	_up = D3DXVECTOR3(0.0f,1.0f,0.0f);
	D3DXMatrixIdentity(&_view);
	D3DXMatrixIdentity(&_proj);



	_isActive = false;
}
void CCamera::Update()
{
	if (getIsActive())
	{
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld); // 월드행렬을 단위행렬로 설정
		(*CDrawMgr->getDevice())->SetTransform(D3DTS_WORLD, &matWorld); // 월드행렬을 디바이스에 선언
		D3DXMatrixLookAtLH(&_view, &_eye, &_lookAt, &_up);
		(*CDrawMgr->getDevice())->SetTransform(D3DTS_VIEW, &_view);
		D3DXMatrixPerspectiveFovLH(&_proj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
		(*CDrawMgr->getDevice())->SetTransform(D3DTS_PROJECTION, &_proj);
	}
}

void CCamera::setEye(D3DXVECTOR3 a_Eye)
{
	_eye = a_Eye;
}
void CCamera::setLookAt(D3DXVECTOR3 a_LookAt)
{
	_lookAt = a_LookAt;
}
void CCamera::setUp(D3DXVECTOR3 a_Up)
{
	_up = a_Up;
}
void CCamera::setView(D3DXMATRIX a_View)
{
	_view = a_View;
}
void CCamera::setProj(D3DXMATRIX a_Proj)
{
	_proj = a_Proj;
}
void CCamera::setActive(bool a_isActive)
{
	_isActive = a_isActive;
}

D3DXVECTOR3 CCamera::getEye()
{
	return _eye;
}
D3DXVECTOR3 CCamera::getLookAt()
{
	return _lookAt;
}
D3DXVECTOR3 CCamera::getUp()
{
	return _up;
}
D3DXMATRIX CCamera::getView()
{
	return _view;
}
D3DXMATRIX CCamera::getProj()
{
	return _proj;
}

bool CCamera::getIsActive()
{
	return _isActive;
}