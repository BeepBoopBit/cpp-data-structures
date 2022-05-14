#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include <iostream>
#include <math.h>

class Heap{
private:
    int _arr[10];

public:
    Heap(){
        _size = 0;
        _currIndex = 0;
    }

public:
    void push(int value){
        _arr[_currIndex] = value;
        int tempCurrIndex = _currIndex;
        int parent = getParent(tempCurrIndex);
        while(isGreater(tempCurrIndex, parent) && tempCurrIndex > 0){
            tempCurrIndex = siftUp(tempCurrIndex, parent);
            parent = getParent(tempCurrIndex);
        }
        
        ++_currIndex;
        ++_size;
    }

    void replace(int value){
        _arr[0] = value;
    }

    int pop_max(){
        int value = _arr[0];
        siftDown(0);
        --_size;
        --_currIndex;
        return value;
    }

public:
    void print(){
        for(int i = 0; i < _size; ++i){
            std::cout << _arr[i] << ' ';
        }
        std::cout << std::endl;
    }

private:
    bool isGreater(int a, int b){
        return a > b;
    }

    bool isLesser(int a, int b){
        return a < b;
    }

    int getParent(int index){
        return std::floor((index-1)/2);
    }

    void siftDown(int index){
        std::swap(_arr[index], _arr[_size-1]);
        while((2*index+2) < _size-1){
            int swapIndex   = 0,
                left        = (2*index)+ 1,
                right       = (2*index)+ 2;
            if(_arr[left] > _arr[right]){
                swapIndex = left;
            }else{
                swapIndex = right;
            }
            std::swap(_arr[index], _arr[swapIndex]);
            index = swapIndex;
        }
    }

    int siftUp(int index, int parentIndex){
        std::swap(_arr[index], _arr[parentIndex]);
        return parentIndex;
    }

private:
    int _size;
    int _currIndex;
    int _level;
};


#endif // HEAP_H