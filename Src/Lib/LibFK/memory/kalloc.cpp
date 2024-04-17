#include <Lib/LibFK/memory/kalloc.hpp>
#include <Lib/LibC/string.h>
#include <Lib/LibC/stdio.h>

char heap[HEAP_SIZE];

byte* allocate_first_fit(size_t size){
    size_t currentOffset = 0;
    while(currentOffset < HEAP_SIZE){
        MemoryBlock* current = reinterpret_cast<MemoryBlock*>(&heap[currentOffset]);
        if (current->is_free && current->size >= size){
            current->is_free = false;
            return reinterpret_cast<byte*>(current + 1);
        }
    }
    return nullptr;
}

byte* Kalloc::allocate(size_t size){
    if (this->actualStrategy == AllocatorStrategy::FIRST_FIT){
        return allocate_first_fit(size);
    }

    return nullptr;
}

byte* Kalloc::allocateZeroed(size_t size){
    byte* block = Kalloc::allocate(size);

    if (block != nullptr){
        memset(block, 0, size);
    }

    return block;
}

void Kalloc::free(byte *ptr){
    if (ptr == nullptr){
        return;
    }

    MemoryBlock* block = reinterpret_cast<MemoryBlock*>(ptr - sizeof(MemoryBlock));
    block->is_free = true;
    return;
}

// Interface to use with singleton
void change_strategy(AllocatorStrategy new_strategy){
    Kalloc::getInstance().change_allocator_strategy(new_strategy);
}

void free(byte* ptr){
    Kalloc::getInstance().free(ptr); 
    return;
}

byte* allocate(size_t size){
    return Kalloc::getInstance().allocate(size);
}


byte* allocateZeroed(size_t size){
    return Kalloc::getInstance().allocateZeroed(size);
}

