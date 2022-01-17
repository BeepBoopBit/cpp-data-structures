#include "../SinglyLinkedList.h"



int main(){
    SinglyLinkedList *list = new SinglyLinkedList(7);
    list->push_back(1);
    list->push_back(9);
    list->push_back(3);
    list->push_back(2);
    list->push_back(8);
    list->push_back(7);
    list->push_back(5);
    list->sort();
    list->print();
}