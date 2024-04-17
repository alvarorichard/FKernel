/*
* Multiboot_interpreter.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Kernel/Misc/multiboot2.h>
#include <Lib/LibC/stdint.h>

class MultibootInterpreter{
    private:
        multiboot_info* mb_ptr;
    protected:
        MultibootInterpreter(multiboot_info* multiboot_ptr) : mb_ptr(multiboot_ptr){}
        MultibootInterpreter(const MultibootInterpreter&) = delete;
        void operator=(const MultibootInterpreter&) = delete;
    public:
        static MultibootInterpreter& getInstance(multiboot_info* multiboot_ptr = nullptr);

        uint64_t getMemoryAmount();
}; 