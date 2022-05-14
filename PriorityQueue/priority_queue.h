#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "heap.h"

class PriorityQueue{
private:
    Heap _heap;

public:
    PriorityQueue(){
    }
public:
    void pop(){
        _heap.pop_max();
    }
    void push(int value){
        _heap.push(value);
    }
    int peek(){
        return _heap.peek();
    }
    void remove(int value){
        _heap.remove(value);
    }
};

#endif // PRIORITY_QUEUE