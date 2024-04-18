#include <Kernel/Io/farpeek_poke.hpp>

uint8_t farpeekb(uint16_t segment_selector, void* offset) {
    uint8_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "movb %%fs:(%2), %0\n\t"
        "pop %%fs"
        : "=r"(ret)
        : "g"(segment_selector), "r"(offset));
    return ret;
}

void farpokeb(uint16_t segment_selector, void* offset, uint8_t value) {
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        :
        : "g"(segment_selector), "r"(offset), "r"(value));
}

uint16_t farpeekw(uint16_t segment_selector, void* offset) {
    uint16_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "movw %%fs:(%2), %0\n\t"
        "pop %%fs"
        : "=r"(ret)
        : "g"(segment_selector), "r"(offset));
    return ret;
}

void farpokew(uint16_t segment_selector, void* offset, uint16_t value) {
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movw %2, %%fs:(%1)\n\t"
        "pop %%fs"
        :
        : "g"(segment_selector), "r"(offset), "r"(value));
}

uint32_t farpeekl(uint16_t segment_selector, void* offset) {
    uint32_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "movl %%fs:(%2), %0\n\t"
        "pop %%fs"
        : "=r"(ret)
        : "g"(segment_selector), "r"(offset));
    return ret;
}

void farpokel(uint16_t segment_selector, void* offset, uint32_t value) {
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movl %2, %%fs:(%1)\n\t"
        "pop %%fs"
        :
        : "g"(segment_selector), "r"(offset), "r"(value));
}