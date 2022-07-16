#include <stdio.h>

typedef enum {male, female, nonbinary} Gender;

typedef struct Person {
    Gender gender;
    int age;
    int height;
} Person;

int main() {
    Person myself = {nonbinary, 20, 181};
    printf("%d%d, %dcm\n", myself.gender, myself.age, myself.height);
    printf("sizeof Gender: %lu bytes\nsize of Person: %lu bytes\n", sizeof(Gender), sizeof(Person));
    return 0;
}