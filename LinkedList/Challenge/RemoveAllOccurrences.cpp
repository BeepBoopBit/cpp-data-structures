#include "../SinglyLinkedList.h"

void removeDuplicates(int valueToRemove){
    SinglyLinkedList *list01 = new SinglyLinkedList(1);
    list01->push_back(3);
    list01->push_back(4);
    list01->push_back(3);
    list01->push_back(4);
    list01->push_back(1);
    list01->push_back(3);
    list01->push_back(1);
    list01->push_back(6);
    SinglyLinkedList *temp = list01;
    bool isFirst = true;
    int index = 0;
    while(temp != nullptr){
        if(temp->getData() == valueToRemove){
            if(isFirst){
                isFirst = false;
            }else{
                temp = temp->next();
                list01->remove(index);
                continue;
            }
        }
        ++index;
        temp = temp->next();
    }
    list01->print();
}

int main(){
    return 0;
}