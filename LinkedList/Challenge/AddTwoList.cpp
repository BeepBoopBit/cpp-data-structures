#include "../SinglyLinkedList.h"


SinglyLinkedList *getList(int start, int end){
    SinglyLinkedList *templist = new SinglyLinkedList(start);
    for(int i = start+1; i <= end; ++i){
        templist->push_back(i);
    }
    return templist;
}

void addTwoList(){
    SinglyLinkedList *list01 = getList(0,5);
    list01->print();
    std::cout << std::endl;
    
    SinglyLinkedList *list02 = getList(6,11);
    list02->print();
    std::cout << std::endl;

    SinglyLinkedList *result = new SinglyLinkedList(0);
    bool isFirst = true;
    std::cout << "---------------\n";
    while(list01 != nullptr || list02 != nullptr){
        int data = 0;
        if(list01 != nullptr){
            data += list01->getData();
            list01 = list01->next();
        }
        if(list02 != nullptr){
            data += list02->getData();
            list02 = list02->next();
        }
        if(isFirst){
            isFirst = false;
            result->changedData(data);
        }else{
            result->push_back(data);
        }
    }
    result->print();

}


int main(){
    addTwoList();
    return 0;
}