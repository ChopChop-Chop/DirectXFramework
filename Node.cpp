#include "Node.h"
#include "Director.h"



CNode::CNode()
{
	m_sTag = new char(256);

}


CNode::~CNode()
{
}

bool CNode::Init()
{
	return true;
}
void CNode::Render()
{
	for (auto p : m_vChilds)
	{
		p->Render();
	}
}
void CNode::Release()
{
	for (int i = m_vChilds.size(); i > 0; i--)
	{
		m_vChilds.at(i)->Release();
	}
}

void CNode::setTag(char* a_sTag)
{
	m_sTag = a_sTag;

}

void CNode::addChild(CNode* a_Ref)
{
	for(auto p : m_vChilds)
	{
		if (p == a_Ref)
		{
			MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "AddChild Duplication", "AddChild Duplication", MB_OK);
			std::cout << "addChild Duplication Error - " << a_Ref->getTag()  << "is Already Exist" << std::endl;
			return;
		}
	}

	m_vChilds.push_back(a_Ref);
}

char* CNode::getTag()
{
	return m_sTag;
}

void CNode::removeChild(CNode* a_Ref)
{
	for (auto p : m_vChilds)
	{
		if (p == a_Ref)
		{
			p->Release();
			delete p;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeChild NullException", "removeChild NullException", MB_OK);
	std::cout << "removeChild NullException - " << a_Ref->getTag() << " is not exist" << std::endl;
}
void CNode::removeChildByTag(char* a_sTag)
{
	for (auto p : m_vChilds)
	{
		if (p->getTag == a_sTag)
		{
			p->Release();
			delete p;
			p = nullptr;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeChildByTag NullException", "removeChildByTag NullException", MB_OK);
	std::cout << "removeChildByTag NullException - " << a_sTag << " is not exist" << std::endl;
}
