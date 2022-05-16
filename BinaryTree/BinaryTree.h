#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

class BinaryTree{
private:
    struct Node{
        int value;
        Node *left;
        Node *right;
        Node *parent;
    };

public:
    BinaryTree(){
        _head = nullptr;
    }

    void push(int value){
        if(_head == nullptr){
            _head = new Node();
            _head->value = value;
        }else{
            traversePush(_head, value);
        }
    }

    void find(int value){
        Node *tempNode = findAux(_head, value);
        if(tempNode == nullptr){
            std::cout << "Value not Founded" << std::endl;
        }else{
            std::cout << "Value was Found" << std::endl;
        }
    }

public: // debug
    void print(){
        printAux(_head);
    }
private:

    Node *findAux(Node *node, int value){
        if(node == nullptr){
            return nullptr;
        }else if(node->value == value){
            return node;
        }else if(node->value < value){
            return findAux(node->right, value);
        }
        return findAux(node->left, value);
    }

    void printAux(Node *node){
        std::cout << node->value << ' ';
        if(node->left != nullptr){
            printAux(node->left);
        }
        if(node->right != nullptr){
            printAux(node->right);
        }
    }

    void traversePush(Node *node, int value){

        if(node->left == nullptr && node->value > value){
            node->left = new Node();
            node->left->value = value;
        }else if(node->right == nullptr && node->value < value){
            node->right = new Node();
            node->right->value = value;
        }else if(node->value > value){
            traversePush(node->left, value);
        }else{
            traversePush(node->right, value);
        }
    }



private:
    Node *_head;
};

#endif // BINARY_TREE