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
    list->print();
    return 0;
}