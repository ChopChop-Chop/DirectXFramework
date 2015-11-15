#include "ObjectManager.h"
#include "Node.h"
#include "Director.h"
#include <iostream>

CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
}

void CObjectManager::addObject(CNode* a_Ref)
{
	for (auto p : m_vObjectPool)
	{
		if (p == a_Ref)
		{
			MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "AddChild Duplication", "AddChild Duplication", MB_OK);
			std::cout << "addChild Duplication Error - " << a_Ref->getTag() << "is Already Exist" << std::endl;
			return;
		}
	}

	m_vObjectPool.push_back(a_Ref);
}
void CObjectManager::removeObjectByTag(char* a_sTag)
{
	for (auto p : m_vObjectPool)
	{
		if (p->getTag == a_sTag)
		{
			p->Release();
			delete p;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeObjectByTag NullException", "removeObjectByTag NullException", MB_OK);
	std::cout << "removeObjectByTag NullException - " << a_sTag << " is not exist" << std::endl;
}
void CObjectManager::removeObject(CNode* a_Ref)
{
	for (auto p : m_vObjectPool)
	{
		if (p == a_Ref)
		{
			p->Release();
			delete p;
			p = nullptr;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeObject NullException", "removeObject NullException", MB_OK);
	std::cout << "removeObject NullException - " << a_Ref->getTag() << " is not exist" << std::endl;
}
CNode* CObjectManager::getObjectByTag(char* a_sTag)
{
	for (auto p : m_vObjectPool)
	{
		if (p->getTag() == a_sTag)
		{
			return p;
		}
	}
	return NULL;
}
CNode* CObjectManager::getObjectByIndex(int a_nIndex)
{
	if (m_vObjectPool.at(a_nIndex) == NULL)
	{
		MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "can not find Object", "can not find object", MB_OK);
		std::cout << "can not found object by index" << a_nIndex << std::endl;
		return NULL;
	}
	else
	{
		return m_vObjectPool.at(a_nIndex);
	}
	

	
}

void CObjectManager::clearPool()
{
	for (int i = m_vObjectPool.size(); i > 0; i--)
	{
		m_vObjectPool.at(i)->Release();
		delete m_vObjectPool.at(i);
	}
	m_vObjectPool.clear();

	
}