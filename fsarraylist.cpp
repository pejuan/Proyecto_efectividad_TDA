#include "fsarraylist.h"
#include "object.h"
#include "tdalist.h"
#include <sstream>

fsarrayList::fsarrayList(int c) {
    capacity = c;
    data = new Object*[capacity];
}

fsarrayList::~fsarrayList() {
    delete[] data;
}

Object* fsarrayList::remove(unsigned int p) {
    if (isEmpty())
        return NULL;
    if (!(p >= 0 && p < size()))
        return NULL;

    Object* retval = data[p];

    if (p == size() - 1)
        data[p] = NULL;
    else {
        for (int i = p; i < size() - 1; i++)
            data[i] = data[i + 1];

        data[size() - 1] = NULL;
    }

    ssize--;
    return retval;
}

Object* fsarrayList::first() const {
    if (isEmpty())
        return NULL;

    return data[0];
}

Object* fsarrayList::last() const {
    if (isEmpty())
        return NULL;

    return data[size() - 1];
}

int fsarrayList::getCapacity() const {
    return capacity;
}

bool fsarrayList::isFull() const {
    return ssize == capacity;
}

void fsarrayList::clear() {
    delete[] data;

    data = new Object*[capacity];
    ssize = 0;
}

int fsarrayList::indexOf(Object* E) const {
    for (int i = 0; i < size(); i++) {
        if (data[i]->equals(E))
            return i;
    }

    return -1;
}

Object* fsarrayList::get(unsigned int p) const {
    if (isEmpty())
        return NULL;
    if (!(p >= 0 && p < size()))
        return NULL;

    return data[p];
}

bool fsarrayList::insert(Object *e, int p) { 
    if (isFull())
        return false;
    if (!((p >= 0) && (p <= size())))
        return false;
    if (isEmpty())
        data[p] = e;
    else {
        if (p == size())
            data[p] = e;
        else {
            for (int i = size() - 1; i >= p; i--)
                data[i + 1] = data[i];
            data[p] = e;
        }
    }
    ssize++;
    return true;
}

int fsarrayList::prev(int p) const {
    return (p - 1);
}

int fsarrayList::next(int p) const {
    return p + 1;
}

void fsarrayList::print()const {
    for (int i = 0; i < size(); i++)
        data[i]->print();
}
