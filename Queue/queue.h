#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

// implementation using linked list
class Queue{
private:
    struct Node{
        int value;
        Node* next;
    };
public:
    Queue(){
        _size = 0;
        _head = nullptr;
        _tail = nullptr;
    }

public:
    void enqueue(int value){
        if(_tail == nullptr){
            _tail = new Node();
            _head = _tail;
        }else{
            _tail->next = new Node();
            _tail = _tail->next;
        }
        _tail->value = value;
        _tail->next = nullptr;
        ++_size;
    }
    int dequeue(){
        if(_head == nullptr){
            std::cout << "No Data in Queue" << std::endl;
            exit(-1);
        }
        int tempValue = _head->value;
        Node *tempHead = _head;
        _head = _head->next;
        delete tempHead;
        --_size;
        return tempValue; 
    }
    int peek(){
        return _head->value;
    }
    int size(){
        return _size;
    }
private:
    int _size;
    Node *_head, *_tail;
};


#endif // QUEUE_H