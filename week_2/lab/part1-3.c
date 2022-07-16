#include <stdio.h>
#include <string.h>

int main() {
    for (int i = 0; i < 5; i++) {

        // get user input date string
        char buffer[11];
        scanf("%10[^\n]", buffer);
        getchar();
        
        // splits input buffer by '/'
        int i = 0;
        char *p = strtok(buffer, "/");
        char *date[3];

        // stores tokens in array called date
        while (p != NULL) {
            date[i++] = p;
            p = strtok(NULL, "/");
        }

        // print array elements with predefined format
        printf("%s Month - %s day - %s year\n", date[0], date[1], date[2]);
    }
    return 0;
}