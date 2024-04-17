#include <Kernel/Init/early_init.hpp>
#include <Kernel/Driver/vga_buffer.hpp>

#include <Lib/LibC/stdio.h>

void early_init(uint64_t memory_available){
    clear();
    printf("[OK]: Start early init\n");

    return;
}