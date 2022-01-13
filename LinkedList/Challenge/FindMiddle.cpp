#include "../SinglyLinkedList.h"

void findMiddle(){
    SinglyLinkedList *list01 = new SinglyLinkedList(0);
    for(int i = 1; i < 10; ++i){
        list01->push_back(i);
    }
    list01->print();

    // this is easy since i've implemented 'size' but let's not use it
    // find the size of the list
    SinglyLinkedList *tempList = list01;
    int listSize = 0;
    while(tempList != nullptr){
        tempList = tempList->next();
        ++listSize;
    }
    // now get the middle
    tempList = list01;
    for(int i = 0; i < (listSize/2); ++i){
        tempList = tempList->next();
    }
    std::cout << '\n' << tempList->getData();
}

int main(){
    findMiddle();
    return 0;
}