#pragma once
#include <vector>

class CNode;

class CObjectManager
{
public:
	void addObject(CNode* a_Ref) throw (ObjectReferenceDuplicationException*);
	void removeObjectByTag(char* a_sTag) throw (ObjectReferenceNullException*);
	void removeObject(CNode* a_Ref) throw (ObjectReferenceNullException*);
	void clearPool();

	CNode* getObjectByTag(char* a_sTag) throw (ObjectReferenceDuplicationException*);
	CNode* getObjectByIndex(int a_nIndex) throw (ObjectReferenceDuplicationException*);

	CObjectManager();
	~CObjectManager();

private:
	std::vector<CNode*> m_vObjectPool;
};

