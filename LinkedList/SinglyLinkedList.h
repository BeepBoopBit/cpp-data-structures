#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

class SinglyLinkedList{

private: // Node
    struct Node{
        int value;
        Node *next = nullptr;
    };

public: // constructors
    SinglyLinkedList(){
        _head = nullptr;
        _tail = nullptr;
    }


public: // functions
    void push_front(int value){
        // store the current head
        Node *prevHead = _head;
        
        // replace the current head with a new node
        _head = createNewNode();

        // assign its value to be the new value
        _head->value = value;

        // assign the value of the new head to the previous head;
        _head->next = prevHead;

        // if it's the first data
        if(_tail == nullptr){
            _tail = _head;
        }
        ++_size;
    }

    void push_back(int value){
        if(_tail == nullptr){
            push_front(value);
        }else{
            _tail->next = createNewNode();
            _tail->next->value = value;
            _tail = _tail->next;
        }
        ++_size;
    }

    void pop_back(){
        Node *tempHead = _head;
        while(tempHead->next->next != nullptr){
            tempHead = tempHead->next;
        }
        delete tempHead->next;
        _tail = tempHead;
        tempHead->next = nullptr;
        --_size;
    }

    void pop_front(){
        Node *tempHead = _head;
        _head = _head->next;
        delete tempHead;
        --_size;
    }

    void removeAt(int index){
        if(index >= _size){
            std::cout << "Index out-of-bounce\n";
            exit(-1);
        }else if(index == _size-1){
            pop_back();
        }else if(index == 0){
            pop_front();
        }else{
            Node *tempHead = _head;
            // iterate through the list until you are at the index
            for(int i = 0; i < index-1; ++i){
                tempHead = tempHead->next;
            }
            Node *tempNodeNext = tempHead->next;
            tempHead->next = tempHead->next->next;
            delete tempNodeNext;
        }
        --_size;
    }

public: // getters
    int front(){
        if(_head == nullptr){
            std::cout << "Index out-of-bounce\n";
            exit(-1);
        }
        return _head->value;
    }
    int back(){
        if(_tail == nullptr){
            std::cout << "Index out-of-bounce\n";
            exit(-1);
        }
        return _tail->value;
    }

    int getValueAt(int index){
        if(index > _size){
            std::cout << "Index out-of-bounce\n";
            exit(-1);
        }
        Node *tempHead = _head;
        for(int i = 0; i < index; ++i){
            tempHead = tempHead->next;
        }
        return tempHead->value;
    }

public: // Debug
    void print(){
        Node *tempHead = _head;
        while(tempHead != nullptr){
            std::cout << tempHead->value << ' ';
            tempHead = tempHead->next;
        }
        std::cout << std::endl;
    }

private: // Auxillary FUnction
    Node *createNewNode(){
        return new Node();
    }

private:
    Node *_head, *_tail;
    int _size = 0;

};

#endif // SINGLY_LINKED_LIST_H