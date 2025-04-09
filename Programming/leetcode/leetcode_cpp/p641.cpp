#include <iostream>
#include <list>
using namespace std;

class MyCircularDeque {
   public:
    int capacity;
    int size;
    list<int> vowl;
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
    }

    bool insertFront(int value) {
        if (size < capacity) {
            vowl.push_front(value);
            size++;
            return true;
        } else
            return false;
    }

    bool insertLast(int value) {
        if (size < capacity) {
            vowl.push_back(value);
            size++;
            return true;
        } else
            return false;
    }

    bool deleteFront() {
        if (size > 0) {
            vowl.pop_front();
            size--;
            return true;
        } else
            return false;
    }

    bool deleteLast() {
        if (size > 0) {
            vowl.pop_back();
            size--;
            return true;
        } else
            return false;
    }

    int getFront() {
        if (size > 0)
            return vowl.front();
        else
            return -1;
    }

    int getRear() {
        if (size > 0)
            return vowl.back();
        else
            return -1;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */