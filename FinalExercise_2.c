#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, vowels = 0;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') spaces++;
        if (ch == 'a' || ch == 'A') a++;
        if (ch == 'e' || ch == 'E') e++;
        if (ch == 'i' || ch == 'I') i++;
        if (ch == 'o' || ch == 'O') o++;
        if (ch == 'u' || ch == 'U') u++;
    }

    vowels = a + e + i + o + u;
    printf("Spaces: %d\n", spaces);
    printf("Vowels: %d (a: %d, e: %d, i: %d, o: %d, u: %d)\n", vowels, a, e, i, o, u);

    return 0;
}

