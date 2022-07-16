#include <stdio.h>
#include <string.h>

int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int letters);
char *my_strcpy(char *str1, char *str2);
char *my_strncpy(char *str1, char *str2, int letters);
char *my_strcat(char *str1, char *str2);
char *my_strncat(char *str1, char *str2, int letters);

int main() {
    char string1[50] = "BatChest";
    char string2[50] = "I LOOOVE C!";
    printf("%d\n", my_strcmp(string1, string2));
    printf("%d\n", my_strncmp(string1, string2, 4));
    printf("%s\n", my_strcpy(string1, string2));
    printf("%s\n", my_strncpy(string1, string2, 4));
    printf("%s\n", my_strcat(string1, "Clap"));
    printf("%s\n", my_strncat(string1, string2, 6));
    return 0;
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