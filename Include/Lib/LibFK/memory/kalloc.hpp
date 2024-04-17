/*
* Kalloc.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibFK/memory/kalloc.hpp>
#include <Lib/LibFK/types.hpp>

#define HEAP_SIZE 512 * 1024 // 512KB reserved

extern char heap[HEAP_SIZE];

struct MemoryBlock{
    size_t size;
    bool is_free;
    size_t* next;
    size_t* prev;
};

enum class AllocatorStrategy{
    FIRST_FIT
};

class Kalloc{
    private:
        Kalloc(){
            freeBlocks->is_free = true;
            freeBlocks->size = HEAP_SIZE - sizeof(MemoryBlock);
            freeBlocks->next = nullptr;
            freeBlocks->prev = nullptr;
        }
        
        Kalloc(Kalloc const&) = delete;
        void operator=(Kalloc const&) = delete;
        MemoryBlock* freeBlocks = reinterpret_cast<MemoryBlock*>(heap);
        AllocatorStrategy actualStrategy = AllocatorStrategy::FIRST_FIT;

    public:
        static Kalloc& getInstance(){
            static Kalloc instance;
            return instance;
        }

        void change_allocator_strategy(AllocatorStrategy new_strategy){
            if (new_strategy != actualStrategy){
                actualStrategy = new_strategy;
                return;
            }

            return;
        }

        byte* allocate(size_t size);
        byte* allocateZeroed(size_t size);
        void free(byte* ptr);
};

// Methods of interface

byte* allocate(size_t); // eq Malloc
byte* allocateZeroed(size_t); // eq Calloc
void free(byte* ptr);  // free