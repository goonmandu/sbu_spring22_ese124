#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int crs_index = 0;

typedef struct Course {
    char title[20];
    int credits;
    char instructor[15];
    int order;
} Course;

void title_atoz(Course *arr);
void order_ascending(Course *arr);
void print_course(Course c);
void print_all(Course *arr);

int main() {
    FILE *in;
    if ((in = fopen("courses", "r")) == NULL) {
        printf("Input file not found");
        return 1;
    }

    Course *courses = (Course *) malloc(sizeof(Course));
    
    while ((fscanf(in, "%s %d %s %d", courses[crs_index].title, &courses[crs_index].credits, courses[crs_index].instructor, &courses[crs_index].order)) != EOF) {
        crs_index++;
        courses = (Course *) realloc(courses, (crs_index + 1) * sizeof(Course));
    }

    title_atoz(courses);
    printf("Alphabetical Order of Courses:\n\n");
    print_all(courses);
    order_ascending(courses);
    printf("In ascending order of course order:\n\n");
    print_all(courses);

    free(courses);

    return 0;
}

void title_atoz(Course *arr) {
    int sorted = 0;
    while (sorted < crs_index - 1) {
        sorted = 0;
        for (int i = 0; i < crs_index - 1; i++) {
            if (strcmp(arr[i].title, arr[i+1].title) > 0) {
                Course temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }
}

void order_ascending(Course *arr) {
    int sorted = 0;
    while (sorted < crs_index - 1) {
        sorted = 0;
        for (int i = 0; i < crs_index - 1; i++) {
            if (arr[i].order > arr[i+1].order) {
                Course temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }
}

void print_course(Course c) {
    printf("Course Title: %s\nCredits: %d\nInstructor: %s\nOrder: %d\n\n", c.title, c.credits, c.instructor, c.order);
}

void print_all(Course *arr) {
    for (int i = 0; i < crs_index; i++) {
        print_course(arr[i]);
    }
}