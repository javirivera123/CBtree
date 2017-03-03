#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



int main() {

    char c;
    printf("Enter a character: ");

    // Reads character input from the user
    scanf("%c", &c);

    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c = %d", c, c);


    userSelection();
    return 0;
}
