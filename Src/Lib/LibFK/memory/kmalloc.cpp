#include <Lib/LibFK/memory/kmalloc.hpp>
#include <Lib/LibFK/memory/kalloc.hpp>
#include <Lib/LibC/stdio.h>

extern "C"{
    void* kcalloc(dword nmemb, dword size){
        return allocateZeroed(nmemb * size);
    }

    void kfree(void* ptr){
        free((byte*)ptr);
        return;
    }

    void* kmalloc(dword size){
        return allocate(size);
    }
}

void* operator new(size_t size){
    return kmalloc(size);
}

void* operator new[](size_t size){
    return kmalloc(size);
}

void operator delete(void* ptr){
    return kfree(ptr);
}

void operator delete[](void* ptr){
    return kfree(ptr);
}

void operator delete(void* ptr, size_t){
    return kfree(ptr);
}

void operator delete[](void* ptr, size_t){
    return kfree(ptr);
}

