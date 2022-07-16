#include <stdio.h>
#include <stdlib.h>

int n;
int josephus_simple(int people[], int skip);
int dead_people(int people[]);
int last_person_standing(int people[]);
void print_people(int people[]);  // Mainly for debug purposes, leaving here because it looks nice lol

int main() {
    int k;
    printf("How many people in circle: ");
    scanf("%d", &n);
    printf("Execute every n-th person: ");
    scanf("%d", &k);
    int *executees = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        executees[i] = i + 1;
    }
    print_people(executees);
    printf("Safe position: %d\n", josephus_simple(executees, k));
    free(executees);
    return 0;
}

int josephus_simple(int people[], int skip) {
    int idx = 0;
    do {
        // DEBUG:
        // print_people(people);
        int skipped = 0;
        printf("#%d killed\n", people[idx]);
        people[idx] = -1;
        while (skipped < skip) {
            if (idx == n - 1) {
                idx = 0;
            } else {
                idx++;
            }
            if (people[idx] != -1) {
                skipped++;
            }
        }
    } while (dead_people(people) <= n - 2);
    return last_person_standing(people);
}

int dead_people(int people[]) {
    int corpses = 0;
    for (int i = 0; i < n; i++) {
        if (people[i] == -1) {
            corpses++;
        }
    }
    return corpses;
}

int last_person_standing(int people[]) {
    int idx;
    for (idx = 0; idx < n; idx++) {
        if (people[idx] != -1) {
            break;
        }
    }
    return people[idx];
}

void print_people(int people[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", people[i]);
    }
    printf("\n");
}