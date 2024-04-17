#include <Kernel/Misc/multiboot_interpreter.hpp>
#include <Kernel/Init/early_init.hpp>

extern "C" void kernel_main(multiboot_info* multiboot_ptr){
    MultibootInterpreter& mb_interpreter = MultibootInterpreter::getInstance(multiboot_ptr);
    uint64_t memory_amount = mb_interpreter.getMemoryAmount();

    early_init(memory_amount);  
    return; 
}
