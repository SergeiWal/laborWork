#include "stdafx.h"
#include "IT.h"

namespace IT
{
	IdTable Create(int size)
	{
		IdTable* it = new IdTable;
		if (size > TI_MAXSIZE)throw ERROR_THROW(120);
		it->maxsize = size;
		it->size = 0;
		it->table = new Entry[TI_MAXSIZE];
		return *it; 
	}

	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size == idtable.maxsize)throw ERROR_THROW(121);
		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		if (n >= idtable.size)throw ERROR_THROW(122);
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, Entry ent)
	{
		for (int i = 0; i < idtable.size;++i)
		{
			if (strcmp(idtable.table[i].id, ent.id) == 0 && strcmp(idtable.table[i].visibilityRegion, ent.visibilityRegion) == 0)return i;
		}

		if (ent.idtype == IT::F) 
		{
			for (int i = 0; i < idtable.size; i++)
			{
				if (strcmp(idtable.table[i].id, ent.id) == 0 && idtable.table[i].visibilityRegion[0]== '$')return i;
			}
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete[] &idtable;
	}
}