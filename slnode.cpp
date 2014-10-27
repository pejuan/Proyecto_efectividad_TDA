#include "slnode.h"
#include "object.h"
#include <iostream>
using namespace std;

SLNode::SLNode() {
    next = NULL;
    data = NULL;
}

SLNode::SLNode(Object* newData) {
    data = newData;
}

SLNode::SLNode(Object* newData, SLNode* newNext) {
    data = newData;
    next = newNext;
}

SLNode::~SLNode() {

    if (data)
        delete data;
    if (next)
        delete next;
}

void SLNode::print()const {
    data->print();
}

SLNode* SLNode::getNext()const {
    return next;
}

void SLNode::setNext(SLNode* newNext) {
    next = newNext;
}

Object* SLNode::getData()const {
    return data;
}

void SLNode::setData(Object* newData) {
    data = newData;
}

