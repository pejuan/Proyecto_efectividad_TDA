#include "integer.h"
#include "object.h"
#include <iostream>
#include <sstream>
using namespace std;

Integer::Integer(int aValue){
    value = aValue;
}

Integer::~Integer(){
}

void Integer::print()const{
    cout <<value<< endl;
}

string Integer::toString()const{
	stringstream ss;
	ss << value;
	return ss.str();
}

bool Integer::equals(Object* other)const{
    if (other == NULL)
        return false;
    if (dynamic_cast<Integer*>(other) == NULL)
        return false; 
    Integer* tempInteger = dynamic_cast<Integer*>(other);
    return tempInteger->getValue() == value;
}

void Integer::setValue(int newValue){
    value = newValue;
}

int Integer::getValue()const{
    return value;
}  


