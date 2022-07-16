#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Person {
    char *first_name;
    char *last_name;
    int zip;
    int age;
    float gpa;
} Person;

int entries;

void print_person(Person p);
void print_everyone(Person *arr);
void gpa_highlow(Person *arr);
void lastname_atoz(Person *arr);
void print_matching_zip(Person *arr, int zipcode);

int main() {
    FILE *in;
    if ((in = fopen("part4in", "r")) == NULL) {
        printf("Input file not found");
        return 1;
    }
    
    char *f;
    char *l;
    char *command = (char *) malloc(10 * sizeof(char));
    int z, a;
    float g;
    fscanf(in, "%d", &entries);
    Person *people = (Person *) malloc(entries * sizeof(Person));
    for (int i = 0; i < entries; i++) {
        f = (char *) malloc(30 * sizeof(char));
        l = (char *) malloc(30 * sizeof(char));
        fscanf(in, "%s %s %d %d %f", f, l, &z, &a, &g);
        people[i] = (Person) {f, l, z, a, g};
    }
    
    while (1) {
        printf("Enter a command (X to quit): ");
        gets(command);
        if (command[0] == 'x') {
            printf("Quitting.\n");
            return 0;
        }
        switch (tolower(command[0])) {
            case 'd':
                print_everyone(people);
                break;
            case 'o':
                gpa_highlow(people);
                print_everyone(people);
                break;
            case 'a':
                lastname_atoz(people);
                print_everyone(people);
                break;
            case 'z':
                if (strlen(command) != 7) {
                    printf("Enter a valid US 5-digit ZIP Code.\n");
                    break;
                }
                char entered_zip[6];
                strncpy(entered_zip, &command[2], 5);
                print_matching_zip(people, atoi(entered_zip));
                break;
            default:
                printf("Enter a valid command.\n");
        }
    }

    free(command);
    free(f);
    free(l);
    free(people);
    return 0;
}

void print_person(Person p) {
    printf("First Name: %s\nLast Name: %s\nZIP Code: %05d\nAge: %d\nGPA: %1.2f\n\n", p.first_name, p.last_name, p.zip, p.age, p.gpa);
}

void print_everyone(Person *arr) {
    for (int i = 0; i < entries; i++) {
        print_person(arr[i]);
    }
}

void gpa_highlow(Person *arr) {
    int sorted = 0;
    while (sorted < entries - 1) {
        sorted = 0;
        for (int i = 0; i < entries - 1; i++) {
            if (arr[i].gpa < arr[i+1].gpa) {
                Person temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }
}

void lastname_atoz(Person *arr) {
    int sorted = 0;
    while (sorted < entries - 1) {
        sorted = 0;
        for (int i = 0; i < entries - 1; i++) {
            if (strcmp(arr[i].last_name, arr[i+1].last_name) > 0) {
                Person temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }
}

void print_matching_zip(Person *arr, int zipcode) {
    for (int i = 0; i < entries; i++) {
        if (arr[i].zip == zipcode) {
            print_person(arr[i]);
        }
    }
}