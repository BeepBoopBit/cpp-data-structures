#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>

class Hash{
private:
    struct Node
    {
        int data;
        std::string key;
        Node *next;
    };

public: // constructors
    Hash(){
        for(int i = 0; i < 10; ++i){
            _arr[i] = nullptr;
        }
    }


public:
    void print(){
        for(int i = 0; i < 10; ++i){
            Node *tempNode = _arr[i];
            while(tempNode != nullptr){
                std::cout << tempNode->data << ' ';
                tempNode = tempNode->next;
            }
            std::cout << std::endl;
        }
    }

    void insert(std::string str, int value){
        int hashIndex = makeHash(str);
        Node *newNode = createNewNode(str, value);
        
        // then it's a new value
        if(_arr[hashIndex] == nullptr){
            _arr[hashIndex] = newNode;
        }else{
            Node *tempNode = _arr[hashIndex];
            while(tempNode->next != nullptr){
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }

    }

public: // operators

    int &operator[](std::string str){
        int hashIndex = makeHash(str);
        if(_arr[hashIndex] == nullptr){
            insert(str, 0);
        }
        
        Node *tempNode = _arr[hashIndex];
        while(tempNode->next != nullptr){
            if(tempNode->key == str){
                break;
            }
            tempNode = tempNode->next;
        }
        return tempNode->data;
    }

private: // auxillary function
    Node *createNewNode(std::string str, int value, Node *next = nullptr){
        Node *tempNode = new Node();
        tempNode->data = value;
        tempNode->key = str;
        tempNode->next = next;
        return tempNode;
    }

    int makeHash(std::string str){
       return ((str.length()*2) + 1) % 10;
    }
private:
    Node *_arr[10];
};

#endif // HASH_H