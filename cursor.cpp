#include "cursor.h"
#include <iostream>
using namespace std;

cursor::cursor(int n)
{
	capacity = n;
	map = new Registry[capacity];
	for(int i = 0; i < capacity; i++)
	{
		if(map[i].datum)
			map[i].datum = NULL;

		map[i].prev = -1;
		map[i].next = -1;
	}
}


cursor::~cursor()
{
	delete[] map;
}


bool cursor::insert(Object* o, int i)
{
	if(i < 0 || i > ssize)
		return false;

	if(o == NULL)
		return false;

	if(ssize == capacity)
		return false;

	int neo = findNextSlot();

	if(neo == -1)
	{
		return false;
	}
	else
	{
		map[neo].datum = o;
	

		if(i == 0)
		{
			if(ssize != 0)
			{
				map[neo].next = head;
				map[head].prev = neo;
			}
			head = neo;
		}
		else
		{
			int tmp = head;
			for(int j = 0; j < i-1; j++)
			{
				tmp = map[tmp].next;
			}
			map[neo].prev = tmp;
			map[neo].next = map[tmp].next;
			map[tmp].next = neo;
			if(i < ssize)
			{
				map[map[neo].next].prev = neo;
			}
		}

		ssize++;
		return true;
	}
}		

int cursor::indexOf(Object* object) const
{
	int i = -1;

	if(ssize > 0)
	{
		int tmp = head;

		for(int j = 0; j < ssize-1; j++)
		{
			if((map[tmp].datum)->equals(object))
			{
				i = j;
				break;
			}
			
			tmp = map[tmp].next;
		}
	}
	
	return i;
}

Object* cursor::get(unsigned i) const
{
	if(i < 0 || i >= ssize)
	{
		return NULL;
	}
	else
	{
		int tmp = head;

		for(int j = 0; j < i; j++)
			tmp = map[tmp].next;

		return map[tmp].datum;
	}
}

Object* cursor::remove(unsigned i)
{
	if(i < 0 || i >= ssize || ssize == 0)
	{
		return NULL;
	}
	else
	{
		Object* ret;	

		if(i == 0)
		{
			int tmp = head;
			ret = map[tmp].datum;
			map[tmp].datum = NULL;
			head = map[tmp].next;
			map[head].prev = -1;
			map[tmp].next = -1;
		}
		else
		{
			int tmp = head;
			for(int j = 0; j < i; j++)
			{
				tmp = map[tmp].next;
			}

			ret = map[tmp].datum;
			map[tmp].datum = NULL;
			map[map[tmp].prev].next = map[tmp].next;

			if(i != ssize-1)
			{
				map[map[tmp].next].prev = map[tmp].prev;

				map[tmp].next = -1;
			}
			map[tmp].prev = -1;
		}
		
		ssize--;
		return ret;
	}
}


int cursor::prev(int i) const
{
	if(i < 0 || i >= ssize || ssize == 0)
	{
		return -1;
	}
	else
	{
		return map[i].prev;
	}
}

int cursor::next(int i) const
{
	if(i < 0 || i >= ssize || ssize == 0)
	{
		return -1;
	}
	else
	{
		return map[i].next;
	}
}

void cursor::clear()
{
	if(ssize != 0)
	{
		for(int i = 0; i < ssize; i++)
		{
			if(map[i].datum)
			{
				map[i].prev = -1;
				map[i].next = -1;
				delete map[i].datum;
			}
		}
		
		ssize = 0;
	}
}

Object* cursor::first() const
{
	if(ssize == 0)
	{
		return NULL;
	}
	else
	{
		return map[head].datum;
	}
}

Object* cursor::last() const
{
	if(ssize == 0)
	{
		return NULL;
	}
	else
	{
		int tmp = head;

		for(int i = 0; i < ssize-1; i++)
		{
			tmp = map[tmp].next;
		}

		return map[tmp].datum;
	}
}
	
void cursor::print() const
{
	int tmp = head;

	for(int i = 0; i < ssize; i++)
	{
		map[tmp].datum->print();
		tmp = map[tmp].next;
	}
}

bool cursor::isFull() const
{
	return (ssize == capacity);
}

int cursor::findNextSlot() const
{

	int retval = -1;

	for(int i = 0; i < capacity; i++)
	{
		if(!map[i].datum)
		{
			retval = i;
			break;
		}
	}

	return retval;
}

