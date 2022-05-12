#ifndef STACK_H
#define STACK_H

#include <iostream>

// Stack using Linked List
class Stack{
private:
    struct Node{
        int value;
        Node *next;
    };

public:
    Stack(){
        _top = nullptr;
        _size = 0;
    }

public:
    int pop(){
        int tempValue = _top->value;
        Node *tempTop = _top;
        _top = _top->next;
        delete tempTop;
        --_size;
        return tempValue;
    }

    void push(int value){
        Node *newTop = new Node();
        newTop->value = value;
        newTop->next = _top;
        _top = newTop;
        ++_size;
    }

    int size(){
        return _size;
    }

private:

private:
    Node *_top;
    int _size;

};

#endif // STACK_H