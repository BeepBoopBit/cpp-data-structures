#include <iostream>

class LinkedList{
public:
    LinkedList(){
        _data = 0;
        _next = nullptr;
    }
    LinkedList(int data){
        _data = data;
        _next = nullptr;
    }
    void push_back(int data){
        LinkedList *tempHead = this;
        while(tempHead->_next != nullptr){
            tempHead = tempHead->_next;
        }
        tempHead->_next = new LinkedList(data);
    }
    LinkedList *push_front(int data){
        LinkedList *newHead = new LinkedList(data);
        newHead->_next = this;
        return newHead;
    }
    void insert(int index, int data){
        LinkedList *tempHead = this;
        for(int i = 0; i < index-1; ++i){
            tempHead = tempHead->_next;
        }
        LinkedList *tempNext = tempHead->_next;
        tempHead->_next = new LinkedList(data);
        tempHead->_next->_next = tempNext;
    }
    void print(){
        LinkedList *tempHead = this;
        while(tempHead != nullptr){
            std::cout << tempHead->_data << ' ';
            tempHead = tempHead->_next;
        }
    }
    LinkedList *reverse(){
        LinkedList *prev = nullptr,
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
    LinkedList *_next;
};

int main(){
    LinkedList *list = new LinkedList(0);
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->insert(2,20);
    list = list->push_front(500);
    list->print();

    return 0;
}