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
            _head = createNewNode(value);
        }else{
            traversePush(_head, value);
        }
    }

    void pop(){
        Node *tempNode = _head;
        int value = tempNode->value;
        tempNode = siftDown(tempNode);
        tempNode = tempNode->parent;
        if(tempNode->left != nullptr && tempNode->left->value == value){
            delete tempNode->left;
            tempNode->left = nullptr;
        }else{
            delete tempNode->right;
            tempNode->right = nullptr;
        }
    }

    void remove(int value){
        Node *tempNode = find(value);
        if(tempNode == _head){
            pop();
        }else{
            tempNode = siftDown(tempNode);
            tempNode = tempNode->parent;
            if(tempNode->left != nullptr && tempNode->left->value == value){
                delete tempNode->left;
                tempNode->left = nullptr;
            }else{
                delete tempNode->right;
                tempNode->right = nullptr;
            }
        }
    }

public: // debug
    void print(){
        printAux(_head);
    }
private:
    Node *siftDown(Node *node){
        if(node->left == nullptr && node->right == nullptr){
            return node;
        }else if(node->left == nullptr && node->right != nullptr){
            std::swap(node->value, node->right->value);
            siftDown(node->right);
        }else{
            std::swap(node->value, node->left->value);
            siftDown(node->left);
        }
    }

    Node *createNewNode(int value){
        Node *tempNewNode = new Node();
        tempNewNode->value = value;
        tempNewNode->left = nullptr;
        tempNewNode->right = nullptr;
        tempNewNode->parent = nullptr;
        return tempNewNode;
    }

    Node *find(int value){
        Node *tempNode = findAux(_head, value);
        if(tempNode == nullptr){
            std::cout << "Value not Founded" << std::endl;
            exit(-1);
        }
        return tempNode;
    }

    Node *findAux(Node *node, int value){
        if(node->value == value){
            return node;
        }else if(node->left == nullptr && node->right == nullptr){
            return nullptr;
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
            node->left = createNewNode(value);
            node->left->parent = node;
        }else if(node->right == nullptr && node->value < value){
            node->right = createNewNode(value);
            node->right->parent = node;
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