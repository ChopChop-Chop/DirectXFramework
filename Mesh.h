#pragma once
#include "Node.h"
#include "Texture.h"

class CMesh : public CNode
{
public:
	CMesh();
	virtual ~CMesh();
private:
	D3DMATERIAL9* pMeshMaterials; // �޽��� ����
	CTexture* MeshTextures; // �Ž��� �ؽ���
	DWORD dwNumMaterials; // �޽��� ���� ����

	D3DXVECTOR3 m_vPos; // ��ġ
	D3DXVECTOR3 m_vAcp; // ��Ŀ����Ʈ
	D3DXVECTOR3 m_vScale;	// ũ��
	D3DXMATRIXA16 m_mMat; // ��Ʈ����
	D3DXCOLOR m_Col;

};

