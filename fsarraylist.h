/* 
 * File:   fsarraylist.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:17 PM
 */

#ifndef FSARRAYLIST_H
#define	FSARRAYLIST_H

#include "tdalist.h"
#include "object.h"

class fsarrayList : public TDAList
{
public:
fsarrayList(int);
virtual ~fsarrayList();
virtual bool insert(Object*,int);
virtual Object* remove(unsigned int);
virtual Object* first() const;
virtual Object* last() const;
virtual int getCapacity() const;
virtual bool isFull() const;
virtual void clear();
virtual Object* get(unsigned int) const;
virtual void print()const;
virtual int indexOf(Object* E) const ;/////////////
virtual int prev(int) const;
virtual int next(int) const;

private:
unsigned int capacity;
Object** data;
};



#endif	/* FSARRAYLIST_H */

