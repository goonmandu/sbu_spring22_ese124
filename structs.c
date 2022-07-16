#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CPU {
    char manufacturer[50];
    char architecture[50];
    char lineup[50];
    char modelname[50];
    int p_cores;
    int e_cores;
    int threads;
    float maxfreq;
} CPU;

void print_specs(CPU cpu) {
    printf("%s %s %s %1.2fGHz (%dP + %dE = %dT) (%s)\n", cpu.manufacturer, cpu.lineup, cpu.modelname, cpu.maxfreq,
                                                         cpu.p_cores, cpu.e_cores, cpu.threads, cpu.architecture);
}

void print_ptr_specs(CPU *cpu) {
    printf("%s %s %s %1.2fGHz (%dP + %dE = %dT) (%s)\n", cpu->manufacturer, cpu->lineup, cpu->modelname, cpu->maxfreq,
                                                         cpu->p_cores, cpu->e_cores, cpu->threads, cpu->architecture);
}

int main() {
    // CPU cpu1 = {"Intel", "AMD64", "Core", "i5-12600K", 6, 4 , 20, 4.9};
    CPU cpu1;
    CPU cpu2 = {"AMD", "AMD64", "Ryzen", "5 5600X", 6, 0, 12, 4.6};
    CPU *cpu_p = (CPU *) malloc(sizeof(CPU));
    struct CPU *cpu_ptr = (CPU *) malloc(sizeof(struct CPU));
    strcpy(cpu_ptr->manufacturer, "AMD");
    strcpy(cpu_ptr->modelname, "Ryzen 7 5800X3D");
    cpu_ptr->p_cores = 8;
    cpu_ptr->e_cores = 0;
    cpu_ptr->threads = 16;
    cpu_ptr->maxfreq = 4.5;

    printf("%s %s (%dP + %dE = %dT, up to %1.1f)\n", cpu_ptr->manufacturer, cpu_ptr->modelname, cpu_ptr->p_cores, cpu_ptr->e_cores, cpu_ptr->threads, cpu_ptr->maxfreq);
    // strcpy(cpu_p->architecture, "AArch64");
    print_ptr_specs(cpu_p);
    print_specs(cpu2);
}