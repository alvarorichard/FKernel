/*
 * IO_Operations.hpp
 * SPDX-Identifier-License: BSD-3-Clause
 * Copyright (c) 2024 FoxBSD
 */

#pragma once

#include <Lib/LibC/stdint.h>

uint8_t inb(uint16_t porta);
void outb(uint16_t porta, uint8_t val);

uint16_t inw(uint16_t porta);
void outw(uint16_t porta, uint16_t val);

uint32_t inl(uint16_t porta);
void outl(uint16_t porta, uint32_t val);

void io_wait(void);