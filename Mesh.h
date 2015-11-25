#pragma once
#include "Node.h"
#include "Texture.h"

class CMesh : public CNode
{
public:
	CMesh();
	virtual ~CMesh();
private:
	D3DMATERIAL9* pMeshMaterials; // 메쉬의 재질
	CTexture* MeshTextures; // 매쉬의 텍스쳐
	DWORD dwNumMaterials; // 메쉬의 재질 개수

	D3DXVECTOR3 m_vPos; // 위치
	D3DXVECTOR3 m_vAcp; // 앵커포인트
	D3DXVECTOR3 m_vScale;	// 크기
	D3DXMATRIXA16 m_mMat; // 매트릭스
	D3DXCOLOR m_Col;

};

