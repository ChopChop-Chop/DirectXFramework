#include "CollisionManager.h"


CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
}

bool CCollisionManager::PointToPoint(D3DXVECTOR3* a_vPt1, D3DXVECTOR3* a_vPt2)
{

}
bool CCollisionManager::PointToLine(const D3DXVECTOR3* V, const D3DXVECTOR3* a_vPt1, const D3DXVECTOR3* a_vPt2, FLOAT fEpsilon = 0.0001)
{

}
bool CCollisionManager::PointToPlane(const D3DXVECTOR3* P, const D3DXVECTOR3* N, float D, float fEpsilon = 0.0001)
{

}
bool CCollisionManager::PointToRect(const D3DXVECTOR3 a_vPt, RECT a_Rect)
{

}
bool CCollisionManager::RectToRect(RECT a_Rect1, RECT a_Rect2)
{

}
bool CCollisionManager::SphereToSphere(const D3DXVECTOR3* SphereCenter1, float SphereRadius1, const D3DXVECTOR3* SphereCenter2, float SphereRadius2)
{

}
bool CCollisionManager::SphereToLine(const D3DXVECTOR3* SphereCenter, float SphereRadius, const D3DXVECTOR3* LineBegin, const D3DXVECTOR3* LineDirection)
{

}