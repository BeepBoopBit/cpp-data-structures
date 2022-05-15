#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>

class DisjointSet{

private:
    int *_parent, *_rank, *_arr;
public:

    DisjointSet(int size){
        _parent = new int[size];
        _arr = new int[size];
        _rank = new int[size];
        _currIndex = 0;
    }

    void push(int value){
        if(_currIndex == _size-1){
            // allocate
        }
        _arr[_currIndex] = value;
        _parent[_currIndex] = _currIndex;
        _rank[_currIndex] = 0;
        ++_currIndex;
    }

    // follows the chain of parent pointers from a specified query node x until it reches a root element
    int find(int x){
        if(_parent[x] == x){
            return x;
        }
        return find(_parent[x]);
    }

    // union
    // parameters are x and y
    // find the intersection between 2 groups 
    void makeUnion(int x, int y){
        _parent[x] = y;
    }

    void print(int x){
        std::cout << _arr[x] << ' ';
        if(_parent[x] == x){
            return;
        }
        print(_parent[x]);
    }

public:


private:
    int _currIndex,
        _size;

};


#endif // UNION_FIND_H