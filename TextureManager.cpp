#include "TextureManager.h"
#include "Texture.h"
#include "Director.h"

CTextureManager::CTextureManager()
{
}


CTextureManager::~CTextureManager()
{
}

CTexture* CTextureManager::createTexture(const char* a_sFileName)
{
	for (auto p : m_vTextureInfo)
	{
		if (p->getFileName() == a_sFileName)
		{
			return p;
		}
	}

	CTexture* temp = new CTexture();
	LPDIRECT3DTEXTURE9 tex = temp->getTexture();

	D3DXCreateTextureFromFileEx(CDrawMgr->getDevice(), a_sFileName, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL,
		&temp->getImgInfo(), NULL, &tex);

	temp->setTexture(tex);
	
	return temp;
}