#include <Kernel/Io/io_operations.hpp>

uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ("inb %w1, %b0" : "=a"(ret) : "Nd"(port) : "memory");
    return ret;
}

void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ("outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

uint16_t inw(uint16_t port) {
    uint16_t ret;
    __asm__ volatile ("inw %w1, %w0" : "=a"(ret) : "Nd"(port) : "memory");
    return ret;
}

void outw(uint16_t port, uint16_t val) {
    __asm__ volatile ("outw %w0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

uint32_t inl(uint16_t port) {
    uint32_t ret;
    __asm__ volatile ("inl %w1, %0" : "=a"(ret) : "Nd"(port) : "memory");
    return ret;
}

void outl(uint16_t port, uint32_t val) {
    __asm__ volatile ("outl %0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

void io_wait(void) {
    outb(0x80, 0);
}