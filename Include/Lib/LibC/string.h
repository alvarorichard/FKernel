/*
* String.h
* SPDX-License-Identifier: BSD-3-Clause
* Copyright (c) 2024, FoxBSD
*/

#pragma once

#include <Lib/LibC/stddef.h>
extern "C"{
    void* memcpy(void* dest, const void* src, size_t n);    

    void* memset(void* dest, int ch, size_t n);

    int atoi(const char* str);

    char* itoa(int num, char* str, int base);

    size_t strlen(const char* str);

    void reverse(char* str, int length);
}