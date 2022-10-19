#include <stdio.h>
#include <stdlib.h>

#include "espl_lib.h"

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    int should_continue = 1;
    while (should_continue == 1) {
        printf("Please enter a number: ");
        int user_number = -1;
        if (scanf("%d", &user_number) == 1) {
            char* words = num_to_words(user_number);
            if (!words) {
                printf("Failed to convert your number, sorry\n");
                return -1;
            }
            printf("Your number in words: %s\n", words);
            free(words);
        }
        else {
            printf("The input was not a number!\n");
            clear_input();
        }
        printf("Please enter 1 to try again or anything else to exit: ");
        should_continue = 0;
        scanf("%d", &should_continue);
        clear_input();
    }
    return 0;
}
