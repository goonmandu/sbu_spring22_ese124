#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORD_LENGTH 50

int main() {
    int tries;
    char guess;
    char word[WORD_LENGTH];
    FILE *in;

    if ((in = fopen("hangman_word", "r")) == NULL) {
        printf("Input file not found.\n");
        exit(1);
    }

    fgets(word, 50, in);
    char hidden[strlen(word)];

    for (int i = 0; i < strlen(word); i++) {
        hidden[i] = '_';
    }

    printf("How many tries: ");
    scanf("%d", &tries);
    getchar();

    while (1) {
        printf("Your guess: ");
        scanf("%c", &guess);
        getchar();

        int idx = 0;
        int correct_guess = 0;
        while (word[idx] != '\0') {
            if (word[idx] == guess) {
                hidden[idx] = guess;
                correct_guess = 1;
            }
            idx++;
        }

        if (!correct_guess) {
            tries--;
            if (!tries) {
                printf("You lost!\nThe word was %s.\n", word);
                return 0;
            }
        }
        
        for (int i = 0; i < strlen(word); i++) {
            printf("%c", hidden[i]);
        }

        printf(" [%d tries left]\n\n", tries);
        if (!strcmp(word, hidden)) {
            printf("You won!\n");
            return 0;
        }
    }

    return 0;
}