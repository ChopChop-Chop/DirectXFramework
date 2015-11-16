#pragma once
#include <d3dx9.h>

enum Result{ NONE = 0, ONEPOINT = 1, TWOPOINT = 2};

typedef Result E_RESULT;

class CCollisionManager
{
public:
	E_RESULT PointToPoint(D3DXVECTOR3* a_vPt1, D3DXVECTOR3* a_vPt2);
	E_RESULT PointToLine();
	E_RESULT PointToPlane();
	E_RESULT PointToRect();
	E_RESULT RectToRect();
	E_RESULT SphereToSphere();
	E_RESULT SphereToLine();


	CCollisionManager();
	~CCollisionManager();
};

