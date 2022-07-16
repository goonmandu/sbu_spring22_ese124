#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Month {
    int month;
    float rent;
    float elec;
    float water;
    float cable;
    float heat;
    float total;
} Month;

void print_bills(Month *);
Month highest_total(Month *);
float *highest_item(Month *);
float monthly_average(Month *);
void sort_total_descending(Month *);
float *most_expensive_per_month(Month *);
void load_data(FILE *, Month *);
void print_month_ints(Month *);
void print_float_array(float *, int);
void fprint_bills(FILE *, Month *);

int main() {
    FILE *in, *out;
    if ((in = fopen("part1in", "r")) == NULL) {
        printf("Input file not found\n");
        return 1;
    }
    out = fopen("descending", "w");

    Month *bills = (Month *) malloc(12 * sizeof(Month));
    load_data(in, bills);
    printf("Highest total month is %d\n", highest_total(bills).month);
    printf("Average expense per month is %f\n", monthly_average(bills));
    printf("Highest item (0 = rent, 1 = elec, 2 = water, 3 = cable, 4 = heat): %d\n", highest_item(bills)[0]);
    sort_total_descending(bills);
    print_month_ints(bills);
    print_float_array(most_expensive_per_month(bills), 12);
    fprint_bills(out, bills);
    print_bills(bills);

    return 0;
}

void print_bills(Month *arr) {
    for (int i = 0; i < 12; i++) {
        printf("Month %d - R: %f E: %f W: %f C: %f H: %f\n", arr[i].month, arr[i].rent, arr[i].elec, arr[i].water, arr[i].cable, arr[i].heat);
    }
    printf("\n");
}

Month highest_total(Month *arr) {
    Month highest;
    for (int mo = 0; mo < 12; mo++) {
        if (arr[mo].total > highest.total) {
            highest = arr[mo];
        }
    }
    return highest;
}

float *highest_item(Month *arr) {
    float S_rent = 0, S_elec = 0, S_water = 0, S_cable = 0, S_heat = 0, highest, ret_arr[2];
    int item;
    for (int mo = 0; mo < 12; mo++) {
        S_rent += arr[mo].rent;
        S_elec += arr[mo].elec;
        S_water += arr[mo].water;
        S_cable += arr[mo].cable;
        S_heat += arr[mo].heat;
    }
    highest = S_rent;
    item = 0;
    if (S_elec > highest) {
        highest = S_elec;
        item = 1;
    }
    if (S_water > highest) {
        highest = S_water;
        item = 2;
    }
    if (S_cable > highest) {
        highest = S_cable;
        item = 3;
    }
    if (S_heat > highest) {
        highest = S_heat;
        item = 4;
    }
    ret_arr[0] = item;
    ret_arr[1] = highest;
    return ret_arr;
}

float monthly_average(Month *arr) {
    float monthly_total = 0;
    for (int mo = 0; mo < 12; mo++) {
        monthly_total += arr[mo].total;
    }
    return monthly_total / 12;
}

void sort_total_descending(Month *arr) {  // PVR
    int sorted = 0;
    while (sorted < 11) {
        sorted = 0;
        for (int i = 0; i < 11; i++) {
            if (arr[i].total < arr[i+1].total) {
                Month temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }
}

float *most_expensive_per_month(Month *arr) {
    float *mepm = (float *) malloc(12 * sizeof(float));  // DMA
    for (int mo = 0; mo < 12; mo++) {
        mepm[mo] = arr[mo].rent;
        if (arr[mo].elec > mepm[mo]) {
            mepm[mo] = arr[mo].elec;
        }
        if (arr[mo].water > mepm[mo]) {
            mepm[mo] = arr[mo].water;
        }
        if (arr[mo].cable > mepm[mo]) {
            mepm[mo] = arr[mo].cable;
        }
        if (arr[mo].heat > mepm[mo]) {
            mepm[mo] = arr[mo].heat;
        }
    }
    return mepm;
}

void load_data(FILE *fptr, Month *arr) {
    for (int mo = 0; mo < 12; mo++) {
        arr[mo].month = mo + 1;
    }
    for (int mo = 0; mo < 12; mo++) {
        fscanf(fptr, "%f", &arr[mo].rent);
    }
    for (int mo = 0; mo < 12; mo++) {
        fscanf(fptr, "%f", &arr[mo].elec);
    }
    for (int mo = 0; mo < 12; mo++) {
        fscanf(fptr, "%f", &arr[mo].water);
    }
    for (int mo = 0; mo < 12; mo++) {
        fscanf(fptr, "%f", &arr[mo].cable);
    }
    for (int mo = 0; mo < 12; mo++) {
        fscanf(fptr, "%f", &arr[mo].heat);
    }
    for (int mo = 0; mo < 12; mo++) {
        arr[mo].total = arr[mo].rent + arr[mo].elec + arr[mo].water + arr[mo].cable + arr[mo].heat;
    }
}

void print_month_ints(Month *arr) {
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i].month);
    }
    printf("\n");
}

void print_float_array(float *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void fprint_bills(FILE *fptr, Month *arr) {
    for (int i = 0; i < 12; i++) {
        fprintf(fptr, "Month %d - R: %f E: %f W: %f C: %f H: %f\n", arr[i].month, arr[i].rent, arr[i].elec, arr[i].water, arr[i].cable, arr[i].heat);
    }
    printf("\n");
}