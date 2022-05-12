#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class DoublyLinkedList{
private:
    struct Node{
        int value;
        Node *prev, *next;
    };

public:
    DoublyLinkedList(){
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }

public:
    void push_front(int value){
        Node *tempHead = _head;
        _head = createNewNode(value);
        _head->next = tempHead;
        // _head->prev = nullptr; // already done in createNewNode
        if(tempHead != nullptr){
            tempHead->prev = _head;
        }else{
            _tail = _head;
        }
        ++_size;
    }

    void push_back(int value){
        if(_tail == nullptr){
            push_front(value);
        }else{
            _tail->next = createNewNode(value, _tail);
            _tail = _tail->next;
        }
        ++_size;
    }

    void pop_front(){
        Node *tempHead = _head;
        _head = _head->next;
        _head->prev = nullptr;
        delete tempHead;
        --_size;
    }

    void pop_back(){
        Node *tempTail = _tail;
        _tail = _tail->prev;
        _tail->next = nullptr;
        delete tempTail;
        --_size;
    }
    void remove(int value){
        Node *tempHead = _head;
        while(tempHead != nullptr){
            if(tempHead->value == value){
                break;
            }
            tempHead = tempHead->next;
        }

        if(tempHead == _head){
            pop_front();
        }else if(tempHead == _tail){
            pop_back();
        }else{
            // assign the tempHead before the value to be removed
            tempHead = tempHead->prev;

            // get the value to be removed
            Node *tempNode = tempHead->next;

            // make the next of the tempHead be the next of the value to be removed
            tempHead->next = tempNode->next;

            // make the previous of the new next node of tempHead be the tempHead;
            tempHead->next->prev = tempHead;

            // delete the tempNode
            delete tempNode;
        }
        --_size;
    }

    void removeAt(int index){
        if(index == 0){
            pop_front();
        }else if(index == _size-1){
            pop_back();
        }else if(index >= _size){
            std::cout << "Index out-of-bounce\n";
            exit(-1);
        }else{
            Node *tempHead = _head;
            for(int i = 0; i < index-1; ++i){
                tempHead = tempHead->next;
            }
            // get the value to be remove
            Node *tempNode = tempHead->next;

            // assigned the tempHead next value to the next value of the tempNode 
            tempHead->next = tempNode->next;

            // initialize the previous value of the next node of tempNode to the current tempHead
            tempHead->next->prev = tempHead;

            delete tempNode;
        }
    }

public: // debug
    void print(){
        Node *tempHead = _head;
        while(tempHead != nullptr){
            std::cout << tempHead->value << ' ';
            tempHead = tempHead->next;
        }
        std::cout << std::endl;
    }

    void rprint(){  
        Node *tempTail = _tail;
        while(tempTail != nullptr){
            std::cout << tempTail->value << ' ';
            tempTail = tempTail->prev;
        }
        std::cout << std::endl;

    }

private: // auxillary functions
    Node *createNewNode(int value, Node *prev = nullptr, Node *next = nullptr){
        Node *tempNode = new Node();
        tempNode->value = value;
        tempNode->prev = prev;
        tempNode->next = next;
        return tempNode;
    }

private:
    Node *_head, *_tail;
    int _size;

};

#endif // DOUBLY_LINKED_LIST_H