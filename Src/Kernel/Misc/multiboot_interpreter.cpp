#include <Kernel/Misc/multiboot_interpreter.hpp>

MultibootInterpreter& MultibootInterpreter::getInstance(multiboot_info* multiboot_ptr){
    static MultibootInterpreter instance(multiboot_ptr);
    return instance;
}

uint64_t MultibootInterpreter::getMemoryAmount(){
    if (mb_ptr->mem_upper < mb_ptr->mem_lower){
        return 0;        
    }
    
    return (static_cast<uint64_t>(mb_ptr->mem_upper) * 1024) - (static_cast<uint64_t>(mb_ptr->mem_lower) * 1024);
}