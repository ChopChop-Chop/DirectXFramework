#pragma once
#include "Header.h"

class CTexture
{
public:
	bool createTexture(const char* a_sFileName);

	__inline LPDIRECT3DTEXTURE9 getTexture();
	__inline char* getFileName();
	__inline RECT getRect();
	__inline D3DXIMAGE_INFO getImgInfo();
	

	__inline void setTexture(LPDIRECT3DTEXTURE9 a_pTexture);
	__inline void setFileName(const char* a_sFileName);
	__inline void setRect(RECT a_rRect);
	__inline void setImgInfo(D3DXIMAGE_INFO a_sImgInfo);

	CTexture();
	virtual ~CTexture();
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	char* m_sFileName;
	RECT m_rRect;
	D3DXIMAGE_INFO m_ImgInfo;

};
__inline LPDIRECT3DTEXTURE9 CTexture::getTexture()
{
	return m_pTexture;
}
__inline char* CTexture::getFileName()
{
	return m_sFileName;
}
__inline RECT CTexture::getRect()
{
	return m_rRect;
}
__inline D3DXIMAGE_INFO CTexture::getImgInfo()
{
	return m_ImgInfo;
}

__inline void CTexture::setTexture(LPDIRECT3DTEXTURE9 a_pTexture)
{
	m_pTexture = a_pTexture;
}
__inline void CTexture::setFileName(const char* a_sFileName)
{
	m_sFileName = new char(sizeof(a_sFileName));

	strcpy(m_sFileName, a_sFileName);
}
__inline void CTexture::setRect(RECT a_rRect)
{
	m_rRect = a_rRect;
}
__inline void CTexture::setImgInfo(D3DXIMAGE_INFO a_ImgInfo)
{
	m_ImgInfo = a_ImgInfo;
}