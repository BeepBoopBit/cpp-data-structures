#include <iostream>

class DoublyLinkedList{
public:
    DoublyLinkedList(){
        _data = 0;
        _prev = nullptr;
        _next = nullptr;
    }
    DoublyLinkedList(int data){
        _data = data;
        _prev = nullptr;
        _next = nullptr;
    }
    void push_back(int data){
        // create a temporary variable
        DoublyLinkedList *tempHead = this;
        // get to the before the last element of the list
        while(tempHead->_next != nullptr){
            tempHead = tempHead->_next;
        }
        // make the _next value equal to the newly created list data
        tempHead->_next = new DoublyLinkedList(data);
        // make the _prev value of the newly created data equal to the tempHead;
        tempHead->_next->_prev = tempHead;
    }
    DoublyLinkedList *push_front(int data){
        DoublyLinkedList *tempHead = this;
        DoublyLinkedList *newHead = new DoublyLinkedList(data);
        newHead->_next = tempHead;
        tempHead->_prev = newHead;
        return newHead;
    }
    void tPush_front(int data){
        // create a new list and set it to the previous head
        DoublyLinkedList *newList = new DoublyLinkedList(_data);
        newList->_next = _next;
        newList->_prev = this;
        
        // change the current data to the new data
        _data = data;
        _next = newList;

    }
    DoublyLinkedList *reverse(){
        DoublyLinkedList *prev = nullptr,
                         *curr = this,
                         *next = nullptr;
        while(curr != nullptr){
            next = curr->_next;
            curr->_next = prev;
            curr->_prev = next;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void print(){
        DoublyLinkedList *tempHead = this;
        while(tempHead != nullptr){
            std::cout << tempHead->_data << ' ';
            tempHead = tempHead->_next;
        }
    }
private:
    int _data;
    DoublyLinkedList *_prev, *_next;
};

int main(){
    DoublyLinkedList *list = new DoublyLinkedList(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list = list->reverse();
    list->print();
    return 0;
}