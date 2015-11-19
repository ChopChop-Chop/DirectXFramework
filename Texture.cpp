#include "Texture.h"
#include "Define.h"



CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}


bool CTexture::createTexture(const char* a_sFileName)
{
	CTexture* temp = CTexMgr->createTexture(a_sFileName);

	if (temp == NULL)
		return false;

	this->m_sFileName = temp->getFileName();
	this->m_ImgInfo = temp->getImgInfo();
	this->m_rRect = temp->getRect();
	this->m_pTexture = temp->getTexture();

	return true;
	
}