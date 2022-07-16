#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in, *out;
    int m, n;
    char scan[500], command[256], command_arr[100][33], user_input[500] = "";
    char text[50][500] = {}, dupe[50][500];
    user_input[0] = '\0';

    if ((in = fopen("part2input", "r")) == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    if ((out = fopen("part2output", "w")) == NULL) {
        printf("Output file not found.\n");
        return 1;
    }

    int lines = 0;
    while (1) {
        if ((fgets(scan, 500, in) == NULL)) {
            break;
        } else {
            strcpy(text[lines], scan);
            text[lines++][strlen(scan)] = '\0';
        }
    }
    printf("\n");
    for (int block = 0; block <= lines; block++) {
        printf("%2d  %s", block + 1, text[block]);
    }
    printf("\n");

    for (int i = 0; i < lines; i++) {
        strcpy(dupe[i], text[i]);
    }
    
    while (1) {
        printf("\nEnter a command: ");
        gets(command);
        
        int arr_idx = 0;
        int input_length = 0;
        char *token = strtok(command, " ");
        while (token != NULL) {
            input_length += strlen(token) + 1;
            strcpy(command_arr[arr_idx++], token);
            token = strtok(NULL, " ");
        }
        
        if (!strcmp(command_arr[0], "I")) {
            if (lines >= 50) {
                printf("No more free space to insert a line.");
            } else {
                m = atoi(command_arr[1]);
                if (m == lines) {
                    strcat(user_input, "\n");
                }
                for (int block = lines; block > m - 1; block--) {
                    strcpy(text[block+1], text[block]);
                }
                for (int idx = 2; idx <= arr_idx + 1; idx++) {
                    if (idx != arr_idx + 1) {
                        strcat(user_input, command_arr[idx]);
                        strcat(user_input, " ");
                    } else {
                        strcat(user_input, command_arr[idx]);
                    }
                }
                user_input[input_length-5] = '\n';
                user_input[input_length-4] = '\0';
                strcpy(text[m], user_input);
                lines++;
                strcpy(user_input, "");
            }
        } else if (!strcmp(command_arr[0], "D")) {
            m = atoi(command_arr[1]);
            n = atoi(command_arr[2]);
            if (m > n) {
                int temp = m;
                m = n;
                n = temp;
            }
            for (int block = m; block < n + 1; block++) {
                strcpy(text[block-1], "\n");
            }
        } else if (!strcmp(command_arr[0], "R")) {
            m = atoi(command_arr[1]);
            n = atoi(command_arr[2]);
            if (m > n) {
                int temp = m;
                m = n;
                n = temp;
            }
            for (int block = m; block < n + 1; block++) {
                printf("New text for Line %d: ", block);
                gets(user_input);
                strcat(user_input, "\n");
                strcpy(text[block-1], user_input);
            }
            printf("\n");
            user_input[0] = '\0';
        } else if (!strcmp(command_arr[0], "E")) {
            for (int block = 0; block <= lines; block++) {
                fputs(text[block], out);
            }
            printf("Exiting editor. Edits saved to output file.\n");
            return 0;
        }
        for (int block = 0; block <= lines; block++) {
            printf("%2d  %s", block + 1, text[block]);
        }
        printf("\n");
    }
    return 0;
}