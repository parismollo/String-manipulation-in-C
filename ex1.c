#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* dupliquer(const char* s) {
    int size = strlen(s);
    char* dest = malloc(size+1);
    if(dest == NULL)  {
        return NULL;
    }
    memmove(dest, s, size+1);
    dest[size] = '\0';
    return dest;
}

char* dupliquer2(const char* s) {
    char* dest = malloc(strlen(s)+1);
    if (dest == NULL) return NULL;
    strcpy(dest, s);
    return dest;
}

char* dupliquer3(const char* s) {
    char* dest = malloc(strlen(s)+1);
    if (dest == NULL) return NULL;
    strncpy(dest, s, strlen(s));
    return dest;
}

int ordrealpha(const char* s1, const char* s2) {
    char* a, *b;
    for(a = (char*)s1, b = (char*)s2; *a != '\0' && *b != '\0'; a++, b++) {
        if (*a < *b) return -1;
        if (*a > *b) return 1;
    }
    if (*a == '\0' && *b == '\0') return 0;
    if (*a == '\0') return -1;
    return 1;
}

int main() {
    printf("[LOG]: duplicate():  %s\n", dupliquer("Hello World"));
    printf("[LOG]: duplicate2(): %s\n", dupliquer2("Hello World"));
    printf("[LOG]: duplicate3(): %s\n", dupliquer3("Hello World"));
    printf("[LOG]: ordrealpha(): %d\n", ordrealpha("Pa", "Paris"));
  
    return EXIT_SUCCESS;
}