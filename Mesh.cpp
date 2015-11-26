#include "Mesh.h"
#include "Director.h"
#include "Define.h"


CMesh::CMesh()
{

	_pos = D3DXVECTOR3(0,0,0); // 위치
	_acp = D3DXVECTOR3(0,0,0); // 앵커포인트
	_scale = D3DXVECTOR3(0,0,0);	// 크기
	D3DXMatrixIdentity(&_mat); // 매트릭스
	_col = D3DXCOLOR(1,1,1,1);

	_degreeX = 0;
	_degreeY = 0;
	_degreeZ = 0;
	D3DXQuaternionIdentity(&_qut);

}


CMesh::~CMesh()
{
}

bool CMesh::Init(const char* a_sFileName)
{
	LPD3DXBUFFER pD3DXMtrlBuffer;		// 메터리얼 버퍼

										// Load the mesh from the specified file
	D3DXLoadMeshFromX(a_sFileName, D3DXMESH_SYSTEMMEM,
		CDrawMgr->getDevice(), NULL,
		&pD3DXMtrlBuffer, NULL, &_numMaterials,
		CDrawMgr->getMesh());

	// We need to extract the material properties and texture names from the 
	// pD3DXMtrlBuffer
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
	_materials = new D3DMATERIAL9[_numMaterials];
	_textures = new CTexture*[_numMaterials];

	for (DWORD i = 0; i < _numMaterials; i++)
	{
		// Copy the material
		_materials[i] = d3dxMaterials[i].MatD3D;

		// Set the ambient color for the material (D3DX does not do this)
		_materials[i].Ambient = _materials[i].Diffuse;

		if (d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlenA(d3dxMaterials[i].pTextureFilename) > 0)
		{
			// Create the texture
			_textures[i]->createTexture(d3dxMaterials[i].pTextureFilename);
		}
	}

	// Done with the material buffer
	pD3DXMtrlBuffer->Release();

	return true;
}
void CMesh::UpdateMatrix()
{
	D3DXQuaternionRotationYawPitchRoll(&_qut, D3DXToRadian(_degreeY), D3DXToRadian(_degreeX), D3DXToRadian(_degreeZ));

	D3DXMatrixTransformation(&_mat, &_acp, NULL, &_scale, &_acp, &_qut, &_pos);
}
void CMesh::Render()
{
	UpdateMatrix();

	// Meshes are divided into subsets, one for each material. Render them in
	// a loop
	for (DWORD i = 0; i < _numMaterials; i++)
	{
		// Set the material and texture for this subset
		CDrawMgr->getDevice()->SetMaterial(&_materials[i]);
		CDrawMgr->getDevice()->SetTexture(0, _textures[i]->getTexture());

		// Draw the mesh subset
		(*CDrawMgr->getMesh())->DrawSubset(i);
		
	}
}
void CMesh::Release()
{

}

void CMesh::setPos(D3DXVECTOR3 a_Pos)
{
	_pos = a_Pos;
}
void CMesh::setAcp(D3DXVECTOR3 a_Acp)
{
	_acp = a_Acp;
}
void CMesh::setScale(D3DXVECTOR3 a_Scale)
{
	_scale = a_Scale;
}
void CMesh::setMat(D3DXMATRIX a_Mat)
{
	_mat = a_Mat;
}
void CMesh::setColor(D3DXCOLOR a_Col)
{
	_col = a_Col;
}

D3DXVECTOR3 CMesh::getPos()
{
	return _pos;
}
D3DXVECTOR3 CMesh::getAcp()
{
	return _acp;
}
D3DXVECTOR3 CMesh::getScale()
{
	return _scale;
}
D3DXMATRIX CMesh::getMat()
{
	return _mat;
}
D3DXCOLOR CMesh::getColor()
{
	return _col;
}