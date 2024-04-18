#include <Kernel/Io/cpu_operations.hpp>

bool are_interrupts_enabled() {
    unsigned long flags;
    asm volatile ("pushf \n\t" "pop %0" : "=g"(flags));
    return flags & (1 << 9);
}

unsigned long save_irqdisable() {
    unsigned long flags;
    asm volatile ("pushf \n\t cli \n\t pop %0" : "=r"(flags) : : "memory");
    return flags;
}

void irqrestore(unsigned long flags) {
    asm("push%0 \n\t popf" :: "rm"(flags) : "memory", "cc");
}

void lidt(void* base, uint16_t size) {
    struct {
        uint16_t length;
        void* base;
    } __attribute__((packed)) IDTR = {size, base};

    asm("lidt %0" :: "m"(IDTR));
}

void cpuid(int code, uint32_t* a, uint32_t* d) {
    asm volatile ("cpuid" : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx");
}

uint64_t rdtsc() {
    uint64_t ret;
    asm volatile ("rdtsc" : "=A"(ret));
    return ret;
}

unsigned long read_cr0() {
    unsigned long val;
    asm volatile ("mov %%cr0, %0" : "=r"(val));
    return val;
}

unsigned long read_cr2() {
    unsigned long val;
    asm volatile ("mov %%cr2, %0" : "=r"(val));
    return val;
}

unsigned long read_cr3() {
    unsigned long val;
    asm volatile ("mov %%cr3, %0" : "=r"(val));
    return val;
}

unsigned long read_cr4() {
    unsigned long val;
    asm volatile ("mov %%cr4, %0" : "=r"(val));
    return val;
}

void invlpg(void* m) {
    asm volatile ("invlpg (%0)" ::"r"(m) : "memory");
}

void wrmsr(uint64_t msr, uint64_t value) {
    uint32_t low = value & 0xFFFFFFFF;
    uint32_t high = value >> 32;
    asm volatile ("wrmsr" : : "c"(msr), "a"(low), "d"(high));
}

uint64_t rdmsr(uint64_t msr) {
    uint32_t low, righ;
    asm volatile ("rdmsr" : "=a"(low), "=d"(righ) : "c"(msr));
    return ((uint64_t)righ << 32) | low;
}