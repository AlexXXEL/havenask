/*********************************************************************
 * $Author: santai.ww $
 *
 * $LastChangedBy: santai.ww $
 * 
 * $Revision: 9613 $
 *
 * $LastChangedDate: 2012-01-06 22:04:49 +0800 (Fri, 06 Jan 2012) $
 *
 * $Id: CacheItem.h 9613 2012-01-06 14:04:49Z santai.ww $
 *
 * $Brief: �ײ�cache�Ĵ洢��Ԫ�� $
 ********************************************************************/

#ifndef KINGSO_CACHE_CACHEITEM_H
#define KINGSO_CACHE_CACHEITEM_H

#include <stdint.h>

BEGIN_HA3_NAMESPACE(util);

typedef uint64_t u_n64_t;
typedef uint32_t u_n32_t;
typedef uint16_t u_n16_t;
typedef uint8_t  u_n8_t;
typedef int64_t n64_t;
typedef int32_t n32_t;
typedef int16_t n16_t;
typedef int8_t  n8_t;

/* lessThan�Ƚ�ģ���� */
template <typename Key>
struct KeyCompare {
};
/* �޷����������ͱȽϺ���,С�ڷ���true */
template<> 
struct KeyCompare<unsigned int> {
	inline bool operator()(const unsigned int nKey1, const unsigned int nKey2) const { 
		return nKey1 < nKey2;
	}
};
/* ���ֲ��Һ���,���ز�С�ڱȽ�ֵ������Ԫ�� */
template < typename Type, typename Compare = KeyCompare<Type> >
struct BinarySearch {
	Compare comp;
	inline n32_t operator()(Type *szElements, n32_t nBegin, n32_t nEnd, Type _Value) {
		n32_t nPos;
		while (nBegin <= nEnd) {
			nPos = (nBegin + nEnd) / 2;
			if (!comp(szElements[nPos], _Value)) {
				nEnd = nPos - 1;
			}
			else {
				nBegin = nPos + 1;
			}
		}
		return nBegin; 
	}
};

struct CacheItem {
  	CacheItem(): key(0), hash_next(NULL) {}
	u_n64_t   key; //��item����Ĳ�ѯkey
	CacheItem  *hash_next; //��map�ж�Ӧ��nextָ��
};

END_HA3_NAMESPACE(util);

#endif
