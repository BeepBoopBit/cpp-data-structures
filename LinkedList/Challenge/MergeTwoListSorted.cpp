#include "../SinglyLinkedList.h"
#include <stdlib.h>

SinglyLinkedList *getList(int start, int end){
    SinglyLinkedList *templist = new SinglyLinkedList(start);
    srand(time(0));
    for(int i = start+1; i <= end; ++i){
        templist->push_back((rand()%end)+start);
    }
    return templist;
}

void swapListData(SinglyLinkedList *lhs, SinglyLinkedList *rhs){
    int tempData = lhs->getData();
    lhs->changedData(rhs->getData());
    rhs->changedData(tempData);
}

void bubbleSortList(SinglyLinkedList *list){
    SinglyLinkedList *tempList = list;
    while(tempList != nullptr){
        SinglyLinkedList *prev = list;
        SinglyLinkedList *curr = list->next();
        while(curr != nullptr){
            if(prev->getData() > curr->getData()){
                swapListData(prev,curr);
            }
            prev = curr;
            curr = curr->next();
        }
        tempList = tempList->next();
    }
}


void mergeTwoList(){

    SinglyLinkedList *list01 = getList(0,10);

    SinglyLinkedList *list02 = getList(0,20);

    // sort both list first
    bubbleSortList(list01);
    list01->print();
    std::cout << std::endl;
    bubbleSortList(list02);
    list02->print();
    std::cout << std::endl;

    // let's merge it
    SinglyLinkedList *resultList = new SinglyLinkedList(0);
    bool isFirst = true;
    int list01Data = 0;    
    while(list01 != nullptr && list02 != nullptr){
        list01Data = list01->getData();
        if(list01Data > list02->getData()){
            if(isFirst){
                // change flag
                isFirst = false;
                // change data
                resultList->changedData(list02->getData());
            }else{
                // otherwise push it back
                resultList->push_back(list02->getData());
            }
            list02 = list02->next();
        }else{
            if(isFirst){
                // change flag
                isFirst = false;
                // change data
                resultList->changedData(list01->getData());
            }else{
                // otherwise push it back
                resultList->push_back(list01->getData());
            }
            list01 = list01->next();
        }
    }
    if(list01 == nullptr && list02 != nullptr){
        while(list02 != nullptr){
            resultList->push_back(list02->getData());
            list02 = list02->next();
        }
    }else if(list02 == nullptr && list01 != nullptr){
        while(list01 != nullptr){
            resultList->push_back(list01->getData());
            list01 = list01->next();
        }
    }
    resultList->print();
}


int main(){
    mergeTwoList();
    return 0;
}