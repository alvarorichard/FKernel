/*
 * Cpu_operations.hpp
 * SPDX-Identifier-License: BSD-3-Clause
 * Copyright (c) 2024 FoxBSD
 */

#pragma once

#include <Lib/LibC/stdint.h>

#define fence() __asm__ volatile ("":::"memory")

bool are_interrupts_enabled();

unsigned long save_irqdisable();
void irqrestore(unsigned long flags);

void lidt(void* base, uint16_t size);
void cpuid(int code, uint32_t* a, uint32_t* d);

uint64_t rdtsc();

unsigned long read_cr0();
unsigned long read_cr2();
unsigned long read_cr3();
unsigned long read_cr4();

void invlpg(void* m);

void wrmsr(uint64_t msr, uint64_t valor);
uint64_t rdmsr(uint64_t msr);