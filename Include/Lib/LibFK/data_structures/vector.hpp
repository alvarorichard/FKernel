/*
* Vector.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibC/stdio.h>
#include <Lib/LibC/stddef.h>
#include <Lib/LibFK/memory/own_ptr.hpp>

namespace FK{

template <typename T>
class Vector{
    private:
        size_t capacity {1};    
        size_t size {0};
        own_ptr<T[]> array;
    public:
        Vector(){
            array = make<T[]>(capacity);
            printf("[OK]: Allocate a vector with size of %d\n", capacity);
        }

        Vector(size_t array_capacity){
            capacity = array_capacity;
            size = 0;
            array = make<T[]>(capacity);
            printf("[OK]: Allocate a vector with size of %d\n", capacity);
        }  

        ~Vector(){
            size = 0;
            capacity = 0;
            array.reset();

            printf("[OK]: Delete the array\n");
        }

        void reallocate_vector(){
            printf("[OK]: Realocate the array with %d\n", (2 * capacity));
            capacity *= 2;
            own_ptr<T[]> new_array = make<T[]>(capacity);

            for (size_t i = 0; i < size; i++){
                new_array[i] = array[i];
            }

            array.reset();

            this->array = new_array;
        }

        bool is_empty() const {
            if (size != 0){
                return false;
            }

            return true;
        }

        bool is_full() const {
            if (size != capacity){
                return false; 
            }

            return true; 
        }
  
        void Insert(T new_element){
            if (is_full()){
                realocate_vector();
            }
            
            printf("[OK]: Insert the element\n");
            array[size] = new_element;
            size ++;
        }
};

};

using FK::Vector;