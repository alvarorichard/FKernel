/*
* Stddef.h
* SPDX-License-Identifier: BSD-3-Clause
* Copyright (c) 2024, FoxBSD
*/

#pragma once

typedef __SIZE_TYPE__ size_t;

typedef __PTRDIFF_TYPE__ ptrdiff_t;

#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef offsetof
#define offsetof(type, member) __builtin_offsetof(type, member)
#endif
