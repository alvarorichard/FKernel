/*
* Vga_buffer.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibC/stddef.h>
#include <Lib/LibC/stdint.h>

#define MAX_COLS 80
#define MAX_ROWS 25

enum Color : uint8_t {
    BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15,
};

struct Character {
    uint8_t character;
    uint8_t color;
};

class VgaBuffer{
    private:
        static VgaBuffer* instance;
        VgaBuffer() = default;
        ~VgaBuffer() = default;
        VgaBuffer(const VgaBuffer&) = delete;
        VgaBuffer& operator=(const VgaBuffer&) = delete;

        void clear_row(size_t row);
        void newline();
    
        size_t row; 
        size_t col;

        struct Character* buffer = (struct Character*) 0xb8000;
        uint8_t color = Color::WHITE | Color::BLACK << 4;

    public:
        static VgaBuffer& get_instance(){
            static VgaBuffer instance; 
            return instance;
        }

        void clear();
        void print_char(char character);
        void print(char* str);
        void println(char* str);
        void set_color(Color foreground, Color background);
};

void set_color(Color foreground, Color background);
void clear();