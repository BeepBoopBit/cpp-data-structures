#include "../SinglyLinkedList.h"


SinglyLinkedList *getList(int start, int end){
    SinglyLinkedList *templist = new SinglyLinkedList(start);
    for(int i = start+1; i <= end; ++i){
        templist->push_back(i);
    }
    return templist;
}

void addTwoList(){
    // create a list starting from 0 to 5 inclusively
    SinglyLinkedList *list01 = getList(0,5);
    list01->print();
    std::cout << std::endl << list01->size() << std::endl;
    
    // create a list starting from 6 to 11 inclusively
    SinglyLinkedList *list02 = getList(6,11);
    list02->print();
    std::cout << std::endl << list02->size() << std::endl;

    // create the list to hold the result
    SinglyLinkedList *result = new SinglyLinkedList(0);
    // flag for the change in the 'result'
    bool isFirst = true;
    std::cout << "---------------\n";
    while(list01 != nullptr || list02 != nullptr){
        int data = 0;
        // if there are value in the list01
        if(list01 != nullptr){
            // add and go to the next list
            data += list01->getData();
            list01 = list01->next();
        }
        // if there are value in the list02
        if(list02 != nullptr){
            // add and go to the next list
            data += list02->getData();
            list02 = list02->next();
        }
        // if it's the first time changing the value
        if(isFirst){
            // change the flag
            isFirst = false;
            // change the first data
            result->changedData(data);
        }else{
            // otherwise push it back
            result->push_back(data);
        }
    }
    // print the result
    result->print();
}


int main(){
    addTwoList();
    return 0;
}