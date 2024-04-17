/*
 * Early_init.hpp
 * SPDX-Identifier-License: BSD-3-Clause
 * Copyright (c) 2024 FoxBSD
 */

#pragma once

#include <Lib/LibC/stdint.h>

void early_init(uint64_t memory_availiable);