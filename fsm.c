// Understand by writing the state outputs.

#include <stdio.h>
#define STATE_A 0
#define STATE_B 1
#define STATE_C 2
#define STATE_D 3

/* Globals. Accessible by any function. */

int state_transition_table[][2] = {
    STATE_C, STATE_B,
    STATE_D, STATE_A,
    STATE_A, STATE_D,
    STATE_B, STATE_C
};

int output_table[][2] = {
    0, 0,
    1, 0,
    0, 1,
    0, 0
};


int main() {
    int current_state = STATE_D;
    int output = 0;
    int input;

    return 0;
}