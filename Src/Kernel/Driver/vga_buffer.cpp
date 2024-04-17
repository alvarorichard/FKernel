#include <Kernel/Driver/vga_buffer.hpp>
#include <Lib/LibC/string.h>

void VgaBuffer::clear_row(size_t row){
    struct Character empty = (struct Character){
        .character = ' ',
        .color = color,
    };

    for (size_t col = 0; col < MAX_COLS; ++col){
        buffer[col + MAX_COLS * row] = empty;
    }
    return;
}

void VgaBuffer::clear(){
    for (int i = 0; i < MAX_COLS; ++i){
        VgaBuffer::clear_row(i);
    }

    return;
}

void VgaBuffer::newline(){
    col = 0;

    if (row < MAX_ROWS - 1){
        ++row;
        return; 
    }

    for (size_t row = 1; row < MAX_ROWS; ++row){
        for (size_t col = 0; col < MAX_COLS; ++col){
            struct Character character = buffer[col + MAX_COLS * row];
            buffer[col + MAX_COLS * (row - 1)] = character;
        }
    }

    VgaBuffer::clear_row(MAX_COLS - 1);
}

void VgaBuffer::print_char(char character){
    if (character == '\n'){
        VgaBuffer::newline();
        return;
    }

    if (col > MAX_COLS){
        VgaBuffer::newline();
    }

    buffer[col + MAX_COLS * row] = (struct Character) {
        .character = (uint8_t) character,
        .color = color
    };

    ++col;
    
    return; 
}

void VgaBuffer::print(char* str){
    for (int i = 0; str[i] != '\0'; i++){
        VgaBuffer::print_char(str[i]);
    }

    return; 
}

void VgaBuffer::println(char* str){
    VgaBuffer::print(str);
    VgaBuffer::print_char('\n');
    return; 
}

void VgaBuffer::set_color(Color foreground, Color background){
    this->color = static_cast<uint8_t>(foreground) + (static_cast<uint8_t>(background) << 4);
    return; 
}

void clear(){
    VgaBuffer::get_instance().clear();
    return;
}

void set_color(Color foreground, Color background){
    VgaBuffer::get_instance().set_color(foreground, background);
    return;
}