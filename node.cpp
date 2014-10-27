#include "node.h"
#include "object.h"
#include <iostream>
using namespace std;

node::node(){
    next = prev = NULL;
    data = NULL;
}

node::node(Object* newData){
    data = newData;
}

node::node(Object* newData, node* newPrev, node* newNext){
    data = newData;  
    prev = newPrev;
    next = newNext;
}

node::~node(){
    if (data)
        delete data;
    if (next)
        delete next;
}

void node::print()const{
    data->print();
}

node* node::getNext()const{
    return next;
}

node* node::getPrev()const{
    return prev;
}

void node::setPrev(node* newPrev){
    prev = newPrev;
}

void node::setNext(node* newNext){
    next = newNext;
}

Object* node::getData()const{
    return data;
}

void node::setData(Object* newData){
    data = newData;
}

