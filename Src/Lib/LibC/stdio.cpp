#include <Lib/LibC/stdio.h>
#include <Lib/LibC/stdarg.h>
#include <Lib/LibC/string.h>

#include <Kernel/Driver/vga_buffer.hpp>

void putchar(char c){
    VgaBuffer::get_instance().print_char(c);
    return;
}

void puts(char* s){
    VgaBuffer::get_instance().println(s);
    return;
}

void printf(const char* format, ...){
    va_list args;
    va_start(args, format);

    while (*format != '\0'){
        if (*format == '%'){
            format++;
        
        switch (*format){
            case 'd': {
                int i = va_arg(args, int);
                char buffer[32];
                itoa(i, buffer, 10);
                puts(buffer);
                break;
            }

            case 's': {
                char *s = va_arg(args, char*);
                puts(s);
                break;
            }

            default:
                putchar('%');
                putchar(*format);
                break;
        }
    } else {
        putchar(*format);
    }
    ++format;
    }

    va_end(args);
    return;
}