#ifndef DOUBLYLIKEDLISTEND_H
#define DOUBLYLIKEDLISTEND_H

#include <iostream>

class DoublyLinkedList{
private:
    int _data, _size;
    DoublyLinkedList *_left, *_right, *_end;
public:
    DoublyLinkedList(){
        _data = 0;
        _size = 0;
        _left = nullptr;
        _right = nullptr;
        _end = this;
    }
    DoublyLinkedList(int data){
        _data = data;
        _size = 0;
        _left = nullptr;
        _right = nullptr;
        _end = this;
    }

public:

    // _end is maintained
    // O(1)
    void push_front(int data){
        if(_size == 0){
            _data = data;
        }else{
            int tempData = _data;
            _data = data;
            DoublyLinkedList *newRight = new DoublyLinkedList(tempData);
            if(_right != nullptr){
                newRight->_left = _right->_left;
                _right->_left = newRight;
                newRight->_right = _right;
                newRight->_end = _end;
            }else{
                newRight->_left = this;
            }
            _end = newRight->_end;
            _right = newRight;
        }
        ++_size;
    }
    // O(1)
    void push_back(int data){
        DoublyLinkedList *newBack = new DoublyLinkedList(data);
        _end->_right = newBack;
        newBack->_left = _end;
        _end = newBack;
        ++_size;
    }

    // O(n)
    void insert(int data, int index){
        DoublyLinkedList *head = this;
        if(index == 0){
            push_front(data);
            return;
        }else if(index == _size){
            push_back(data);
            return;
        }else if(index > _size){
            std::cout << "OUT OF BOUNCE" << std::endl;
            exit(-1);
        }
        for(int i = 0; i < index-1; ++i){
            head = head->_right;
        }
        DoublyLinkedList *newData = new DoublyLinkedList(data);
        newData->_right = head->_right;
        newData->_right->_left = newData;
        newData->_left = head;
        head->_right = newData;
        if(index == _size){
            _end = newData;
        }
        ++_size;
    }

    // O(1)
    void pop_back(){
        if(_size == 0){
            std::cout << "THERE'S NOTHING TO POP" << std::endl;
            exit(-1);
        }else if(_size == 1){
            // no reason to do anything
            --_size;
            return;
        }
        DoublyLinkedList *endLeft = _end->_left;
        endLeft->_right = nullptr;
        delete _end;
        _end = endLeft;
        --_size;
    }
    // O(1)
    void pop_front(){
        if(_size == 0){
            std::cout << "THERE'S NOTHING TO POP" << std::endl;
            exit(-1);
        }else if(_size == 1){
            // no reason to do anything
            --_size;
            return;
        }
        _data = _right->_data;
        DoublyLinkedList *tempRight = _right;
        _right = _right->_right;
        --_size;
        delete tempRight;
    }

    void remove(int index){
        checkOutOfBounce(index);
        if(index == 0){
            pop_front();
            return;
        }else if(index == _size-1){
            pop_back();
            return;
        }
        DoublyLinkedList *head = this;
        for(int i = 0; i < index-1; ++i){
            head = head->_right;
        }
        DoublyLinkedList *headRight = head->_right->_right;
        headRight->_left = head;
        delete head->_right;
        head->_right = headRight;
    }

    int size(){
        return _size;
    }

    DoublyLinkedList *end(){
        return _end;
    }

    DoublyLinkedList *begin(){
        return this;
    }

    void print(){
        DoublyLinkedList *head = this;
        while(head != nullptr){
            std::cout << head->_data     << std::endl;
            head =head->_right;
        }
    }
    void rPrint(){
        DoublyLinkedList *head = _end;
        while(head != nullptr){
            std::cout << head->_data << std::endl;
            head = head->_left;
        }
    }
private:
    void checkOutOfBounce(int value){
        if(value > _size){
            std::cout << "OUT OF BOUNCE" << std::endl;
            exit(-1);
        }
    }
};

#endif