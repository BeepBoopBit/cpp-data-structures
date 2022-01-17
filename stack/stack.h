#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
public:
    Stack(int size){
        _stack = new int[size];
        _size = size;
    }
    Stack(){
        _stack = new int[10];
        _size = 10;
    }
    int peek(){
        return _stack[_top];
    }
    void push(int data){
        _stack[_top++] = data;
    }
    int pop(){
        return _stack[--_top];
    }
    bool isEmpty(){
        if(_size == 0){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(_top >= _size){
            return true;
        }
        return false;
    }

private:
    int _top = 0,
        _size = 0;
    int *_stack = nullptr;
};

#endif // STACK_H