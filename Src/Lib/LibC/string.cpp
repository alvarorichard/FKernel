#include <Lib/LibC/string.h>

extern "C"{

void reverse(char* str, int length){
    int start = 0;
    int end = length - 1;
    while (start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end --;
        start ++; 
    }

    return; 
}

size_t strlen(const char* str){
    const char* s = str;
    while(*s){
      ++s;      
    }

    return s - str;
}

char* itoa(int num, char* str, int base){
    int i = 0;
    bool is_negative = false;

    if (num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10) {
        is_negative = true;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (is_negative){
        str[i++] = '-';
    }

    str[i] = '\0';  

    size_t str_size = strlen(str);

    reverse(str, str_size);

    return str; 
}

int atoi(const char* str){
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    for (int i = 0; str[i] != '\0'; ++i){
        res = res*10 + str[i] - '0';
    }

    return sign*res;
}

void* memcpy(void* dest, const void* src, size_t n){
    char* d = static_cast<char*>(dest);
    const char* s = static_cast<const char*>(src);

    while(n--){
        *d++ = *s++;
    }

    return dest;
}

void* memset(void* dest, int ch, size_t n){
    char* d = static_cast<char*>(dest);

    while(n--){
        *d++ = ch;
    }
    
    return dest;
}

}