#pragma once
#include "Node.h"
#include "Texture.h"

class CMesh : public CNode
{
public:

	bool Init(const char* a_sFileName);
	void UpdateMatrix();
	void Render();
	void Release();

	void setPos(D3DXVECTOR3 a_Pos);
	void setAcp(D3DXVECTOR3 a_Acp);
	void setScale(D3DXVECTOR3 a_Scale);
	void setMat(D3DXMATRIX a_Mat);
	void setColor(D3DXCOLOR a_Col);
	void setDegreeX(float a_DegreeX) { _degreeX = a_DegreeX; }
	void setDegreeY(float a_DegreeY) { _degreeY = a_DegreeY; }
	void setDegreeZ(float a_DegreeZ) { _degreeZ = a_DegreeZ; }

	D3DXVECTOR3 getPos(); // ��ġ
	D3DXVECTOR3 getAcp(); // ��Ŀ����Ʈ
	D3DXVECTOR3 getScale();	// ũ��
	D3DXMATRIX getMat(); // ��Ʈ����
	D3DXCOLOR getColor();
	float getDegreeX() { return _degreeX; }
	float getDegreeY() { return _degreeY; }
	float getDegreeZ() { return _degreeZ; }

	CMesh();
	virtual ~CMesh();
private:
	D3DMATERIAL9* _materials; // �޽��� ����
	CTexture** _textures; // �Ž��� �ؽ���
	DWORD _numMaterials; // �޽��� ���� ����

	D3DXVECTOR3 _pos; // ��ġ
	D3DXVECTOR3 _acp; // ��Ŀ����Ʈ
	D3DXVECTOR3 _scale;	// ũ��
	D3DXMATRIX _mat; // ��Ʈ����
	D3DXCOLOR _col;
	D3DXQUATERNION _qut;
	LPD3DXBUFFER _mtrlBuffer;
	D3DXMATERIAL* _d3dxMaterials;

	float _degreeX;
	float _degreeY;
	float _degreeZ;
};

