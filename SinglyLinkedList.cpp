#include <iostream>

class SinglyLinkedList{
public:
    SinglyLinkedList(){
        _data = 0;
        _next = nullptr;
    }
    SinglyLinkedList(int data){
        _data = data;
        _next = nullptr;
    }
    void push_back(int data){
        SinglyLinkedList *tempHead = this;
        while(tempHead->_next != nullptr){
            tempHead = tempHead->_next;
        }
        tempHead->_next = new SinglyLinkedList(data);
    }
    SinglyLinkedList *push_front(int data){
        SinglyLinkedList *newHead = new SinglyLinkedList(data);
        newHead->_next = this;
        return newHead;
    }
    void tPush_front(int data){
        // create a new list with the current head data
        SinglyLinkedList *newVal = new SinglyLinkedList(_data);
        newVal->_next = _next;

        // set the current data to the new data
        _data = data;
        _next = newVal;
    }
    void insert(int index, int data){
        if(index == 0){
            tPush_front(data);
            return;
        }
        SinglyLinkedList *tempHead = this;
        for(int i = 0; i < index-1; ++i){
            tempHead = tempHead->_next;
        }
        SinglyLinkedList *tempNext = tempHead->_next;
        tempHead->_next = new SinglyLinkedList(data);
        tempHead->_next->_next = tempNext;
    }
    void print(){
        SinglyLinkedList *tempHead = this;
        while(tempHead != nullptr){
            std::cout << tempHead->_data << ' ';
            tempHead = tempHead->_next;
        }
    }
    SinglyLinkedList *reverse(){
        SinglyLinkedList *prev = nullptr,
                   *curr = this,
                   *next = nullptr;
        while(curr != nullptr){
            next = curr->_next;
            curr->_next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
private:
    int _data;
    SinglyLinkedList *_next;
};

int main(){
    SinglyLinkedList *list = new SinglyLinkedList(0);
    list->push_back(1);
    list->insert(1,5);
    list->push_back(1);
    list->print();

    return 0;
}