#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

typedef struct {
    size_t indice; 
    size_t len;
} mutation;

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

int nboc(const char *s, const char *sub) {
    /*
    Attention: 
    - Fonction inversé par rapport le tp
    Cherche le nombre d'occurrences de s dans sub!!!!
    */
    int nb_occurences = 0;
    int len_s = strlen(s), len_sub = strlen(sub);
    int idx_s = 0;

    if(len_s > len_sub) return nb_occurences;
    for(int i = 0; i < len_sub; i++) {
        if(sub[i] == s[idx_s]) {
            idx_s++;
            if(idx_s == len_s) {
                nb_occurences++;
                idx_s = 0;
            }
        }else {
            idx_s = 0;
        }
    }
    return nb_occurences;
}

mutation diff(const char *s, const char *t) {
    mutation m = {.len = 0, .indice = -1};
    int s_len = strlen(s), t_len = strlen(t);
    if (s_len != t_len) return m;

    for(int i = 0; i < s_len; i++) {
        if(s[i] == t[i]) continue;
        m.indice = i;
        while (s[i] != t[i]) {
            m.len++;
            i++;
        }
        break;
    }
    return m;
}

mutation longest(const char *s, const char *t) {
    int s1 = strlen(s);
    assert(s1 == strlen(t));
    mutation max = diff(s, t);
    mutation tmp;
    for(int i=1;i<s1;i++) {
        tmp = diff(s+i, t+i);
        if(tmp.len > max.len)
            max = tmp;
    }
    return max;
}

int nbr_words(const char *s) {
    int found_space = 1;
    int word_counter = 0;

    for(int i = 0; i < strlen(s); i++) {
        if(isspace(s[i])) {
            found_space = 1;
        }else {
            if(found_space != 0) {
                word_counter++;
                found_space = 0;
            }
        }
    }
    return word_counter;
}
int word_len(const char *w) {
    assert(isalpha(w[0]));
    assert(!isspace(w[0]));

    int idx = 0;
    while(!isspace(w[idx])) {
        if(w[idx] == '\0') {
            break;
        }
        idx++;
    }
    return idx;
}

char *extract_word(const char *word, int *pl) {
    int len = word_len(word);
    assert(len > 0);
    char *res = malloc(sizeof(char)*len+1);
    assert(res != NULL);
    memmove(res, word, len+1);
    *pl = len;
    return res;
}

char *next_word(const char *w) {
    int idx = 0;
    while(isspace(w[idx]) || w[idx] == '\0') {
        idx++;
    }
    int *random = malloc(sizeof(int));
    return extract_word(w+idx, random);
}
void tests_1() {
    printf("[LOG]: duplicate():  %s\n", dupliquer("Hello World"));
    printf("[LOG]: duplicate2(): %s\n", dupliquer2("Hello World"));
    printf("[LOG]: duplicate3(): %s\n", dupliquer3("Hello World"));
    printf("[LOG]: ordrealpha(): %d\n", ordrealpha("Pa", "Paris"));
    printf("[LOG]: multiplier(): %s\n", multiplier("Paris", 3));
}


int main(int argc, char* argv[]) {
    tests_1();

    if(argc > 3) {
        for(int i = 0; i < argc-1; i++) {
            if(i == 0) continue;
            printf("[%d]: %s ;", i, argv[i]);
            printf(" [%d]: %s -> ", i+1, argv[i+1]);
            printf("%d\n", ordrealpha(argv[i], argv[i+1]));
        }   
    }

    if(argc == 3) {
        int s = atoi(argv[2]);
        printf("%s", multiplier(argv[1], s));
    }

    printf("nbocc: %d\n", nboc("aa", "dsdaaaaddsaa"));
    mutation m = diff("abbbb", "abcdd");
    printf("mutation m.len: %d, m.indice: %d\n", m.len, m.indice);
    mutation longest_mutation = longest("atcgatatt", "aaagccata");
    printf("mutation m.len: %d, m.indice: %d\n", longest_mutation.len, longest_mutation.indice);
    printf("nbr_words: %d\n", nbr_words("    hello my dds name is paris  "));
    
    char *s = "Paris Mollo";
    printf("word_len: %d\n", word_len(s+6));

    int *pl = malloc(sizeof(int));

    char *res = extract_word(s+6, pl);
    printf("extracted word: %s\n", res);
    printf("old word: %s\n", s);
    printf("new word len: %d\n", *pl);

    printf("next word: %s", next_word("      Hello    dsds"));

    return EXIT_SUCCESS;
}