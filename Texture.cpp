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

	this->_fileName = temp->getFileName();
	this->_imgInfo = temp->getImgInfo();
	this->_rect = temp->getRect();
	this->_texture = temp->getTexture();

	return true;
	
}