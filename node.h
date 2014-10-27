/* 
 * File:   node.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:15 PM
 */

#ifndef NODE_H
#define	NODE_H

#include "object.h"


class node
{
    Object* data;
    node* prev;
    node* next;
  public:
    node();
    node(Object*);
    node(Object*, node*, node*);
    ~node();
    void print()const;
    node* getNext()const;
    node* getPrev()const;
    void setNext(node*);
    void setPrev(node*);
    Object* getData()const;
    void setData(Object*);
};

#endif	/* NODE_H */

