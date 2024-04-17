/*
* Kmalloc.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibFK/memory/kalloc.hpp>

extern "C" {
    void* kcalloc(dword nmemb, dword size);
    void* kmalloc(dword size);
    void* krealloc(void* ptr, dword size);
    void kfree(void* ptr);
}