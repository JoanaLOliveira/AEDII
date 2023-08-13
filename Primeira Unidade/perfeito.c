#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    printf("Numeros perfeitos entre 1 e 1000:\n");

    for (int num = 1; num <= 1000; num++) {
        if (isPerfect(num)) {
            printf("%d: 1", num);
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    printf(" + %d", i);
                }
            }

            printf("\n");
        }
    }

    return 0;
}