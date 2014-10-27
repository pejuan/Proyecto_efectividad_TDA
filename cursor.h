/* 
 * File:   cursor.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:12 PM
 */

#ifndef CURSOR_H
#define	CURSOR_H
#include "tdalist.h"

class cursor : public TDAList
{
	struct Registry
	{
		int prev, next;
		Object* datum;
	};

	Registry* map;
	int head;
	int capacity;
	int findNextSlot() const;

public:
	cursor(int=25);
	~cursor();
	virtual bool insert(Object*, int);
    virtual int indexOf(Object*) const;
  	virtual Object* get(unsigned) const;
	virtual Object* remove(unsigned);
	virtual int prev(int) const;
	virtual int next(int) const;
	virtual void clear();
	virtual Object* first() const;
	virtual Object* last() const;
	virtual void print() const;
	virtual bool isFull() const;
};



#endif	/* CURSOR_H */

