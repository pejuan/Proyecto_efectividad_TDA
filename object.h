/* 
 * File:   object.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:27 PM
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include <string>
using namespace std;

class Object
{
  public:
    Object();
    virtual ~Object();
    virtual void print()const;
    virtual string toString()const;
    virtual bool equals(Object*)const;
};

#endif	/* OBJECT_H */

