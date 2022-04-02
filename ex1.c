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
    strncpy(dest, s, strlen(s)+1);
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

char* multiplier(const char* s, unsigned int a) {
    char* res = malloc((strlen(s) * a + 1) * sizeof(char));
    if (res == NULL) return NULL;
    res[0] = '\0';
    for(int i=0; i<a; i++) {
        strncat(res, s, strlen(s));
    }
    return res;
}


int main(int argc, char* argv[]) {
    printf("[LOG]: duplicate():  %s\n", dupliquer("Hello World"));
    printf("[LOG]: duplicate2(): %s\n", dupliquer2("Hello World"));
    printf("[LOG]: duplicate3(): %s\n", dupliquer3("Hello World"));
    printf("[LOG]: ordrealpha(): %d\n", ordrealpha("Pa", "Paris"));
    printf("[LOG]: multiplier(): %s\n", multiplier("Paris", 3));
  
    return EXIT_SUCCESS;
}