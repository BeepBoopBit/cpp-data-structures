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
        // Iterate through until before the last element
        SinglyLinkedList *tempHead = this;
        while(tempHead->_next != nullptr){
            tempHead = tempHead->_next;
        }
        // make its '_next' be equal to a new list data
        tempHead->_next = new SinglyLinkedList(data);
    }
    SinglyLinkedList *push_front(int data){
        // create a new list and store it
        SinglyLinkedList *newHead = new SinglyLinkedList(data);
        // make the value of '_next' point to the current head
        newHead->_next = this;
        // return the new head
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
        // if the index is '0' then change the 'head'
        if(index == 0){
            tPush_front(data);
            return;
        }
        // iterate until the specified index - 1
        SinglyLinkedList *tempHead = this;
        for(int i = 0; i < index-1; ++i){
            tempHead = tempHead->_next;
        }
        // create a temporary variable to be the next of tempHead
        SinglyLinkedList *tempNext = tempHead->_next;
        // make the temporary _next variable be equal to the new variable 
        tempHead->_next = new SinglyLinkedList(data);
        // assigned the value of the _next of the newly created variable to the temporary variable
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
            // make next point to the current next
            next = curr->_next;
            // make the current next point to the prev list
            curr->_next = prev;
            // make the prev be equal to the current list
            prev = curr;
            // make current point to the next list
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