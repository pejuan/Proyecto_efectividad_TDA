/* 
 * File:   integer.h
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:19 PM
 */

#ifndef INTEGER_H
#define	INTEGER_H

#include "object.h"


class Integer : public Object{
    int value;
  public:
    Integer(int=0);
    virtual ~Integer();
    virtual void print()const;
    virtual string toString()const;
    virtual bool equals(Object*)const;
    void setValue(int);
    int getValue()const;  
};

#endif	/* INTEGER_H */

