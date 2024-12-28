#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int a, b, c;
    int result;

    printf("Enter three integers (a, b, c):\n");

    // Read inputs & validate
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Error: Invalid input. Please enter three integers.\n");
        return 1; // Exit with error
    }

    // Calculate d = a^3 + b^2 + c
    result = (a * a * a) + (b * b) + c;

    // Print!
    printf("The calculated value of d is: %d\n", result);

    return 0;
}

