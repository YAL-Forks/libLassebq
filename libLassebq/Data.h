#pragma once
#include <unordered_map>
#include "GMLConstants.h"
#define MAKE_EV_KEY(_Type, _Subtype) (_Subtype##ull | _Type##ull << 0x20ull)

constexpr unsigned long long makeevkey(unsigned long long type, unsigned long long subtype)
{
	return (subtype | type << 0x20ull);
}

extern std::unordered_map<unsigned long long, std::string> mapOfEvents;

enum eDeleteType : int
{
	eDelete_placementdelete = 3,
	eDelete_delete = 1,
	eDelete_free = 2,
	eDelete_none = 0
};

struct SLink;

struct SLinkListEx {
	SLink * head;
	SLink * tail;
	int offset;
};

struct SLink {
	SLink * next;
	SLink * prev;
	SLinkListEx * list;
};

template<typename T>
class HashNode {
public:
	HashNode<T>* m_pPrev;
	HashNode<T>* m_pNext;
	unsigned int m_ID;
	T* m_pObj;
};

template<typename T>
class HashLink {
public:
	T* m_pFirst;
	T* m_pLast;
};

template<typename T>
class CHash {
public:
	HashLink<HashNode<T>> *m_pHashingTable;
	int m_HashingMask;
	int m_Count;
};

typedef unsigned int Hash;

template<class K, class V, int I>
class Element {
public:
	V v; // Value
	K k; // Key
	Hash hash; // Hash
};

template<class K, class V, int I = 3>
class CHashMap {
public:
	int m_curSize;
	int m_numUsed;
	int m_curMask;
	int m_growThreshold;
	Element<K, V, I>* m_elements;

	int GetIdealPosition(Hash _h)
	{
		return this->m_curMask & _h;
	}
};

template<class T>
struct SLinkedListNode {
	SLinkedListNode* m_pNext;
	SLinkedListNode* m_pPrev;
	T* m_pObj;
};

template<class T>
struct SLinkedList {
	SLinkedListNode<T>* m_pFirst;
	SLinkedListNode<T>* m_pLast;
	int m_Count;
	//eDeleteType m_DeleteType;
};

template<class T>
class cARRAY_STRUCTURE {
	int Length;
	T * Array;
};

class cARRAY_OF_POINTERS {
	int Length;
	int m_slotsUsed;
	int m_reserveSize;
	void** Array;
};

template<class T>
class OLinkedList {
public:
	T* m_pFirst;
	T* m_pLast;
	int m_Count;
	eDeleteType m_DeleteType;
};

template<class T>
class LinkedList {
	T* m_pFirst;
	T* m_pLast;
	int m_Count;
	eDeleteType m_DeleteType;
};