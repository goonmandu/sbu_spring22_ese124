#include <stdio.h>

int my_is_upper(char c);
int my_is_lower(char c);
int my_isalpha(char c);
int my_isdigit(char c);
int my_alnum(char c);
char my_to_upper(char c);
char my_to_lower(char c);

int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int letters);
char *my_strcpy(char *str1, char *str2);
char *my_strncpy(char *str1, char *str2, int letters);
char *my_strcat(char *str1, char *str2);
char *my_strncat(char *str1, char *str2, int letters);
int my_strlen(char *word);

char *to_pig_latin(char *word);
int starts_with_cap(char *word);
int num_of_leading_cons(char *word);
char *append_ay(char *word);
char *delete_first_letters(char *word, int letters);
int is_vowel(char *word, int idx);

int main() {
    char string[40];
    for (int i = 0; i < 5; i++) {
        printf("Enter a string to Piglatinify: ");
        scanf("%s", string);
        getchar();
        printf("%s\n\n", to_pig_latin(string));
    }
    return 0;
}

char *to_pig_latin(char *word) {
    char original[40];
    my_strcpy(original, word);
    append_ay(word);
    if (starts_with_cap(original)) {
        word[0] = my_to_upper(word[0]);
    }
    return word;
}

int my_is_upper(char c) {
    if ('A' <= c && 'Z' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_is_lower(char c) {
    if ('a' <= c && 'z' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_isalpha(char c) {
    if (my_is_upper(c) || my_is_lower(c)) {
        return 1;
    } else {
        return 0;
    }
}

int my_isdigit(char c) {
    if ('0' <= c && '9' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_alnum(char c) {
    if (my_isalpha(c) || my_isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

char my_to_upper(char c) {
    if (my_is_lower(c)) {
        return c - 32;
    } else {
        return c;
    }
}

char my_to_lower(char c) {
    if (my_is_upper(c)) {
        return c + 32;
    } else {
        return c;
    }
}

int my_strcmp(char *str1, char *str2) {
    int idx = 0;
    do {
        if (str1[idx] != str2[idx]) {
            return 1;
        }
        idx++;
    } while (str1[idx] != '\0' || str2[idx] != '\0');
    return 0;
}

int my_strncmp(char *str1, char *str2, int letters) {
    for (int idx = 0; idx < letters; idx++) {
        if (str1[idx] == '\0' || str2[idx] == '\0') {
            return 2;
        }
        if (str1[idx] != str2[idx]) {
            return 1;
        }
    }
    return 0;
}

char *my_strcpy(char *str1, char *str2) {
    int idx = 0;
    do {
        str1[idx] = str2[idx];
        idx++;
    } while (str1[idx] != '\0' || str2[idx] != '\0');
    str1[idx] = '\0';
    return str1;
}

char *my_strncpy(char *str1, char *str2, int letters) {
    int wider_scope_idx = 0;
    for (int idx = 0; idx < letters; idx++) {
        if (str2[idx] == '\0') {
            return str1;
        }
        str1[idx] = str2[idx];
        wider_scope_idx++;
    }
    str1[wider_scope_idx] = '\0';
    return str1;
}

char *my_strcat(char *str1, char *str2) {
    int str1_idx = 0, str2_idx = 0;
    while (str1[str1_idx] != '\0') {
        str1_idx++;
    }
    while (str2[str2_idx] != '\0') {
        str1[str1_idx+str2_idx] = str2[str2_idx];
        str2_idx++;
    }
    str1[str1_idx+str2_idx] = '\0';
    return str1;
}

char *my_strncat(char *str1, char *str2, int letters) {
    int str1_idx = 0, str2_idx = 0;
    while (str1[str1_idx] != '\0') {
        str1_idx++;
    }
    while (str2[str2_idx] != '\0' && str2_idx < letters) {
        str1[str1_idx+str2_idx] = str2[str2_idx];
        str2_idx++;
    }
    str1[str1_idx+str2_idx] = '\0';
    return str1;
}

int is_vowel(char *word, int idx) {
    if (idx != 0) {
        if (my_to_lower(word[idx]) == 'a' ||
            my_to_lower(word[idx]) == 'e' ||
            my_to_lower(word[idx]) == 'i' ||
            my_to_lower(word[idx]) == 'o' ||
            my_to_lower(word[idx]) == 'u' ||
            my_to_lower(word[idx]) == 'y') {
            return 1;
        }
    } else {
        if (my_to_lower(word[idx]) == 'a' ||
            my_to_lower(word[idx]) == 'e' ||
            my_to_lower(word[idx]) == 'i' ||
            my_to_lower(word[idx]) == 'o' ||
            my_to_lower(word[idx]) == 'u') {
            return 1;
        }
    }
    return 0;
}

int my_strlen(char *word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }
    return len;
}

char *delete_first_letters(char *word, int letters) {
    int final_len = 0;
    for (int idx = 0; idx < my_strlen(word) - letters; idx++) {
        word[idx] = word[idx+letters];
        final_len++;
    }
    word[final_len] = '\0';
    return word;
}

char *append_ay(char *word) {
    word[0] = my_to_lower(word[0]);
    if (is_vowel(word, 0)) {
        return my_strcat(word, "way");
    } else {
        word = my_strncat(word, word, num_of_leading_cons(word));
        delete_first_letters(word, num_of_leading_cons(word));
        return my_strcat(word, "ay");
    }
}

int num_of_leading_cons(char *word) {
    int num = 0;
    while (!is_vowel(word, num)) {
        num++;
    }
    return num;
}

int starts_with_cap(char *word) {
    if (my_is_upper(word[0])) {
        return 1;
    } else {
        return 0;
    }
}
