#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array{
private:
    T* ptr;
    int size;

public:
    // Constructor to initialize from array
    Array(T* arr, int size);

    // Constructor of an empty array
    Array();

    // Copy constructor
    Array(const Array<T>& other); 

    // Copy assignment operator
    Array<T>& operator=(const Array<T>& other);

    // Destructor
    ~Array();

    T* getArray(); // Returns a copy of the array
    T get(int index); // Returns the the value in index
    void print();// prints content on stdout
};

// Constructor definition
template <typename T>
Array<T>::Array(T* arr, int s){ 
    ptr = new T[s]; 
    size = s; 
    for (int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
}

// Default constructor definition
template <typename T>
Array<T>::Array() : ptr(nullptr), size(0){}

// Copy constructor definition
template <typename T>
Array<T>::Array(const Array<T>& other){
    size = other.size;
    ptr = new T[size];
    for (int i = 0; i < size; i++){
        ptr[i] = other.ptr[i];
    }
}

// Assignment operator definition
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
    if (this == &other) return *this;

    delete[] ptr;

    size = other.size;
    ptr = new T[size];
    for (int i = 0; i < size; i++){
        ptr[i] = other.ptr[i];
    }
    return *this;
}

// Destructor definition
template <typename T>
Array<T>::~Array(){
    delete[] ptr;
}

// Method to return a copy of the array
template <typename T>
T* Array<T>::getArray(){
    T* arr = new T[size];
    for (int i = 0; i < size; i++)
        arr[i] = ptr[i];
    return arr;
}

// Method to return value at a given index
template <typename T>
T Array<T>::get(int index){
    if(index< 0 || index >= size){
        throw std::out_of_range("Index out of range");
    }
    return ptr[index];
}

// Method to print the array
template <typename T> 
void Array<T>::print(){ 
    for (int i = 0; i < size; i++) 
        std::cout << ptr[i] <<  " "; 
    std::cout << std::endl; 
} 


#endif