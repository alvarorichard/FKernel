/*
 * Farpeek_poke.hpp
 * SPDX-Identifier-License: BSD-3-Clause
 * Copyright (c) 2024 FoxBSD
 */

#pragma once

#include <Lib/LibC/stdint.h>

uint8_t farpeekb(uint16_t segment_selector, void* offset);
void farpokeb(uint16_t segment_selector, void* offset, uint8_t value);

uint16_t farpeekw(uint16_t segment_selector, void* offset);
void farpokew(uint16_t segment_selector, void* offset, uint16_t value);

uint32_t farpeekl(uint16_t segment_selector, void* offset);
void farpokel(uint16_t segment_selector, void* offset, uint32_t value);
