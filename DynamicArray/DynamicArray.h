#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream> // temporary

class DynamicArray{
public: // constructors
    DynamicArray(int capacity = 10){
        _arr = new int[capacity];
        _capacity = capacity;
    }

public: // functions
    void add(int value){
        if(_size+1 >= _capacity){
            // double the capacity
            _capacity *= 2;
            
            // create a new temporary array with the new capacity value
            int *newArr = new int[_capacity];
            
            // copy the contents of the current array to the new array
            for(int i = 0; i < _size; ++i){
                newArr[i] = _arr[i];
            }
            
            // delete the previous array
            delete []_arr;
            
            // assign _arr to the new array
            _arr = newArr; 
        }
        // put the value at the end of the array
        _arr[_size++] = value;
    }

    void removeAt(int index){
        for(int i = index; i < _size-1; ++i){
            _arr[i] = _arr[i+1];
        }
        --_size;
    }

    void remove(int value){
        for(int i = 0; i < _size; ++i){
            if(_arr[i] == value){
                removeAt(i);
            }
        }
    }

    void replace(int index, int value){
        if(index < _size){
            _arr[index] = value;
        }else{
            std::cout << "Index out-of-bounce" << std::endl;
            exit(-1);
        }
    }
    

public: // Getters
    int capacity(){
        return _capacity;
    }

    int size(){
        return _size;
    }

    int getItemAt(int index){
        if(index < _size){
            return _arr[index];
        }
        std::cout << "Index out-of-bounce" << std::endl;
        exit(-1);
    }


public: // debug
    void print(){
        for(int i = 0; i < _size; ++i){
            std::cout << _arr[i] << ' ';
        }
    }

private:
    int _size = 0,
        _capacity = 10,
        *_arr = nullptr;


};

#endif
