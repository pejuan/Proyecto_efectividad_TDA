/* 
 * File:   slnode.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:26 PM
 */

#ifndef SLNODE_H
#define	SLNODE_H
#include "object.h"

class SLNode{
Object* data;
SLNode* next;
public:
SLNode();
SLNode(Object*);
SLNode(Object*,SLNode*);
~SLNode();
void print()const;
SLNode* getNext()const;
void setNext(SLNode*);
Object* getData()const;
void setData(Object*);
};

#endif


