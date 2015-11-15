#pragma once
#include "Header.h"


class CNode
{
public:
	virtual bool Init();
	virtual void Render();
	virtual void Release();

	void setTag(char* a_sTag);
	void addChild(CNode* a_Ref);
	void removeChild(CNode* a_Ref);
	void removeChildByTag(char* a_sTag);
	char* getTag();

	CNode();
	virtual ~CNode();
protected:
	std::vector<CNode*> m_vChilds;

	char* m_sTag;
};

